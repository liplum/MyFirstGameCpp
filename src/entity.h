//
// Created by Liplum on 4/23/2023.
//
#ifndef ENTITY_H
#define ENTITY_H

#include <malloc.h>
#include <string>

class Fighter;

class FighterType {
public:
  const std::string name;
  float maxHp;
  float attack;
  float armor;
  int level;

  Fighter *create();
};


class Player : public FighterType {
public:
  int exp;
};

class Enemy : public FighterType {
public:
  int expReward;
};

class Fighter {
public:
  const std::string name;
  FighterType *type;
  float curHp;
  float attack;
  float armor;
};

#endif