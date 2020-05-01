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
    chara_animation_t move;
    sfVector2i pos;
    sfClock *clock;
    sfVector2i fpos;
    bool is_hostile;
    bool go_act;
    sfInt32 timer;
    sfInt32 ms_loop;
} pnj_t;

typedef struct pnj_manage_s
{
    pnj_t *all_pnj;
    size_t nb_pnj;
    bool activate;
} pnj_manage_t;

typedef struct pnj_plan {
    sfVector2i position;
    const char *path_sprite;
    bool is_hostile;
} pnj_plan_t;

#endif
