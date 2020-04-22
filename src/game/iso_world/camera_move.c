/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-17T18:09:32+02:00 | Author: simon
*/

#include "my_rpg.h"

static const float SHIFT = 200;
static const int DIR_L = 0;
static const int DIR_R = 1;
static const int DIR_U = 2;
static const int DIR_D = 3;
static const int DIR_NO = 4;

static int check_move_camera(sfVector2f *player_coord, window_t *w)
{
    if (player_coord->x <= SHIFT) {
        return DIR_L;
    } else if (player_coord->y <= SHIFT) {
        return DIR_U;
    }
    if (w->width - player_coord->x <= SHIFT) {
        return DIR_R;
    } else if (w->height - player_coord->y <= SHIFT) {
        return DIR_D;
    }
    return DIR_NO;
}

static void apply_movement(int dir, isow_t *isow)
{
    float shiftx = 0;
    float shifty = 0;

    if (dir == DIR_R) {
        shiftx = -SHIFT;
    } else if (dir == DIR_U) {
        shifty = SHIFT;
    }
    if (dir == DIR_L) {
        shiftx = SHIFT;
    } else if (dir == DIR_D) {
        shifty = -SHIFT;
    }
    map_translate(&isow->map, shiftx, shifty);
    map_translate(&isow->map_water, shiftx, shifty);
}

void camera_move(isow_t *isow, window_t *w)
{
    int dir;

    dir = check_move_camera(&isow->player.mtx_2d[1][0][0], w);
    if (dir != DIR_NO) {
        apply_movement(dir, isow);
    }
}
