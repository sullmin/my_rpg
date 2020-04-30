/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

//créer une fonction qui prend un id et qui ajoute l'item dans l'inventaire

#include <stdbool.h>
#include "inventory_system.h"
#include "game_t.h"

bool add_item_in_player_inv(player_inventory_t *inv, item_t *item)
{
    for (size_t i = 0; i < inv->size; i++)
        if (!inv->inventory[i]) {
            inv->inventory[i] = item;
            return true;
        }
    return false;
}

bool move_item_in_inventory(game_t *game, const char *id)
{
    list_t *item_load = game->item_load;
    list_t *end = item_load;

    if (!end)
        return false;
    while (end && my_strcmp(id, end->item->id) != 0)
        end = end->next;
    if (!end)
        return false;
    if (!add_item_in_player_inv(&game->inventory, end->item)) {
        return false;
    } else {
        sysquest_check_end(game);
    }
    return true;
}
