/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

//créer une fonction qui prend un id et qui ajoute l'item dans l'inventaire

#include <stdbool.h>
#include "inventory_system.h"

bool add_item_in_player_inv(player_inventory_t *inv, item_t *item)
{
    for (size_t i = 0; i < inv->size; i++)
        if (!inv->inventory[i]) {
            inv->inventory[i] = item;
            return true;
        }
    return false;
}

bool move_item_in_inventory(player_inventory_t *inv, list_t *item_load,
    const char *id)
{
    list_t *end = item_load;

    if (!end)
        return false;
    while (!end && my_strcmp(id, end->item->id) != 0)
        end = end->next;
    if (!end)
        return false;
    add_item_in_player_inv(inv, end->item);
    return true;
}