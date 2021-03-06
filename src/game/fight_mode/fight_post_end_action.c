/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-01T12:11:05+02:00 | Author: simon
*/

#include "my_rpg.h"

const int FIGHT_WIN = 1;

void fight_post_end_action(game_t *game, int status)
{
    sound_manager_stop_all(&SOUND);
    if (status == FIGHT_WIN) {
        player_add_xp(game, 2);
        sound_manager_play(&SOUND, SUCCESS);
    } else {
        sound_manager_play(&SOUND, HIT);
    }
    sound_manager_play(&SOUND, FANTASY_THEME);
}

void fight_start_action(game_t *game)
{
    sound_manager_stop_all(&SOUND);
    sound_manager_play(&SOUND, BATTLE);
}
