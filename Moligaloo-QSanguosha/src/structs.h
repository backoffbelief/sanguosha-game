#ifndef STRUCTS_H
#define STRUCTS_H

class Room;
class TriggerSkill;
class ServerPlayer;
class Card;
class Slash;
class GameRule;

#include "player.h"

#include <QVariant>

struct DamageStruct{
    DamageStruct();

    enum Nature{
        Normal, // normal slash, duel and most damage caused by skill
        Fire,  // fire slash, fire attack and few damage skill (Yeyan, etc)
        Thunder // lightning, thunder slash, and few damage skill (Leiji, etc)
    };

    ServerPlayer *from;
    ServerPlayer *to;
    const Card *card;
    int damage;
    Nature nature;
    bool chain;
};

struct CardEffectStruct{
    CardEffectStruct();

    const Card *card;

    ServerPlayer *from;
    ServerPlayer *to;

    bool multiple;
};

struct SlashEffectStruct{
    SlashEffectStruct();

    const Slash *slash;

    ServerPlayer *from;
    ServerPlayer *to;

    bool drank;

    DamageStruct::Nature nature;
};

struct CardUseStruct{
    CardUseStruct();
    bool isValid() const;
    void parse(const QString &str, Room *room);

    const Card *card;
    ServerPlayer *from;
    QList<ServerPlayer *> to;
};

struct CardMoveStruct{
    int card_id;
    Player::Place from_place, to_place;
    ServerPlayer *from, *to;
    bool open;

    QString toString() const;
};

struct DyingStruct{
    DyingStruct();

    ServerPlayer *who; // who is ask for help
    DamageStruct *damage; // if it is NULL that means the dying is caused by losing hp
};

struct RecoverStruct{
    RecoverStruct();

    int recover;
    ServerPlayer *who;
    const Card *card;
};

struct JudgeStruct{
    JudgeStruct();
    bool isGood(const Card *card = NULL) const;
    bool isBad() const;

    ServerPlayer *who;
    const Card *card;
    QRegExp pattern;
    bool good;
    QString reason;
};


//
//游戏中可以触发的事件的集合
//
enum TriggerEvent{
    GameStart,//游戏开始
    TurnStart,
    PhaseChange,
    DrawNCards,
    HpRecover,//HP恢复

    StartJudge,
    AskForRetrial,
    FinishJudge,

    //伤害相关，伤害前，伤害，伤害完成，这个牵扯到判定之类的吧
    Predamage,
    Predamaged,
    DamageDone,
    Damage,
    Damaged,
    DamageComplete,

    //死亡相关
    Dying,
    AskForPeaches,
    AskForPeachesDone,
    Death,
    GameOverJudge,

    SlashEffect,
    SlashEffected,
    SlashProceed,
    SlashHit,
    SlashMissed,

    //卡牌相关，要卡，使用卡，弃牌，失去牌（什么时候失去啊。。）
    CardAsked,
    CardUsed,
    CardResponsed,
    CardDiscarded,
    CardLost,

    CardEffect,
    CardEffected,
    CardFinished
};

typedef const Card *CardStar;
typedef ServerPlayer *PlayerStar;
typedef JudgeStruct *JudgeStar;
typedef DamageStruct *DamageStar;

Q_DECLARE_METATYPE(DamageStruct);
Q_DECLARE_METATYPE(CardEffectStruct);
Q_DECLARE_METATYPE(SlashEffectStruct);
Q_DECLARE_METATYPE(CardUseStruct);
Q_DECLARE_METATYPE(CardMoveStruct);
Q_DECLARE_METATYPE(CardStar);
Q_DECLARE_METATYPE(PlayerStar);
Q_DECLARE_METATYPE(DyingStruct);
Q_DECLARE_METATYPE(RecoverStruct);
Q_DECLARE_METATYPE(JudgeStar);
Q_DECLARE_METATYPE(DamageStar);

#endif // STRUCTS_H
