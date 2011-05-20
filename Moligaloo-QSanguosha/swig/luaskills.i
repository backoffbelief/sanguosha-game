
class LuaTriggerSkill: public TriggerSkill{
public:
    LuaTriggerSkill(const char *name, Frequency frequency);
    void addEvent(TriggerEvent event);
	
	virtual bool triggerable(ServerPlayer *target) const;
    virtual bool trigger(TriggerEvent event, ServerPlayer *player, QVariant &data) const;

    LuaFunction on_trigger;
    LuaFunction can_trigger;
};

class ViewAsSkill:public Skill{
public:
    ViewAsSkill(const QString &name);

    virtual bool viewFilter(const QList<CardItem *> &selected, const CardItem *to_select) const = 0;
    virtual const Card *viewAs(const QList<CardItem *> &cards) const = 0;

    bool isAvailable() const;
};

class LuaViewAsSkill: public ViewAsSkill{
public:
    LuaViewAsSkill(const char *name);

    virtual bool viewFilter(const QList<CardItem *> &selected, const CardItem *to_select) const;
    virtual const Card *viewAs(const QList<CardItem *> &cards) const;

    LuaFunction view_filter;
    LuaFunction view_as;

    LuaFunction enabled_at_play;
    LuaFunction enabled_at_response;
};

class LuaSkillCard: public SkillCard{
public:
    LuaSkillCard(const char *name);
    void setTargetFixed(bool target_fixed);
    void setWillThrow(bool will_throw);

    LuaFunction available;
    LuaFunction filter;    
    LuaFunction feasible;
    LuaFunction on_use;
    LuaFunction on_effect;
};

