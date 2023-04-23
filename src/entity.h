//
// Created by Liplum on 4/23/2023.
//
#ifndef ENTITY_H
#define ENTITY_H

#include <malloc.h>
#include <string>

using namespace std;

class Fighter;

class FighterInfo {
public:
  const string name;
  float maxHp;
  float attack;
  float armor;
  int level;
  Fighter *create();
};


class Player : FighterInfo {
public:
  int exp;
};

class Enemy : FighterInfo {
public:
  int expReward;
};

class Fighter {
public:
  const string name;
  FighterInfo* info;
  float curHp;
  float attack;
  float armor;
};


typedef struct {
  float hp;
  float damage;
  float armor;
} Upgrade;

#endif