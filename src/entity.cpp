//
// Created by Liplum on 4/23/2023.
//

#include "entity.h"

Fighter *FighterInfo::create() {
  return new Fighter{
    .name = this->name,
    .info= this,
    .curHp = this->maxHp,
    .attack = this->attack,
    .armor = this->armor,
  };
}