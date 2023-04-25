//
// Created by Liplum on 4/23/2023.
//

#include "entity.h"
#include "game.h"

Fighter *FighterType::create() {
  return new Fighter{
    .type= *this,
    .curHp = this->getMaxHp(),
    .attack = this->getAttack(),
    .armor = this->getArmor(),
    .attackPower = 100,
    .defenseResistance = 0.5f,
  };
}

float Fighter::getAttackDamageTo(Fighter b, float powerMul) {
  return calcDamage(this->type.getLevel(), this->attack, this->attackPower * powerMul, b.armor);
}
