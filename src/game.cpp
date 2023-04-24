//
// Created by Liplum on 4/23/2023.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <iostream>
#include "console.h"
#include "entity.h"
#include "ui.h"
#include "calculate.h"
#include "game.h"

using namespace std;

ActionType getActionChoice() {
  int choice = 0;
  cout << "Attack=1, Parry=2, Withdraw=3" << endl;
  while (choice != Attack && choice != Parry && choice != Withdraw) {
    cout << "Your choice:";
    cin >> choice;
  }
  return static_cast<ActionType>(choice);
}

const int healthBarWidth = 15;

void displayHealthBar(Fighter &fighter) {
  cout << fighter.type->getName() << " HP:" << endl;
  cout << "\t|" << createHealthBar(fighter.curHp, fighter.type->getMaxHp(), healthBarWidth) << "| "
       << static_cast<int>(fighter.curHp) << endl;
}

void displayNewTurnBanner(Fighter &player, Fighter &enemy, int turn) {
  clearScreen();
  printf("------------------------------------------------------------\n");
  cout << "[Turn " << turn << "]" << endl;
  displayHealthBar(player);
  displayHealthBar(enemy);
}

float calcDamage(int aLv, float aAttack, float aPower, float bArmor) {
  float randomFactor = randfIn(0.85f, 1.0f);
  bArmor = bArmor > 1 ? bArmor : 1;
  float damageFactor = aAttack / bArmor;
  float attackerLvFactor = 2 * (float) aLv / 5 + 2;
  float damage = attackerLvFactor * aPower * damageFactor / 50;
  return damage * randomFactor;
}

#pragma clang diagnostic pop