%{

#include "lua-wrapper.h"
#include "clientplayer.h"
#include "carditem.h"

bool LuaTriggerSkill::triggerable(ServerPlayer *target) const{
	if(can_trigger == 0)
		return TriggerSkill::triggerable(target);
	
	Room *room = target->getRoom();
	lua_State *L = room->getLuaState();
	
	// the callback function
	lua_rawgeti(L, LUA_REGISTRYINDEX, can_trigger);	
	
	LuaTriggerSkill *self = const_cast<LuaTriggerSkill *>(this);
	SWIG_NewPointerObj(L, self, SWIGTYPE_p_LuaTriggerSkill, 0);
	
	SWIG_NewPointerObj(L, target, SWIGTYPE_p_ServerPlayer, 0);

	int error = lua_pcall(L, 2, 1, 0);
	if(error){
		const char *error_msg = lua_tostring(L, -1);
		lua_pop(L, 1);
		room->output(error_msg);
		return false;
	}else{
		bool result = lua_toboolean(L, -1);
		lua_pop(L, 1);
		return result;
	}
}

bool LuaTriggerSkill::trigger(TriggerEvent event, ServerPlayer *player, QVariant &data) const{
	if(on_trigger == 0)
		return false;
		
	Room *room = player->getRoom();
	lua_State *L = room->getLuaState();
	
	int e = static_cast<int>(event);
	
	// the callback
	lua_rawgeti(L, LUA_REGISTRYINDEX, on_trigger);	
	
	LuaTriggerSkill *self = const_cast<LuaTriggerSkill *>(this);
	SWIG_NewPointerObj(L, self, SWIGTYPE_p_LuaTriggerSkill, 0);

	// the first argument: event
	lua_pushinteger(L, e);	
	
	// the second argument: player
	SWIG_NewPointerObj(L, player, SWIGTYPE_p_ServerPlayer, 0);

	// the last event: data
	SWIG_NewPointerObj(L, &data, SWIGTYPE_p_QVariant, 0);
	
	int error = lua_pcall(L, 4, 1, 0);
	if(error){
		const char *error_msg = lua_tostring(L, -1);
		lua_pop(L, 1);
		room->output(error_msg);
		return false;
	}else{
		bool result = lua_toboolean(L, -1);
		lua_pop(L, 1);
		return result;
	}
}

#include <QMessageBox>

static void Error(lua_State *L){
    const char *error_string = lua_tostring(L, -1);
    lua_pop(L, 1);
    QMessageBox::warning(NULL, "Lua script error!", error_string);
}

// ----------------------

void LuaViewAsSkill::pushSelf(lua_State *L) const{
    LuaViewAsSkill *self = const_cast<LuaViewAsSkill *>(this);
    SWIG_NewPointerObj(L, self, SWIGTYPE_p_LuaViewAsSkill, 0);
}

bool LuaViewAsSkill::viewFilter(const QList<CardItem *> &selected, const CardItem *to_select) const{
    if(view_filter == 0)
        return false;

    lua_State *L = Sanguosha->getLuaState();

    lua_rawgeti(L, LUA_REGISTRYINDEX, view_filter);

    pushSelf(L);

    lua_createtable(L, selected.length(), 0);
    int i;
    for(i=0; i<selected.length(); i++){
        const Card *card = selected.at(i)->getFilteredCard();
        SWIG_NewPointerObj(L, card, SWIGTYPE_p_Card, 0);
        lua_rawseti(L, -2, i+1);
    }

    const Card *card = to_select->getFilteredCard();
    SWIG_NewPointerObj(L, card, SWIGTYPE_p_Card, 0);

    int error = lua_pcall(L, 3, 1, 0);
    if(error){
        Error(L);
        return false;
    }else{
        bool result = lua_toboolean(L, -1);
        lua_pop(L, 1);
        return result;
    }
}

const Card *LuaViewAsSkill::viewAs(const QList<CardItem *> &cards) const{
    if(view_as == 0)
        return NULL;

    lua_State *L = Sanguosha->getLuaState();

    lua_rawgeti(L, LUA_REGISTRYINDEX, view_as);

    pushSelf(L);

    lua_createtable(L, cards.length(), 0);
    int i;
    for(i=0; i<cards.length(); i++){
        const Card *card = cards.at(i)->getFilteredCard();
        SWIG_NewPointerObj(L, card, SWIGTYPE_p_Card, 0);
        lua_rawseti(L, -2, i+1);
    }

    int error = lua_pcall(L, 2, 1, 0);
    if(error){
        Error(L);
        return NULL;
    }

    void *card_ptr;
    int result = SWIG_ConvertPtr(L, -1, &card_ptr, SWIGTYPE_p_Card, 0);
    lua_pop(L, 1);
    if(SWIG_IsOK(result)){
		const Card *card = static_cast<const Card *>(card_ptr);
        return card;
    }else
        return NULL;
}

bool LuaViewAsSkill::isEnabledAtPlay() const{
    if(enabled_at_play == 0)
        return ViewAsSkill::isEnabledAtPlay();

    lua_State *L = Sanguosha->getLuaState();

    // the callback
    lua_rawgeti(L, LUA_REGISTRYINDEX, enabled_at_play);

    pushSelf(L);

    int error = lua_pcall(L, 1, 1, 0);
    if(error){
        Error(L);
        return false;
    }else{
        bool result = lua_toboolean(L, -1);
        lua_pop(L, 1);
        return result;
    }
}

bool LuaViewAsSkill::isEnabledAtResponse() const{
    if(enabled_at_response == 0)
        return ViewAsSkill::isEnabledAtResponse();

    lua_State *L = Sanguosha->getLuaState();

    // the callback
    lua_rawgeti(L, LUA_REGISTRYINDEX, enabled_at_response);

    pushSelf(L);

    int error = lua_pcall(L, 1, 1, 0);
    if(error){
        Error(L);
        return false;
    }else{
        bool result = lua_toboolean(L, -1);
        lua_pop(L, 1);
        return result;
    }
}

// ---------------------

void LuaSkillCard::pushSelf(lua_State *L) const{
    LuaSkillCard *self = const_cast<LuaSkillCard *>(this);
    SWIG_NewPointerObj(L, self, SWIGTYPE_p_LuaSkillCard, 0);
}

bool LuaSkillCard::isAvailable() const{
    if(available == 0)
        return SkillCard::isAvailable();

    lua_State *L = Sanguosha->getLuaState();
	
	// the callback
	lua_rawgeti(L, LUA_REGISTRYINDEX, available);	

    pushSelf(L);

    int error = lua_pcall(L, 1, 1, 0);
    if(error){
        Error(L);
        return false;
    }else{
		bool result = lua_toboolean(L, -1);
		lua_pop(L, 1);
		return result;
	}
}

bool LuaSkillCard::targetFilter(const QList<const ClientPlayer *> &targets, const ClientPlayer *to_select) const{
    if(filter == 0)
        return SkillCard::targetFilter(targets, to_select);

    lua_State *L = Sanguosha->getLuaState();
	
	// the callback
	lua_rawgeti(L, LUA_REGISTRYINDEX, filter);	

    pushSelf(L);

    lua_createtable(L, targets.length(), 0);
    int i;
    for(i=0; i<targets.length(); i++){
        SWIG_NewPointerObj(L, targets.at(i), SWIGTYPE_p_ClientPlayer, 0);
        lua_rawseti(L, -2, i+1);
    }

    SWIG_NewPointerObj(L, to_select, SWIGTYPE_p_ClientPlayer, 0);

    int error = lua_pcall(L, 3, 1, 0);
    if(error){
        Error(L);
        return false;
    }else{
		bool result = lua_toboolean(L, -1);
		lua_pop(L, 1);
		return result;
	}
}

bool LuaSkillCard::targetsFeasible(const QList<const ClientPlayer *> &targets) const{
    if(feasible == 0)
        return SkillCard::targetsFeasible(targets);

    lua_State *L = Sanguosha->getLuaState();
	
	// the callback
	lua_rawgeti(L, LUA_REGISTRYINDEX, feasible);	

    pushSelf(L);

    lua_createtable(L, targets.length(), 0);
    int i;
    for(i=0; i<targets.length(); i++){
        SWIG_NewPointerObj(L, targets.at(i), SWIGTYPE_p_ClientPlayer, 0);
        lua_rawseti(L, -2, i+1);
    }

    int error = lua_pcall(L, 2, 1, 0);
    if(error){
        Error(L);
        return false;
    }else{
		bool result = lua_toboolean(L, -1);
		lua_pop(L, 1);
		return result;
	}
}

void LuaSkillCard::use(Room *room, ServerPlayer *source, const QList<ServerPlayer *> &targets) const{
    if(on_use == 0)
        return SkillCard::use(room, source, targets);

    lua_State *L = Sanguosha->getLuaState();
	
	// the callback
	lua_rawgeti(L, LUA_REGISTRYINDEX, on_use);

    pushSelf(L);

    SWIG_NewPointerObj(L, room, SWIGTYPE_p_Room, 0);

    SWIG_NewPointerObj(L, source, SWIGTYPE_p_ServerPlayer, 0);

    lua_createtable(L, targets.length(), 0);
    int i;
    for(i=0; i<targets.length(); i++){
        SWIG_NewPointerObj(L, targets.at(i), SWIGTYPE_p_ServerPlayer, 0);
        lua_rawseti(L, -2, i+1);
    }

    int error = lua_pcall(L, 4, 0, 0);
    if(error){
        const char *error_msg = lua_tostring(L, -1);
        lua_pop(L, 1);
        room->output(error_msg);
    }
}

void LuaSkillCard::onEffect(const CardEffectStruct &effect) const{
    if(on_effect == 0)
        return SkillCard::onEffect(effect);

    lua_State *L = Sanguosha->getLuaState();
	
	// the callback
	lua_rawgeti(L, LUA_REGISTRYINDEX, on_effect);

    pushSelf(L);

    SWIG_NewPointerObj(L, &effect, SWIGTYPE_p_CardEffectStruct, 0);

    int error = lua_pcall(L, 2, 0, 0);
    if(error){
        const char *error_msg = lua_tostring(L, -1);
        lua_pop(L, 1);
		Room *room = effect.to->getRoom();
        room->output(error_msg);
    }
}



%}
