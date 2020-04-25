/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#ifndef PNJ_T_H_
#define PNJ_T_H_

#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct pnj_s
{
    movement_t move;
    sfVector2i pos;
    sfClock *clock;
    bool sens;
} pnj_t;

#endif
