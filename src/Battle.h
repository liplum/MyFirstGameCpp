//
// Created by Liplum on 4/30/2023.
//

#ifndef BATTLE_H
#define BATTLE_H


#include "entity.h"

struct BattleResult {
  int turnPassed;
};

enum BattleState {
  Running, End,
};

class Battle {
private:
  Fighter* player;
  Fighter *enemy;
  int turn = 0;
public:
  /**
   * Step the turn to the next.
   * @return
   */
  BattleState stepTurn();

  BattleResult settle();
};

Battle* createBattle(Player &player, Enemy &enemy);


#endif //BATTLE_H
