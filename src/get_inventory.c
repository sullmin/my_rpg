/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include <stdlib.h>
#include <stdbool.h>
#include "myrpg.h"

extern int NB_ITEM_INVENTORY;

item_t *get_player_inventory(void)
{
    item_t *inventory = malloc(sizeof(item_t) * NB_ITEM_INVENTORY);

    if (!inventory)
        return NULL;
    for (size_t i = 0; i < NB_ITEM_INVENTORY; i++) {
        inventory[i] = {0};
        inventory[i].name = NULL;
    }
    return inventory;
}