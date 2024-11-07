#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"  // NOLINT

// effets des moves
void deal_damage(int damage, Supemon *target, Supemon *launcher) {
    int evade_chance = 100* launcher->accuracie[0]/(launcher->accuracie[0]+target->evasion[0]);
    int randvar = rand()%100 +1;
    printf("%d chance de toucher  %d generer\n", evade_chance, randvar);
    if (randvar < evade_chance) {
            int true_damage = damage*launcher->attack[0]/target->defence[0];
            if ((damage*launcher->attack[0]/target->defence[0])%1 == 0) {target->hp[0] -= true_damage;
            } else {
                if ((rand()%100 +1)> 50) {true_damage++;}
            target->hp[0] -= true_damage;
            }
        printf("%s take damage\n", target->name);
    } else {printf("Attack missed\n");}
}

void up_attack(Supemon *launcher) {
    launcher->attack[0]+=1;
    printf("Attack up\n");
}

void up_evasion(Supemon *launcher) {
    launcher->evasion[0]+=1;
    printf("Evasion up\n");
}

void up_deffence(Supemon *launcher) {
    launcher->defence[0]+=1;
    printf("Defense up\n");
}

// move
char* get_move_name(unsigned int id) {
    switch (id) {
    case 1:return "Scratch";
    case 2:return "Pound";
    case 3:return "Grawl";
    case 4:return "Foliage";
    case 5:return "Shell";
    default:return("Not a move");
    }
}

void move_effect(unsigned int id, Supemon *target, Supemon *launcher) {
    switch (id) {
    case 1:deal_damage(3, target, launcher); break;
    case 2:deal_damage(2, target, launcher); break;
    case 3:up_attack(launcher); break;
    case 4:up_evasion(launcher); break;
    case 5:up_deffence(launcher); break;
    }}
