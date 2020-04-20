/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-20T15:52:52+02:00 | Author: simon
*/

#include "my_rpg.h"

int kinem_start(isow_t *isow, sound_manager_t *sound)
{
    isow->kinem.start = true;
    isow->kinem.curr_angle = isow->kinem.start_angle;
    isow->kinem.timer = 0;
    isow->kinem.idx_player_move = 0;
    object_on_map_set_coord(&isow->player, &isow->map,
    isow->kinem.player_start_pos.x, isow->kinem.player_start_pos.y);
    map_set_angley(&isow->map, isow->kinem.start_angle);
    sound_manager_stop_all(sound);
    sound_manager_play(sound, isow->kinem.id_music);
    return EXIT_SUCCESS;
}

int kinem_stop(isow_t *isow, sound_manager_t *sound)
{
    isow->kinem.start = false;
    sound_manager_stop_all(sound);
    return EXIT_SUCCESS;
}
