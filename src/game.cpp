#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <stdio.h>
#include "console.h"
#include "entity.h"

//
// Created by Liplum on 4/23/2023.
//
int getChoice() {
  int choice;
  printf("Attack=1, Parry=2, Withdraw=3\n");
  printf("Your choice:");
  scanf("%d", &choice);
  return choice;
}

void displayNewTurn(int turn, FighterObject *player, FighterObject *enemy) {
  clearScreen();
  printf("------------------------------------------------------------");
  printf("\n[Turn %d]\n\n", turn);
  printf("Your Hp is %d. The %s Hp is %d.\n", (int) player->curHp, enemy->name, (int) enemy->maxHp);
}

/// Return a random number between [0f,1f]
float randf() {
  return (float) rand() / (float) RAND_MAX;
}

/// Return a random number between [min,max]
float randfIn(float min, float max) {
  return randf() * max + min;
}

float calcDamage(int aLv, float aAttack, float bArmor) {
  float randomFactor = randfIn(0.85f, 1.0f);
  return ((((((2 * (float) aLv) / 5 + 2) * aAttack / bArmor) / 50) + 2) * randomFactor) / 100;
}

#pragma clang diagnostic pop