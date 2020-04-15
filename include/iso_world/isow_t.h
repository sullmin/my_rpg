/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** iso world
*/

#ifndef ISOW_T_H_
#define ISOW_T_H_

#include "map_t.h"
#include "object_t.h"

typedef struct iso_world {
    object_t player;
    map_t map;
    map_t map_water;
    sfClock *clock;
    sfInt32 timer;
    sfInt32 ms_loop;
} isow_t;

#endif
