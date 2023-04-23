//
// Created by Liplum on 4/23/2023.
//

#include <stdio.h>
#include "../game.h"

Enemy slime = {
  .name = "Slime",
  .maxHp = 50,
  .attack = 12,
  .armor = 0,
  .level= 1,
  .expReward = 200,
};

void level1(Player *playerInfo) {
  int turn = 0;
  FighterObject *player = newFighterObjectFromPlayer(playerInfo);
  FighterObject *enemy = newFighterObjectFromEnemy(&slime);
  while (1) {
    displayNewTurn(turn + 1, player, enemy);
    int choice = getChoice();
    printf("\n");
    switch (choice) {
      case ATTACK: {
        turn++;
        float playerDmg = calcDamage(playerInfo->level, player->attack, enemy->armor);
        enemy->curHp -= playerDmg;
        float enemyDmg = calcDamage(slime.level, enemy->attack, player->armor);
        slimeCaused = waving(curEnemy.attack) - player.armor;
        player.maxHp -= slimeCaused;
        if (curEnemy.maxHp > 0 && player.maxHp > 0) { //Not yet killed
          printf("\nYou slashed the enemy and cause %d attack!\n\n", playerCaused);
          printf("\nSlime hit you and caused %d attack!", slimeCaused);
          getchar();
          getchar();
          goto loop_slime;
        } else if (curEnemy.maxHp <= 0) { //Killed
          printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("\nA critical strike is performed!\n\n");
          printf("Congratulations! You won the fight.\n\n");
          ending = 1;
          part += 1;
          goto end;
        } else { //Failed
          printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("\nYou slashed the enemy and cause %d attack!\n\n", playerCaused);
          printf("\nSlime rushed swiftly and consumed you!\n\n");
          getchar();
          getchar();
          goto die;
        }
      }
        break;
      case PARRY: {
        turn++;
        slimeCaused = waving(curEnemy.attack) - player.armor * 2;
        player.maxHp -= slimeCaused;
        if (player.maxHp > 0) {
          printf("\nYou raised the shield and defended.\n");
          printf("\nSlime hit you and cause %d!\n\n", slimeCaused);
          getchar();
          getchar();
          goto loop_slime;
        } else {
          printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("\nYou raised the shield and tried to defend.\n");
          printf("\nBut enemy countered your defense...\n\n");
          ending = 0;
          goto die;
        }
      }
        break;
      case Withdraw: {
        turn++;
        printf("\nSlime stuck your legs.\n");
        slimeCaused = waving(curEnemy.attack);
        player.maxHp -= curEnemy.attack;
        if (player.maxHp > 0) {
          printf("\nYou were distracted and caught by slimes. You lost %d attack.\n\n", slimeCaused);
          getchar();
          getchar();
          goto loop_slime;
        } else {
          printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
          printf("\nSlime caught you and consumed your body. How poor you are!\n\n");
          ending = 0;
          goto die;
        }
      }
        break;
      default:
        continue;
    }
  }
}