/*Copyright 2024 <Lint arrete de m'embeter sur les copiright>*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "header.h"  // NOLINT



typedef struct {
    char name[10];
    Supemon list_supemon[6];
    Supemon* curr_supemon;
    __int64 supcoins;
    Item bag[50];
    int bag_count;
    }Player;

Supemon Dex();
void ooc_menu();
Player curr_player;
int choice_var = 0;
void save(Player *player, const char *file_name);
void load(Player *player, const char *file_name);
void buy_item(__int64 *supcoins, Item *bag, int *bag_count);
void sell_item(__int64 *supcoins, Item *bag, int *bag_count);
void shop();


int main() {
    srand(time(NULL));
    void starter_choose();
    do {
        printf("Hello world!\n");
        printf(" 1:Choose a Name\n 2:Load a Save\n");
        scanf("%d", &choice_var);
        if (choice_var != 1 && choice_var != 2) {
            printf("invalid input");
        } while (getchar() != '\n');
    }while (choice_var !=1 && choice_var != 2);
    switch (choice_var) {
    case 1:
        printf("What's your name?\n");
        scanf("%10s", curr_player.name);
        curr_player.supcoins = 1000;
        curr_player.bag_count = 0;
        starter_choose();
        break;
    case 2:
        load(&curr_player, "savegame.txt");
    }

    return 0;
}

void starter_choose() {
    int choice_var = 0;

    do {
        printf(" Hello %s\n Welcome in Supemon World\n", curr_player.name);
        printf("============================\n");
        printf(" Choose your starter Supemon :\n");
        printf(" 1 - Supmander\n");
        printf(" 2 - Supasaur\n");
        printf(" 3 - Supirtle\n");
        printf("============================\n");
        scanf("%d", &choice_var);
        if (choice_var != 1 && choice_var != 2 && choice_var != 3) {
                    printf("no valid entry\n");
        }while (getchar() != '\n');
    }while(choice_var != 1 && choice_var != 2 && choice_var != 3);
    curr_player.list_supemon[0] = Dex(choice_var);
    curr_player.curr_supemon = &curr_player.list_supemon[0];
    printf("You choose %s. Congrat, Now GET OUT!!\n", curr_player.curr_supemon->name);
    ooc_menu();}


void ooc_menu() {
    int choice_var = 0;
    void heal();
    void combat_init();
    do {
        printf("+------------------------------------+\n");
        printf("|   1:Into the wild                  |\n");
        printf("|   2:Smilin'Stan S. Stanman         |\n");
        printf("|   3:Healing Center                 |\n");
        printf("|   4:Quit game                      |\n");
        printf("+------------------------------------+\n");
        scanf("%d", &choice_var);
        if (choice_var !=1 && choice_var !=2 && choice_var !=3 && choice_var !=4) {
                    printf("no valid entry\n");
        }while (getchar() != '\n');
    }while(choice_var != 1 && choice_var !=2 && choice_var !=3 && choice_var != 4);
    switch (choice_var) {
    case 1:combat_init(); break;
    case 2:shop(); break;
    case 3:heal(); break;
    case 4:
        save(&curr_player, "savegame.txt");
        exit(0);
        break;
    }
}

void combat_init() {
    void combat();
    void wild_turn(Supemon* wild_supemon);
    int r =(rand() % 3)+1;
    Supemon wild_supemon = Dex(r);
    wild_supemon.level = curr_player.curr_supemon->level;
    wild_supemon.hp[1] *= pow(1.3, wild_supemon.level);
    wild_supemon.hp[0] = wild_supemon.hp[1];
    wild_supemon.attack[1] *= pow(1.3, wild_supemon.level);
    wild_supemon.attack[0] = wild_supemon.attack[1];
    wild_supemon.defence[1] *= pow(1.3, wild_supemon.level);
    wild_supemon.defence[0] = wild_supemon.defence[1];
    wild_supemon.evasion[1] *= pow(1.3, wild_supemon.level);
    wild_supemon.evasion[0] = wild_supemon.evasion[1];
    wild_supemon.accuracie[1] *= pow(1.3, wild_supemon.level);
    wild_supemon.accuracie[0] = wild_supemon.accuracie[1];
    wild_supemon.speed *= pow(1.3, wild_supemon.level);

    Supemon *ptr = &wild_supemon;
    if (wild_supemon.speed > curr_player.curr_supemon->speed) {wild_turn(ptr);
    } else if (wild_supemon.speed < curr_player.curr_supemon->speed) {combat(ptr);
    } else {
        if ((rand()%100 +1) > 50) {wild_turn(ptr);
        } else {combat(ptr);}}}

void combat(Supemon *wild_supemon) {
    void run(Supemon *wild_supemon);
    void wild_turn(Supemon* wild_supemon);
    void capture(Supemon *wild_supemon);
    void change_supemon();
    void attack();
    void use_item(Item player_items[], int *player_item_count, Supemon *supemon);
    do {
        printf("Your turn\n");
        printf("============================\n");
        printf("%s (wild)\n", wild_supemon->name);
        printf("HP:%d / %d      LVL:%d\n", wild_supemon->hp[0], wild_supemon->hp[1], wild_supemon->level);
        printf("ATK:%u          DEF:%u\n", wild_supemon->attack[0], wild_supemon->defence[0]);
        printf("ACC:%u          EVA:%u\n", wild_supemon->accuracie[0], wild_supemon->evasion[0]);
        printf("============================\n");
        printf("%s (your's)\n", curr_player.curr_supemon->name);
        printf("HP:%d / %d      LVL:%d\n", curr_player.curr_supemon->hp[0],
        curr_player.curr_supemon->hp[1], curr_player.curr_supemon->level);
        printf("ATK:%u          DEF:%u\n", curr_player.curr_supemon->attack[0],
        curr_player.curr_supemon->defence[0]);
        printf("ACC:%u          EVA:%u\n", curr_player.curr_supemon->accuracie[0],
        curr_player.curr_supemon->evasion[0]);
        printf("============================\n");
        printf("What do you want to do :\n");
        printf("    1:Attack\n");
        printf("    2:Change supemon\n");
        printf("    3:Use item\n");
        printf("    4:Capture\n");
        printf("    5:Nigerundayo\n");
        printf("============================\n");
        scanf("%d", &choice_var);
        if (choice_var !=1 && choice_var !=2 && choice_var != 3 && choice_var != 4 && choice_var != 5) {
                printf("no valid entry");
                while (getchar() != '\n') {}
        }
    }while(choice_var != 1 && choice_var != 2 && choice_var != 3 && choice_var != 4 && choice_var != 5);
    switch (choice_var) {
    case 1:attack(wild_supemon); break;
    case 2:change_supemon(); wild_turn(wild_supemon); break;
    case 3:use_item(curr_player.bag, &curr_player.bag_count, curr_player.curr_supemon); wild_turn(wild_supemon); break;
    case 4:capture(wild_supemon); break;
    case 5:run(wild_supemon); break;
}}

void attack(Supemon* wild_supemon) {
    void end_of_fight(Supemon* wild_supemon, int who_win);
    void wild_turn(Supemon* wild_supemon);

    do {
        printf("============================\n");
        printf("    1:%s\n", get_move_name(curr_player.curr_supemon->move_id[0]));
        printf("    2:%s\n", get_move_name(curr_player.curr_supemon->move_id[1]));
        printf("    3:Cancel\n");
        printf("============================\n");
        scanf("%d", &choice_var);
        if (choice_var !=1 && choice_var !=2 && choice_var !=3) {
                printf("No valid entry");
                while (getchar() != '\n') {}}
        }while(choice_var != 1 && choice_var != 2 && choice_var != 3);

    switch (choice_var) {
    case 1:
        move_effect(curr_player.curr_supemon->move_id[0] , wild_supemon , curr_player.curr_supemon);
        printf("%d HP left\n", wild_supemon->hp[0]);
        break;
    case 2:
        move_effect(curr_player.curr_supemon->move_id[1] , wild_supemon , curr_player.curr_supemon);
        break;
    case 3:combat(wild_supemon);
        break;
    }


    if (wild_supemon->hp[0] <=0 ) {end_of_fight(wild_supemon, 1);
    } else {wild_turn(wild_supemon);}
}

void wild_turn(Supemon* wild_supemon) {
    printf("Enemy turn\n");
    void end_of_fight(Supemon* wild_supemon, int who_win);
    move_effect(wild_supemon->move_id[rand()%2] , curr_player.curr_supemon , wild_supemon);
    if (curr_player.curr_supemon->hp[0] <= 0) {end_of_fight(wild_supemon, 0);
    } else {combat(wild_supemon);}
}

void end_of_fight(Supemon* wild_supemon, int who_win) {
    void change_supemon();
    void level_up();
    curr_player.curr_supemon->attack[0] = curr_player.curr_supemon->attack[1];
    curr_player.curr_supemon->defence[0] = curr_player.curr_supemon->defence[1];
    curr_player.curr_supemon->evasion[0] = curr_player.curr_supemon->evasion[1];
    curr_player.curr_supemon->accuracie[0] = curr_player.curr_supemon->accuracie[1];

    if (who_win == 0) {change_supemon();
    } else if (who_win == 1) {
        curr_player.supcoins+=rand()%401 +100;
        curr_player.curr_supemon->xp += wild_supemon->level * (rand()%401 +100);
        if (curr_player.curr_supemon->xp >= 500 + 1000 * (curr_player.curr_supemon->level - 1)) {level_up();}
    ooc_menu();
    }
}

void level_up() {
    printf("%s Level up!!!" , curr_player.curr_supemon->name);
            curr_player.curr_supemon->xp-= 500 + 1000 * (curr_player.curr_supemon->level - 1);
            curr_player.curr_supemon->level+=1;

            if (floor(curr_player.curr_supemon->hp[1] * 1.3) == curr_player.curr_supemon->hp[1] * 1.3) {
                if (rand() > 0.5) {curr_player.curr_supemon->hp[1] = curr_player.curr_supemon->hp[1]*1.3 +1;
                } else {curr_player.curr_supemon->hp[1]*=1.3;}
            } else {curr_player.curr_supemon->hp[1]*=1.3;}

            if (floor(curr_player.curr_supemon->attack[1] * 1.3) == curr_player.curr_supemon->attack[1] * 1.3) {
                if (rand() > 0.5) {
                    curr_player.curr_supemon->attack[1] = curr_player.curr_supemon->attack[1]*1.3 +1;
                } else {curr_player.curr_supemon->attack[1]*=1.3;}
            } else {curr_player.curr_supemon->attack[1]*=1.3;}

            if (floor(curr_player.curr_supemon->defence[1] * 1.3) == curr_player.curr_supemon->defence[1] * 1.3) {
                if (rand() > 0.5) {
                    curr_player.curr_supemon->defence[1] = curr_player.curr_supemon->defence[1]*1.3 +1;
                } else {curr_player.curr_supemon->defence[1]*=1.3;}
            } else {curr_player.curr_supemon->defence[1]*=1.3;}

            if (floor(curr_player.curr_supemon->evasion[1] * 1.3) == curr_player.curr_supemon->evasion[1] * 1.3) {
                if (rand() > 0.5) {
                    curr_player.curr_supemon->evasion[1] = curr_player.curr_supemon->evasion[1]*1.3 +1;
                } else {curr_player.curr_supemon->evasion[1]*=1.3;}
            } else {curr_player.curr_supemon->evasion[1]*=1.3;}

            if (floor(curr_player.curr_supemon->accuracie[1] * 1.3) == curr_player.curr_supemon->accuracie[1] * 1.3) {
                if (rand() > 0.5) {
                    curr_player.curr_supemon->accuracie[1] = curr_player.curr_supemon->accuracie[1]*1.3 +1;
                } else {curr_player.curr_supemon->accuracie[1]*=1.3;}
            } else {curr_player.curr_supemon->accuracie[1]*=1.3;}

            if (floor(curr_player.curr_supemon->speed * 1.3) == curr_player.curr_supemon->speed * 1.3) {
                if (rand() > 0.5) {
                    curr_player.curr_supemon->speed = curr_player.curr_supemon->speed*1.3 +1;
                } else {curr_player.curr_supemon->speed*=1.3;}
            } else {curr_player.curr_supemon->speed*=1.3;}

            curr_player.curr_supemon->attack[0] = curr_player.curr_supemon->attack[1];
            curr_player.curr_supemon->defence[0] = curr_player.curr_supemon->defence[1];
            curr_player.curr_supemon->evasion[0] = curr_player.curr_supemon->evasion[1];
            curr_player.curr_supemon->accuracie[0] = curr_player.curr_supemon->accuracie[1];}

void change_supemon() {
    int tf_var;

    do {
        tf_var = 0;
        printf("================================\n");
        for (int i = 0; i < 6; i++) {
            printf("%d: %s   %d/%d HP\n", i+1, curr_player.list_supemon[i].name,
                curr_player.list_supemon[i].hp[0], curr_player.list_supemon[i].hp[1]);
            if (strcmp(curr_player.list_supemon[i].name, "") != 0 && curr_player.list_supemon[i].hp[0] > 0) {
                tf_var = 1;}}
        printf("================================\n");

        if (tf_var == 0) {
            printf("All your Supemons are defeated!\n");
            exit(0);}

        printf("Choose a Supemon (1-6): ");
        scanf("%d", &choice_var);

        if (choice_var < 1 || choice_var > 6) {
            printf("Invalid choice. Please select a number between 1 and 6.\n");
            while (getchar() != '\n') {}
        } else {choice_var--;}

        if (strcmp(curr_player.list_supemon[choice_var].name, "")
            != 0 && curr_player.list_supemon[choice_var].hp[0] > 0) {
            curr_player.curr_supemon = &curr_player.list_supemon[choice_var];
        } else {
            printf("The chosen Supemon is not available or has no HP left. Please choose another one.\n");}
    } while (curr_player.curr_supemon == NULL || curr_player.curr_supemon->hp[0] <= 0);
}

void capture(Supemon *wild_supemon) {
    int capture_rate = (((wild_supemon->hp[1]-wild_supemon->hp[0])/wild_supemon->hp[1]) -0.5) *100;
    for (int i = 0; i < 5; i++) {
        if (strcmp(curr_player.list_supemon[i].name, "") == 0) {
            if ((rand()%100 +1) <= capture_rate) {
                printf("========Wild supemon captured=========\n");
                curr_player.list_supemon[i]=*wild_supemon;
                    curr_player.list_supemon[i].attack[0] = curr_player.list_supemon[i].attack[1];
                    curr_player.list_supemon[i].defence[0] = curr_player.list_supemon[i].defence[1];
                    curr_player.list_supemon[i].evasion[0] = curr_player.list_supemon[i].evasion[1];
                    curr_player.list_supemon[i].accuracie[0] = curr_player.list_supemon[i].accuracie[1];
                end_of_fight(wild_supemon, 1);
            } else {
                printf("Capture missed");
                wild_turn(wild_supemon);}}}}

void run(Supemon *wild_supemon) {
    int run_rate = (curr_player.curr_supemon->speed/(curr_player.curr_supemon->speed+wild_supemon->speed))*100;
    if ((rand()%100 +1) <= run_rate) {ooc_menu();
    } else {wild_turn(wild_supemon);}
    }


void shop() {
    do {
        printf("Welcome to the Shop!\n");
        printf("Smilin'Stan S. Stanman\n");
        printf("1 - Buy Items\n2 - Sell Items\n3 - Exit shop");
        scanf("%d", &choice_var);
    }while(choice_var != 1 && choice_var != 2 && choice_var != 3);
    switch (choice_var) {
    case 1:
        buy_item(&curr_player.supcoins, curr_player.bag, &curr_player.bag_count);
        printf("Thank you for your purchase!\n");
        break;
    case 2:
        sell_item(&curr_player.supcoins, curr_player.bag, &curr_player.bag_count);
        break;
    case 3:
        ooc_menu();
    }
    ooc_menu();
}

void use_item(Item player_items[], int *player_item_count, Supemon *supemon) {
    if (*player_item_count == 0) {
        printf("You have no items to use.\n");
        return;
    }

    printf("Your items:\n");
    int displayed_count = 0;  // Compteur pour savoir combien d'items valides sont affiches
    for (int i = 0; i < *player_item_count; i++) {
        if (strlen(player_items[i].name) > 0) {  // Ne montre que les items valides
            printf("%d. %s\n", displayed_count + 1, player_items[i].name);
            displayed_count++;
        }
    }

    if (displayed_count == 0) {
        printf("You have no usable items.\n");
        return;
    }

    int choice;
    printf("Enter the item number to use: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > displayed_count) {
        printf("Invalid choice.\n");
        return;
    }

    Item selected_item = player_items[choice - 1];

    if (strcmp(selected_item.name, "Potion") == 0) {
        int hp_restored = 5;
        supemon->hp[0] += hp_restored;
        if (supemon->hp[0] > supemon->hp[1]) {
            supemon->hp[0] = supemon->hp[1];
        }
        printf("Your %s restored %d HP!\n", supemon->name, hp_restored);
    } else if (strcmp(selected_item.name, "Super Potion") == 0) {
        int hp_restored = 10;
        supemon->hp[0] += hp_restored;
        if (supemon->hp[0] > supemon->hp[1]) {
            supemon->hp[0] = supemon->hp[1];
        }
        printf("Your %s restored %d HP!\n", supemon->name, hp_restored);
    } else if (strcmp(selected_item.name, "Rare Candy") == 0) {
        supemon->level += 1;
        printf("Your %s leveled up to %d!\n", supemon->name, supemon->level);

        supemon->hp[1] = (int)(supemon->hp[1] * 1.3);  // NOLINT
        supemon->attack[1] = (int)(supemon->attack[1] * 1.3);  // NOLINT
        supemon->defence[1] = (int)(supemon->defence[1] * 1.3);  // NOLINT
        supemon->evasion[1] = (int)(supemon->evasion[1] * 1.3);  // NOLINT
        supemon->accuracie[1] = (int)(supemon->accuracie[1] * 1.3);  // NOLINT
        supemon->speed = (int)(supemon->speed * 1.3);  // NOLINT
        supemon->hp[0] = supemon->hp[1];
        supemon->attack[0] = supemon->attack[1];
        supemon->defence[0] = supemon->defence[1];
        supemon->evasion[0] = supemon->evasion[1];
        supemon->accuracie[0] = supemon->accuracie[1];
        printf("Stats have been recalculated.\n");
    }

    for (int i = choice - 1; i < *player_item_count - 1; i++) {
        player_items[i] = player_items[i + 1];
    }
    (*player_item_count)--;

    return;
}


void heal() {
    for (int i = 0; i  <6; i++) {
        curr_player.list_supemon[i].hp[0] = curr_player.list_supemon[0].hp[1];
    }
    ooc_menu();}


void save(Player *player, const char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error when opening the backup file\n");
        return;
    }


    fprintf(file, "Name:%s\n", player->name ? player->name : "Unknown");
    fprintf(file, "Supcoins:%llu\n", player->supcoins);
    fprintf(file, "Bag_count:%d\n", player->bag_count);


    for (int i = 0; i < 6; i++) {
        Supemon sup = player->list_supemon[i];
        if (strlen(sup.name) > 0) {
            fprintf(file, "Supemon:%s,%d,%u,%d,%d,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u\n",
                sup.name,
                sup.level, sup.xp,
                sup.hp[0], sup.hp[1],
                sup.attack[0], sup.attack[1],
                sup.defence[0], sup.defence[1],
                sup.evasion[0], sup.evasion[1],
                sup.accuracie[0], sup.accuracie[1],
                sup.speed,
                sup.move_id[0], sup.move_id[1]);
        }
    }


    for (int i = 0; i < player->bag_count; i++) {
        if (strlen(player->bag[i].name) > 0) {
            fprintf(file, "Item:%s,%d,%d\n", player->bag[i].name, player->bag[i].buy_price, player->bag[i].sell_price);
        }
    }

    fclose(file);
    printf("Save successfully to %s.\n", file_name);
}

void load(Player *player, const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error when opening the upload file\n");
        return;
    }

    char line[256];
    int supemon_index = 0;

    player->bag_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name:%49s", player->name);
        } else if (strncmp(line, "Supcoins:", 9) == 0) {
            sscanf(line, "Supcoins:%llu", &player->supcoins);
        } else if (strncmp(line, "Bag_count:", 10) == 0) {
            sscanf(line, "Bag_count:%d", &player->bag_count);
        } else if (strncmp(line, "Supemon:", 8) == 0 && supemon_index < 6) {
            if (sscanf(line, "Supemon:%49[^,],%d,%u,%d,%d,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u",
                player->list_supemon[supemon_index].name,
                &player->list_supemon[supemon_index].level,
                &player->list_supemon[supemon_index].xp,
                &player->list_supemon[supemon_index].hp[0],
                &player->list_supemon[supemon_index].hp[1],
                &player->list_supemon[supemon_index].attack[0],
                &player->list_supemon[supemon_index].attack[1],
                &player->list_supemon[supemon_index].defence[0],
                &player->list_supemon[supemon_index].defence[1],
                &player->list_supemon[supemon_index].evasion[0],
                &player->list_supemon[supemon_index].evasion[1],
                &player->list_supemon[supemon_index].accuracie[0],
                &player->list_supemon[supemon_index].accuracie[1],
                &player->list_supemon[supemon_index].speed,
                &player->list_supemon[supemon_index].move_id[0],
                &player->list_supemon[supemon_index].move_id[1]) != 16) {
                printf("Error loading Supemon to index %d\n", supemon_index);
            }
            supemon_index++;
        } else if (strncmp(line, "Item:", 5) == 0) {
            char item_name[50];
            int buy_price, sell_price;
            sscanf(line, "Item:%49[^,],%d,%d", item_name, &buy_price, &sell_price);
            if (player->bag_count < 50) {
                snprintf(player->bag[player->bag_count].name,
                    sizeof(player->bag[player->bag_count].name), "%s", item_name);
                player->bag[player->bag_count].buy_price = buy_price;
                player->bag[player->bag_count].sell_price = sell_price;
                player->bag_count++;
            }
        }
    }

    if (supemon_index > 0) {
        player->curr_supemon = &player->list_supemon[0];  // On selectionne le premier Supemon de la liste
    }

    fclose(file);
    printf("Successful loading from %s.\n", file_name);
    printf("Hello, %s! Welcome back to Supemon World!\n", player->name);

    ooc_menu();
}
