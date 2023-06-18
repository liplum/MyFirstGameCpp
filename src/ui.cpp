//
// Created by Liplum on 4/24/2023.
//

#include "ui.h"
#include "console.h"
#include <string>
#include <iostream>

using namespace std;

namespace ui {

  const int healthBarWidth = 15;

  void displayHealthBar(Fighter &fighter) {
    cout << fighter.type.getName() << " HP:" << endl;
    cout << "\t|" << ui::createHealthBar(fighter.curHp, fighter.type.getMaxHp(), healthBarWidth) << "| "
         << static_cast<int>(fighter.curHp) << endl;
  }

  void displayNewTurnBanner(Fighter &player, Fighter &enemy, int turn) {
    clearScreen();
    printf("------------------------------------------------------------\n");
    cout << "[Turn " << turn << "]" << endl;
    displayHealthBar(player);
    displayHealthBar(enemy);
  }

  ActionType getActionChoice() {
    int choice = 0;
    cout << "Attack=1, Parry=2, Withdraw=3" << endl;
    while (choice != Attack && choice != Parry && choice != Withdraw) {
      cout << "Your choice:";
      cin >> choice;
    }
    return static_cast<ActionType>(choice);
  }

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

  string createBoard(const vector<string> &lines) {
    // Find the length of the longest line
    size_t maxLength = 0;
    for (const auto &line: lines) {
      maxLength = max(maxLength, line.length());
    }

    // Build the top and bottom borders of the box
    string border = string(maxLength + 4, '*');

    // Build the contents of the box
    string contents;
    for (const auto &line: lines) {
      // Calculate the padding for this line
      size_t paddingSize = maxLength - line.length();
      string leftPadding = string(paddingSize / 2, ' ');
      string rightPadding = string(paddingSize - leftPadding.length(), ' ');

      // Build the centered line with padding and borders
      string borderedLine = "* ";
      borderedLine += leftPadding;
      borderedLine += line;
      borderedLine += rightPadding;
      borderedLine += " *";

      // Add the line to the contents
      contents += borderedLine + "\n";
    }

    // Combine the borders and contents into the final box
    return border + "\n" + contents + "\n" + border;
  }
}