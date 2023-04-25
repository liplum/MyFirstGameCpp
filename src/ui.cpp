//
// Created by Liplum on 4/24/2023.
//

#include "ui.h"
#include <string>

using namespace std;

namespace ui {

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
    for (const auto& line : lines) {
      maxLength = max(maxLength, line.length());
    }

    // Build the top and bottom borders of the box
    string border = string(maxLength + 4, '*');

    // Build the contents of the box
    string contents;
    for (const auto& line : lines) {
      // Calculate the padding for this line
      size_t paddingSize = maxLength - line.length();
      string leftPadding = string(paddingSize / 2, ' ');
      string rightPadding = string(paddingSize - leftPadding.length(), ' ');

      // Build the centered line with padding and borders
      string borderedLine = "* " + leftPadding + line + rightPadding + " *";

      // Add the line to the contents
      contents += borderedLine + "\n";
    }

    // Combine the borders and contents into the final box
    return border + "\n" + contents + "\n" + border;
  }
}