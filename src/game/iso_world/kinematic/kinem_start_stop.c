/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-20T15:52:52+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const sfVector2i PLAYER_MOVEMENT[];

int kinem_start(isow_t *isow, sound_manager_t *sound)
{
    isow->kinem.start = true;
    isow->kinem.mode = ANGLE;
    isow->kinem.curr_angle = isow->kinem.start_angle;
    isow->kinem.timer = 0;
    isow->kinem.idx_player_move = 0;
    map_scale_all(isow, isow->kinem.scale);
    object_on_map_set_coord(&isow->player, &isow->map,
    isow->kinem.player_start_pos.x, isow->kinem.player_start_pos.y);
    map_set_angley(&isow->map, isow->kinem.start_angle);
    map_set_angley(&isow->map_water, isow->kinem.start_angle);
    sound_manager_stop_all(sound);
    sound_manager_play(sound, isow->kinem.id_music);
    return EXIT_SUCCESS;
}

int kinem_stop(game_t *game)
{
    size_t idx = 0;

    ISOW.kinem.start = false;
    sound_manager_stop_all(&SOUND);
    map_scale_all(&ISOW, (-ISOW.kinem.scale));
    object_on_map_set_coord(&ISOW.player, &ISOW.map,
    ISOW.kinem.player_start_pos.x, ISOW.kinem.player_start_pos.y);
    while (!(PLAYER_MOVEMENT[idx].x == 0 && PLAYER_MOVEMENT[idx].y == 0)) {
        object_on_map_move(&ISOW.player, &ISOW.map, PLAYER_MOVEMENT[idx].x,
        PLAYER_MOVEMENT[idx].y);
        idx++;
    }
    quest_enable(game, 0);
    return EXIT_SUCCESS;
}
