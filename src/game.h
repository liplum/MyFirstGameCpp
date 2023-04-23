//
// Created by Liplum on 4/23/2023.
//
#include "entity.h"

#ifndef GAME_H
#define GAME_H

#define ATTACK  1
#define PARRY  2
#define Withdraw  3

int getChoice();

void displayNewTurn(int turn, FighterObject *player, FighterObject *enemy);

int waving(int value);

float calcDamage(int aLv, float aAttack, float bArmor);

#endif //GAME_H
