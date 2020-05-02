/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

door_t const DIF_DOOR[] = {
    (door_t) {'P', "113"},
    (door_t) {'V', "213"},
    (door_t) {'R', "313"},
    (door_t) {'T', "413"}
};

static void quest_manage(game_t *game, const char type)
{
    if (type == 'T') {
        player_teleportation(game);
    }
}

bool is_correct_door(sfVector2i *pos, game_t *game)
{
    for (size_t i = 0; i < 4; i++)
        if (WMAIN->hitbox[pos->y][pos->x] == DIF_DOOR[i].type) {
            if (is_in_player_inv(&game->inventory, DIF_DOOR[i].id)) {
                quest_manage(game, DIF_DOOR[i].type);
                return true;
            } else if (as_seconds(WMAIN->sound_effect[2].clock) > 1) {
                sfSound_play(WMAIN->sound_effect[2].sound);
                sfClock_restart(WMAIN->sound_effect[2].clock);
            }
        }
    return false;
}
