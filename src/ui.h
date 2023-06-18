//
// Created by Liplum on 4/24/2023.
//

#include <string>
#include <vector>
#include "game.h"

#ifndef UI_H
#define UI_H
using namespace std;

namespace ui {
  void displayHealthBar(Fighter &fighter);

  void displayNewTurnBanner(Fighter &player, Fighter &enemy, int turn);

  string createHealthBar(float curHp, float maxHp, int barWidth);

  string createBoard(const vector<string> &lines);

  ActionType getActionChoice();
}
#endif //UI_H
