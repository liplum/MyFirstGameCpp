//
// Created by Liplum on 4/24/2023.
//
#include "../game.h"

#ifndef LEVEL_1_H
#define LEVEL_1_H

class SlimeLevel : public GameLevel {
public:
  void onEnter() const override;
  BattleResult startBattle(const BattleContext& ctx) const override;
};

#endif //LEVEL_1_H
