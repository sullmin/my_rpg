/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** iso world
*/

#ifndef ISOW_T_H_
#define ISOW_T_H_

#include "isow_map_t.h"
#include "object_t.h"

struct isow_event {
    sfKeyCode player_move_key;
    bool player_move;
};

typedef struct iso_world {
    struct isow_event event;
    object_t player;
    object_t prison;
    map_t map;
    map_t map_water;
    sfClock *clock;
    sfInt32 timer;
    sfInt32 ms_loop;
} isow_t;

#endif
