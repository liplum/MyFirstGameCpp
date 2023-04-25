//
// Created by Liplum on 4/24/2023.
//

#include <cstdio>
#include "../game.h"
#include "../console.h"
#include "level_1.h"
#include "../calculate.h"

Enemy *createSlime() {
  auto e = new Enemy;
  e->name = "Slime";
  e->maxHp = 120.0f;
  e->attack = 12.0f;
  e->armor = 2.0f;
  e->level = 1;
  e->expReward = 10;
  return e;
}

void SlimeLevel::onEnter() {
  printf("A slime is coming here...");
  alert();
  getchar();
}

const float escapeChance = 0.01f;

BattleResult SlimeLevel::startBattle(const BattleContext &ctx) const {
  auto enemySlime = *createSlime();
  auto player = *ctx.player.create();
  auto enemy = *enemySlime.create();
  int turn = 0;
  while (true) {
    turn++;
    displayNewTurnBanner(player, enemy, turn);
    ActionType choice = getActionChoice();
    printf("\n");
    switch (choice) {
      case Attack: {
        float playerCaused = player.getAttackDamageTo(enemy);
        enemy.curHp -= playerCaused;
        float slimeCaused = enemy.getAttackDamageTo(player);
        player.curHp -= slimeCaused;
        if (enemy.curHp <= 0) { //Killed
          printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("A critical strike is performed!\n");
          printf("Congratulations! You won the fight.\n");
          return BattleWin;
        }
        if (player.curHp <= 0) { //Failed
          printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("You slashed the enemy and cause %d damage!\n", (int) playerCaused);
          printf("Slime rushed swiftly and consumed you!\n");
          getchar();
          getchar();
          return BattleLoss;
        }
        //Not yet killed
        printf("You slashed the enemy and cause %d damage!\n", (int) playerCaused);
        printf("Slime hit you and caused %d damage!\n", (int) slimeCaused);
        getchar();
        getchar();
        continue;
      }
      case Parry: {
        player.armor *= 2;
        float slimeCaused = enemy.getAttackDamageTo(player);
        player.curHp -= slimeCaused;
        if (player.curHp <= 0) {
          printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("You raised the shield and tried to defend.\n");
          printf("But enemy countered your defense...\n");
          getchar();
          return BattleLoss;
        }
        printf("You raised the shield and defended.\n");
        printf("Slime hit you and cause %d!\n", (int) slimeCaused);
        getchar();
        getchar();
        player.armor = player.type.getArmor();
        continue;
      }
      case Withdraw: {
        if (randf() <= escapeChance) {
          return BattleEscape;
        }
        printf("Slime stuck your legs.\n");
        float slimeCaused = enemy.getAttackDamageTo(player, 1.5f);
        player.curHp -= slimeCaused;
        if (player.curHp <= 0) {
          printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("Slime caught you and consumed your body. How poor you are!\n");
          getchar();
          return BattleLoss;
        }
        printf("You were distracted and caught by slimes. You lost %d damage.\n", (int) slimeCaused);
        getchar();
        getchar();
        continue;
      }
    }
  }
}
