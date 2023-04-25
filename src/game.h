//
// Created by Liplum on 4/23/2023.
//
#include "entity.h"

#ifndef GAME_H
#define GAME_H

typedef enum {
  BattleWin,
  BattleLoss,
  BattleEscape,
} BattleResult;

extern const float escapeChance;

typedef enum {
  Attack = 1,
  Parry = 2,
  Withdraw = 3,
} ActionType;

ActionType getActionChoice();

void displayHealthBar(Fighter *fighter);

void displayNewTurnBanner(Fighter &player, Fighter &enemy, int turn);

float calcDamage(int aLv, float aAttack, float aPower, float bArmor);

class BattleContext {
public:
  Player &player;
};

class GameLevel {
public:
  virtual void onEnter() const = 0;

  virtual BattleResult startBattle(const BattleContext &ctx) const = 0;
};

#endif //GAME_H
