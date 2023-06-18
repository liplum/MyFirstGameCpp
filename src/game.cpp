//
// Created by Liplum on 4/23/2023.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <iostream>
#include "console.h"
#include "entity.h"
#include "ui.h"
#include "utils.h"
#include "game.h"
#include <algorithm>

using namespace std;

float calcDamage(int aLv, float aAttack, float aPower, float bArmor) {
  float randomFactor = randfIn(0.85f, 1.0f);
  bArmor = max(bArmor, 1.0f);
  float damageFactor = aAttack / bArmor;
  float attackerLvFactor = 2 * (float) aLv / 5 + 2;
  float damage = attackerLvFactor * aPower * damageFactor / 50;
  return damage * randomFactor;
}

#pragma clang diagnostic pop
