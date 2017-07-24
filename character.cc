#include "character.h"

Character::Character() {}

Character::Character(int hp, int atk, int def, bool enemy) : maxHp(hp), hp(hp), atk(atk), def(def), enemy(enemy) {}


string Character::getType() const {
	return type; 
}
int Character::getHp() const {
	return hp;
}
void Character::setHp(int hp) {
	this->hp = hp;
}
int Character::getMaxHp() const {
	return maxHp;
}
int Character::getAtk() const {
	return atk;
}
int Character::setAtk(int atk) {
	return this->atk = atk;
}
int Character::getDef() const {
	return def;
}
int Character::setDef(int def) {
	return this->def = def;
}
void Character::addGold(int gold) {
    this->gold += gold;
}
int Character::getGold() const{
    return gold;
}

bool Character::isEnemy(){
    return enemy;
}

void Character::reset(){}

void Character::trollAddHp(){}

Character::~Character(){}

