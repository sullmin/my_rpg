/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-20T15:52:52+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const sfVector2i PLAYER_MOVEMENT[];

static int content_mode_move(isow_t *isow, sound_manager_t *sound)
{
    int *i = &isow->kinem.idx_player_move;

    if (PLAYER_MOVEMENT[*i].x == 0 && PLAYER_MOVEMENT[*i].y == 0) {
        kinem_stop(isow, sound);
    }
    object_on_map_move(&isow->player, &isow->map, PLAYER_MOVEMENT[*i].x,
    PLAYER_MOVEMENT[*i].y);
    (*i)++;
    return EXIT_SUCCESS;
}

static int content_mode_angle(isow_t *isow)
{
    if (isow->kinem.curr_angle > isow->kinem.max_angle) {
        map_rotate(&isow->map, 0, isow->kinem.step_angle);
        map_rotate(&isow->map_water, 0, isow->kinem.step_angle);
        isow->kinem.curr_angle += isow->kinem.step_angle;
    } else {
        isow->kinem.mode = PLAYER_MOVE;
    }
    return EXIT_SUCCESS;
}

int kinem_run(isow_t *isow, sound_manager_t *sound)
{
    isow->kinem.timer += TIME_MILLI(isow->clock);
    sfClock_restart(isow->clock);
    if (isow->kinem.timer >= isow->kinem.ms_loop) {
        while (isow->kinem.timer >= isow->kinem.ms_loop) {
            isow->kinem.timer -= isow->kinem.ms_loop;
        }
        if (isow->kinem.mode == ANGLE
                && content_mode_angle(isow) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        } else if (isow->kinem.mode == PLAYER_MOVE
                && content_mode_move(isow, sound) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}
