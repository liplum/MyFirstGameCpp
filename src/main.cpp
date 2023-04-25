#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <cstdio>
#include <iostream>
#include "game.h"
#include "console.h"
#include "level/level_1.h"
#include "vector"
#include "ui.h"

using namespace std;

Player *createPlayer() {
  auto p = new Player;
  p->name = "You";
  p->maxHp = 130.0f;
  p->attack = 10.0f;
  p->armor = 4.0f;
  p->level = 1;
  return p;
}

int main() {
#ifdef _WIN32
  setvbuf(stdout, nullptr, _IONBF, 0);
#endif
  srand((unsigned) time(nullptr));
  clearScreen();
  cout << ui::createBoard(vector<string>{
    "My First Game Cpp v0.0.1",
    "Last Change: 4/25/2023    by Liplum",
  }) << endl;

  auto levels = vector{
    SlimeLevel()
  };
  cout << "You were found in a forest." << endl;
  auto player = *createPlayer();
  for (const auto &level: levels) {
    level.onEnter();
    cout << "Start fighting!" << endl;
    getchar();
    auto result = level.startBattle(BattleContext{.player = player});
    switch (result) {
      case BattleWin: {
        cout << "Press Enter to continue...";
        getchar();
        getchar();
        continue;
      }
      case BattleEscape: {
        getchar();
        cout << ui::createBoard(vector<string>{
          "You Escaped from the Forest",
          "That's the right way.",
        });
        return 0;
      }
      case BattleLoss: {
        getchar();
        cout << ui::createBoard(vector<string>{
          "Game Over",
          "Don't be sad, just try again.",
        }) << endl;
        return 0;
      }
    }
  }

  cout << ui::createBoard(vector<string>{
    "Congratulations! you passed the game.",
    "Thank you for playing, please wait for my next work! UwU",
  }) << endl;
  return 0;
}

#pragma clang diagnostic pop
