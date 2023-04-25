#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "console.h"
#include "level/level_1.h"
#include "vector"

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
  printf("\t\t**********************\n");
  printf("\t\t* First Game v1.5.0  *\n");
  printf("\t\t**********************\n");
  printf("\t\t\t\tLast Change: 4/24/2023    by Liplum\n");

  auto levels = vector{
    SlimeLevel()
  };
  cout << "You were found in a forest.";
  getchar();
  printf("A slime is coming here...");
  alert();
  getchar();
  printf("Start fighting!");
  auto player = *createPlayer();
  for (const auto &level: levels) {
    BattleResult result = level.startBattle(BattleContext{.player = player});
    switch (result) {
      case BattleWin: {
        printf("Press Enter to continue...");
        getchar();
        getchar();
        continue;
      }
      case BattleEscape: {
        getchar();
        printf("*----*------*------*------*------*-------*\n");
        printf("|       You Escaped from the Forest      |\n");
        printf("|         That's the right way.          |\n");
        printf("*-----*------*------*------*------*------*\n");
        return 0;
      }
      case BattleLoss: {
        getchar();
        printf("*----*------*------*------*------*-------*\n");
        printf("|             Game Over                  |\n");
        printf("|       Don't be sad, just try again.    |\n");
        printf("*-----*------*------*------*------*------*\n");
        return 0;
      }
    }
  }

  printf("*----*------*------*------*------*------*------*------*------*------*\n");
  printf("|              Congratulations! you passed the game.                |\n");
  printf("|       Thank you for playing, please wait for my next work! UwU    |\n");
  printf("*-----*------*------*------*------*------*------*------*------*-----*");
  return 0;
}

#pragma clang diagnostic pop
