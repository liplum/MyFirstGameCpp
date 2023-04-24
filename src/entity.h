//
// Created by Liplum on 4/23/2023.
//
#ifndef ENTITY_H
#define ENTITY_H

#include <malloc.h>
#include <string>
#include <utility>

class Fighter;

class FighterType {
public:
  virtual std::string getName() = 0;

  virtual float getMaxHp() = 0;

  virtual float getAttack() = 0;

  virtual float getArmor() = 0;

  virtual int getLevel() = 0;

  Fighter *create();
};


class Player : public FighterType {
public:
  std::string name;
  float maxHp;
  float attack;
  float armor;
  int level;
  int exp = 0;
public:
  std::string getName() override {
    return name;
  }

  float getMaxHp() override {
    return maxHp;
  }

  float getAttack() override {
    return attack;
  }

  float getArmor() override {
    return armor;
  }

  int getLevel() override {
    return level;
  }
};

class Enemy : public FighterType {
public:
  std::string name;
  float maxHp;
  float attack;
  float armor;
  int level;
  int expReward;
public:
  std::string getName() override {
    return name;
  }

  float getMaxHp() override {
    return maxHp;
  }

  float getAttack() override {
    return attack;
  }

  float getArmor() override {
    return armor;
  }

  int getLevel() override {
    return level;
  }
};

class Fighter {
public:
  FighterType &type;
  float curHp;
  float attack;
  float armor;
  /**
   * Who has greater speed can move first.
   * If the speed is the same, one random player will be the first player.
   */
  float speed;
  float attackPower;
  float defenseResistance;

  float getAttackDamageTo(Fighter b, float powerMul = 1.0f);
};

#endif