/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

door_t const DIF_DOOR[] = {
    (door_t) {'P', "113"},
    (door_t) {'V', "113"},
    (door_t) {'R', "113"},
    (door_t) {'T', "113"}
};

bool is_correct_door(sfVector2i *pos, game_t *game)
{
    for (size_t i = 0; i < 4; i++)
        if (WMAIN->hitbox[pos->y][pos->x] == DIF_DOOR[i].type &&
            is_in_player_inv(&game->inventory, DIF_DOOR[i].id))
            return true;
    return false;
}