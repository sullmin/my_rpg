/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-20T15:52:52+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const sfVector2i PLAYER_MOVEMENT[];

static int content_mode_move(game_t *game)
{
    int *i = &ISOW.kinem.idx_player_move;

    if (PLAYER_MOVEMENT[*i].x == 0 && PLAYER_MOVEMENT[*i].y == 0) {
        kinem_stop(game);
    }
    object_on_map_move(&ISOW.player, &ISOW.map, PLAYER_MOVEMENT[*i].x,
    PLAYER_MOVEMENT[*i].y);
    (*i)++;
    return EXIT_SUCCESS;
}

static int content_mode_angle(game_t *game)
{
    if (ISOW.kinem.curr_angle > ISOW.kinem.max_angle) {
        map_rotate(&ISOW.map, 0, ISOW.kinem.step_angle);
        map_rotate(&ISOW.map_water, 0, ISOW.kinem.step_angle);
        ISOW.kinem.curr_angle += ISOW.kinem.step_angle;
    } else {
        ISOW.kinem.mode = PLAYER_MOVE;
    }
    return EXIT_SUCCESS;
}

int kinem_run(game_t *game)
{
    ISOW.kinem.timer += TIME_MILLI(ISOW.clock);
    sfClock_restart(ISOW.clock);
    if (ISOW.kinem.timer >= ISOW.kinem.ms_loop) {
        while (ISOW.kinem.timer >= ISOW.kinem.ms_loop) {
            ISOW.kinem.timer -= ISOW.kinem.ms_loop;
        }
        if (ISOW.kinem.mode == ANGLE
                && content_mode_angle(game) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        } else if (ISOW.kinem.mode == PLAYER_MOVE
                && content_mode_move(game) != EXIT_SUCCESS) {
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}
