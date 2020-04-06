/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "inventory_system.h"
#include "my.h"

bool is_in_player_inv(player_inventory_t *inv, const char *id)
{
    for (size_t i = 0; i < inv->size; i++)
        if (inv->inventory[i] && my_strcmp(inv->inventory[i]->id, id) == 0)
            return true;
    return false;
}