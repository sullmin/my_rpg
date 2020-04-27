/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_world_t
*/

#ifndef MAIN_WORLD_T_H_
#define MAIN_WORLD_T_H_

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect_init;
    sfIntRect rect;
    char **hitbox;
    sfVector2f position_player;
    sfVector2i position_on_map;
    int shift_rect;
    sfClock *clock;
    sfInt32 timer;
    sfInt32 ms_loop;
    sfVector2i size_map;
} main_world_t;

#endif /* !MAIN_WORLD_T_H_ */
