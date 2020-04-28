/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-20T15:52:52+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const sfVector2f MAP_INIT_ANGL;

static const float START_ANGLE = 50;
static const float STEP_ANGLE = -1;

static const int ID_MUSIC = MUSIC1;

static const sfInt32 MS_LOOP = 300;

static const float SCALE = -15;

const sfVector2i PLAYER_MOVEMENT[] =
{
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -2},
    {-1, -2},
    {-1, -2},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, -1},
    {-1, -1},
    {-1, -1},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {-1, 0},
    {0, 0}
};

static const sfVector2i PLAYER_START = {60, 60};

int kinem_create(isow_t *isow)
{
    isow->kinem.start_angle = START_ANGLE;
    isow->kinem.step_angle = STEP_ANGLE;
    isow->kinem.max_angle = MAP_INIT_ANGL.y;
    isow->kinem.ms_loop = MS_LOOP;
    isow->kinem.id_music = ID_MUSIC;
    isow->kinem.start = false;
    isow->kinem.player_start_pos = PLAYER_START;
    isow->kinem.scale = SCALE;
    return EXIT_SUCCESS;
}

int kinem_destroy(isow_t *isow)
{
    isow->kinem.start = false;
    return EXIT_SUCCESS;
}
