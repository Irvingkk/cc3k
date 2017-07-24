#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

using namespace std;

class Character {
protected:
	int maxHp=0;
	int hp=0;
	int atk=0;
	int def=0;
    int gold=0; // conecret
	string type="unnamed";
    bool enemy;
public:
	Character();
	Character(int hp, int atk, int def, bool enemy);
	virtual string attack(Character *ec) = 0;
	string getType() const;
	int getHp() const;
	void setHp(int hp);
	int getMaxHp() const;
	int getAtk() const;
	int setAtk(int atk);
	int getDef() const;
	int setDef(int def);
    void addGold(int gold); // add gold to pc/ec
    int getGold() const; // get the amount of gold
    bool isEnemy();
    virtual void reset(); // reset potion of player
    virtual void trollAddHp(); // add 5 hp to troll
	virtual ~Character();
};


#endif
