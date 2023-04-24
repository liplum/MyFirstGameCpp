//
// Created by Liplum on 4/24/2023.
//

#include "ui.h"
#include <string>

using namespace std;

// Create a health bar string based on the current and maximum health points
string createHealthBar(float curHp, float maxHp, int barWidth) {
  // Calculate the percentage of remaining health points
  float percent = curHp / maxHp;

  // Calculate the number of characters to fill in the bar
  int numFilledChars = static_cast<int>(percent * static_cast<float>(barWidth));
  numFilledChars = max(numFilledChars, 1);

  // Fill the health bar string with spaces
  string healthBar(barWidth, ' ');

  // Fill in the filled characters with '='
  fill_n(healthBar.begin(), numFilledChars - 1, '=');
  healthBar[numFilledChars - 1] = '>';

  return healthBar;
}
