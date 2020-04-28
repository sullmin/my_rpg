/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool init_pnj(pnj_t *pnj)
{
    pnj->clock = sfClock_create();
    pnj->sens = true;
    pnj->pos.x = 66;
    pnj->pos.y = 32;
    if (!movement_creat(&pnj->move, "./asset/sprite/enemy.png"))
        return false;
    built_it(&pnj->move, 1);
    return true;
}

void destroy_pnj(pnj_t *pnj)
{
    sfClock_destroy(pnj->clock);
    destroy_movement(&pnj->move);
}