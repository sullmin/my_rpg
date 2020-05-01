/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_world_t
*/

#ifndef MAIN_WORLD_T_H_
#define MAIN_WORLD_T_H_

#include "movement_t.h"
#include "sound_t.h"
#include "pnj_t.h"

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *spr_box;
    sfTexture *txt_box;
    sfIntRect rect_init;
    sfIntRect rect;
    sfView *view;
    int nb_zoom;
    char **hitbox;
    int shift_rect;
    sfClock *clock;
    sfInt32 timer;
    sfInt32 ms_loop;
    sfVector2i size_map;
    sfVector2i map_max_pos_rect;
    sfVector2i size_map_pixel;
    float zoom;
    sound_t *sound_effect;
    progress_t *bar;
    pnj_manage_t pnj_man;
    chara_animation_t player_move;
    sfVector2f position_on_map;
    sfVector2i pos_on_map_int;
    float shift_pos;
    bool is_player_move;
    enum direction move_dir;
    int xp;
    int lvl;
    sfSprite *player_hitbox_spr;
    sfTexture *player_hitbox_txr;
    sfVector2i player_hitbox_pos[4];
    particles_pack_t *effect[13];
} main_world_t;

#endif /* !MAIN_WORLD_T_H_ */
