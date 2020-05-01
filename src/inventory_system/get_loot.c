/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool get_loot(game_t *game)
{
    list_t *item_load = game->item_load;
    list_t *end = item_load;

    if (!end)
        return false;
    while (end && (PLAYER_INT.x != end->item->pos.x
            && PLAYER_INT.y != end->item->pos.y)) {
        end = end->next;
    }
    if (!end)
        return false;
    if (!add_item_in_player_inv(&game->inventory, end->item)) {
        return false;
    }
    sound_manager_play(&SOUND, CLOCHE);
    return true;
}
