/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-15T09:13:14+02:00 | Author: simon
*/

#include "my_rpg.h"

int isow_destroy(isow_t *isow)
{
    object_destroy(&isow->player);
    object_destroy(&isow->prison);
    map_destroy(&isow->map);
    map_destroy(&isow->map_water);
    sfClock_destroy(isow->clock);
    kinem_destroy(isow);
    return EXIT_SUCCESS;
}
