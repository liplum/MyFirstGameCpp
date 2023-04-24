//
// Created by Liplum on 4/23/2023.
//

#include "entity.h"

Fighter *FighterType::create() {
  return new Fighter{
    .name = this->name,
    .type= this,
    .curHp = this->maxHp,
    .attack = this->attack,
    .armor = this->armor,
  };
}