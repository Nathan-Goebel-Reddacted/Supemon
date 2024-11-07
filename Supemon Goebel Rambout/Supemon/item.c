#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"  // NOLINT

Item items_for_sale[] = {
    {"Potion", "Restore 5 HP", 100, 50},
    {"Super Potion", "Restore 10 HP", 300, 150},
    {"Rare Candy", "Increase a Supemon's level by 1", 700, 350}
};

int num_items_for_sale = 3;


void show_items_for_sale() {
    printf("Items available for purchase:\n");
    for (int i = 0; i < num_items_for_sale; i++) {
        printf("%d. %s - %d Supcoins (%s)\n", i + 1, items_for_sale[i].name,
            items_for_sale[i].buy_price, items_for_sale[i].description);
    }
}

void buy_item(__int64 *player_supcoins, Item player_items[], int *player_item_count) {
    show_items_for_sale();
    int choice;
    printf("Enter the item number to buy: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_items_for_sale) {
        printf("Invalid choice.\n");
        return;
    }

    if (*player_item_count >= 50) {
        printf("Your bag is full! You can't carry more items.\n");
        return;
    }

    Item selected_item = items_for_sale[choice - 1];
    if (*player_supcoins >= selected_item.buy_price) {
        player_items[*player_item_count] = selected_item;
        (*player_item_count)++;
        *player_supcoins -= selected_item.buy_price;
        printf("You bought %s!\n", selected_item.name);
    } else {
        printf("You don't have enough Supcoins!\n");
    }
}

void sell_item(__int64 *player_supcoins, Item player_items[], int *player_item_count) {
    if (*player_item_count == 0) {
        printf("You have no items to sell.\n");
        return;
    }

    printf("Your items:\n");
    for (int i = 0; i < *player_item_count; i++) {
        printf("%d. %s - Sell Price: %d Supcoins\n", i + 1, player_items[i].name, player_items[i].sell_price);
    }

    int choice;
    printf("Enter the item number to sell: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > *player_item_count) {
        printf("Invalid choice.\n");
        return;
    }

    Item selected_item = player_items[choice - 1];
    *player_supcoins += selected_item.sell_price;

    // Supprimer l'item vendu en decalant les elements
    for (int i = choice - 1; i < *player_item_count - 1; i++) {
        player_items[i] = player_items[i + 1];
    }
    (*player_item_count)--;
    printf("You sold %s!\n", selected_item.name);
}
