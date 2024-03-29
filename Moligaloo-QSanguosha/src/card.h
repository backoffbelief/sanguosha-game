#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QMap>
#include <QIcon>

class Room;
class ServerPlayer;
class Client;
class ClientPlayer;
class CardItem;

struct CardEffectStruct;
struct CardMoveStruct;
struct CardUseStruct;

//牌类的基类！
class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString suit READ getSuitString CONSTANT)
    Q_PROPERTY(bool red READ isRed STORED false CONSTANT)
    Q_PROPERTY(bool black READ isBlack STORED false CONSTANT)
    Q_PROPERTY(int id READ getId CONSTANT)
    Q_PROPERTY(int number READ getNumber WRITE setNumber)
    Q_PROPERTY(QString number_string READ getNumberString CONSTANT)
    Q_PROPERTY(QString type READ getType CONSTANT)
    Q_PROPERTY(QString pixmap_path READ getPixmapPath)
    Q_PROPERTY(bool target_fixed READ targetFixed)
    Q_PROPERTY(bool once READ isOnce CONSTANT)
    Q_PROPERTY(bool mute READ isMute CONSTANT)
    Q_PROPERTY(bool equipped READ isEquipped)

    Q_ENUMS(Suit)
    Q_ENUMS(CardType)

public:
    // enumeration type
    enum Suit {Spade, Club, Heart, Diamond, NoSuit};
    static const Suit AllSuits[4];

    // card types
    //牌得类型
    //技能，基础，陷阱，装备
    enum CardType{
        Skill,
        Basic,
        Trick,
        Equip,
    };

    // constructor
    Card(Suit suit, int number, bool target_fixed = false);

    // property getters/setters
    QString getSuitString() const;
    bool isRed() const;
    bool isBlack() const;
    int getId() const;
    void setId(int id);
    int getEffectiveId() const;
    QString getEffectIdString() const;

    int getNumber() const;
    void setNumber(int number);
    QString getNumberString() const;

    Suit getSuit() const;
    void setSuit(Suit suit);

    bool sameColorWith(const Card *other) const;
    bool isEquipped() const;

    QString getPixmapPath() const;
    QString getIconPath() const;
    QString getPackage() const;    
    QIcon getSuitIcon() const;
    QString getFullName(bool include_suit = false) const;
    QString getLogName() const;
    QString getName() const;
    QString getSkillName() const;   
    void setSkillName(const QString &skill_name);
    QString getDescription() const;
    QString getEffectPath() const;

    bool isVirtualCard() const;
    virtual bool match(const QString &pattern) const;

    void addSubcard(int card_id);
    void addSubcard(const Card *card);
    QList<int> getSubcards() const;
    void clearSubcards();
    QString subcardString() const;
    void addSubcards(const QList<CardItem *> &card_items);
    int subcardsLength() const;

    virtual QString getType() const = 0;
    virtual QString getSubtype() const = 0;
    virtual CardType getTypeId() const = 0;
    virtual QString toString() const;
    virtual QString getEffectPath(bool is_male) const;
    bool isNDTrick() const;

    // card target selection
    virtual bool targetFixed() const;
    virtual bool targetsFeasible(const QList<const ClientPlayer *> &targets) const;
    virtual bool targetFilter(const QList<const ClientPlayer *> &targets, const ClientPlayer *to_select) const;
    virtual bool isAvailable() const;

    bool isOnce() const;
    bool isMute() const;
    bool willThrow() const;

    virtual void onUse(Room *room, const CardUseStruct &card_use) const;
    virtual void use(Room *room, ServerPlayer *source,  const QList<ServerPlayer *> &targets) const;
    virtual void onEffect(const CardEffectStruct &effect) const;
    virtual bool isCancelable(const CardEffectStruct &effect) const;

    virtual void onMove(const CardMoveStruct &move) const;

    // static functions
    static bool CompareByColor(const Card *a, const Card *b);
    static bool CompareBySuitNumber(const Card *a, const Card *b);
    static bool CompareByType(const Card *a, const Card *b);
    static const Card *Parse(const QString &str);
    static Card * Clone(const Card *card);
    static QString Suit2String(Suit suit);
    static QStringList IdsToStrings(const QList<int> &ids);
    static QList<int> StringsToIds(const QStringList &strings);

protected:
    QList<int> subcards;
    bool target_fixed;
    bool once;
    QString skill_name;
    bool mute;
    bool will_throw;

private:
    Suit suit;
    int number;
    int id;    
};

//---------------------------------------------------------------------------------
//技能牌！！！
//
class SkillCard: public Card{
    Q_OBJECT

public:
    SkillCard();
    void setUserString(const QString &user_string);

    virtual QString getSubtype() const;    
    virtual QString getType() const;
    virtual CardType getTypeId() const;
    virtual QString toString() const;    

protected:
    QString user_string;
};

class DummyCard: public SkillCard{
    Q_OBJECT

public:
    DummyCard();

    virtual QString getSubtype() const;
    virtual QString getType() const;
    virtual QString toString() const;
};

#endif // CARD_H
