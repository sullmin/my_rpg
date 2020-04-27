/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_world_t
*/

#ifndef MAIN_WORLD_T_H_
#define MAIN_WORLD_T_H_

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
    char **hitbox;
    sfSprite *s_player;
    sfTexture *t_player;
    sfVector2f position_player;
    sfVector2i position_on_map;
    float zoom;
}main_world_t;

#endif /* !MAIN_WORLD_T_H_ */
