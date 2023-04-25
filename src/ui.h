//
// Created by Liplum on 4/24/2023.
//

#include <string>
#include <vector>

#ifndef UI_H
#define UI_H
using namespace std;

namespace ui {
  string createHealthBar(float curHp, float maxHp, int barWidth);

  string createBoard(const vector<string> &lines);
}
#endif //UI_H
