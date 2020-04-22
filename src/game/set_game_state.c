/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T15:00:44+02:00 | Author: simon
*/

#include "my_rpg.h"

static void music_manager(game_t *game)
{
    if (game->state == MAIN_MENU) {
        sound_manager_stop_all(&SOUND);
        sound_manager_play(&SOUND, MUSIC1);
    }
}

void set_game_state(game_t *game, game_status_t new_state)
{
    if (game->state == ISO_WORLD || game->state == MAIN_WORLD) {
        game->prev_state = game->state;
    }
    game->state = new_state;
    music_manager(game);
}
