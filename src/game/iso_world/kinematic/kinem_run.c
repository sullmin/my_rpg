/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-20T15:52:52+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const sfVector2i PLAYER_MOVEMENT[];

static int content_mode_angle(isow_t *isow, sound_manager_t *sound)
{
    if (isow->kinem.curr_angle < isow->kinem.max_angle) {
        map_rotate(&isow->map, 0, isow->kinem.step_angle);
        isow->kinem.curr_angle += isow->kinem.step_angle;
    } else {
        kinem_stop(isow, sound);
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
        if (content_mode_angle(isow, sound) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}
