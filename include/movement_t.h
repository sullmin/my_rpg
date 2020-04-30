/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#ifndef MOVEM_T_H
#define MOVEM_T_H

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct chara_animation_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rec;
    sfClock *clock;
    sfInt32 timer;
    bool orient[4];
    bool in_move;
    bool is_static;
    int count;
} chara_animation_t;

#endif
