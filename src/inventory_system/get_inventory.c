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

item_t **get_player_inventory(int size)
{
    item_t **inventory;

    if (size <= 0)
        return NULL;
    inventory = malloc(sizeof(item_t *) * size);
    if (!inventory)
        return NULL;
    for (size_t i = 0; i < size; i++)
        inventory[i] = NULL;
    return inventory;
}