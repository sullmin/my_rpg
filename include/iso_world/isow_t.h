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
#include "particles.h"

struct isow_event {
    sfKeyCode player_move_key_h;
    sfKeyCode player_move_key_v;
    bool player_move;
};

enum kinem_mode {
    ANGLE,
    PLAYER_MOVE
};

struct kinematic {
    enum kinem_mode mode;
    float curr_angle;
    float step_angle;
    float start_angle;
    float max_angle;
    sfInt32 timer;
    sfInt32 ms_loop;
    int id_music;
    int idx_player_move;
    sfVector2i player_start_pos;
    float scale;
    bool start;
};

typedef struct iso_world {
    struct isow_event event;
    struct kinematic kinem;
    object_t player;
    object_t prison;
    map_t map;
    map_t map_water;
    sfClock *clock;
    sfInt32 timer;
    sfInt32 ms_loop;
    particles_pack_t *sand;
} isow_t;

#endif
