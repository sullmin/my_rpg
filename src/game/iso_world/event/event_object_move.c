/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-15T15:22:40+02:00 | Author: simon
*/

#include "isow.h"

void event_object_move(isow_t *isow, sfEvent *event)
{
    if (event->key.code == sfKeyI)
        object_on_map_move(&isow->player, &isow->map, 0, -1);
    if (event->key.code == sfKeyK)
        object_on_map_move(&isow->player, &isow->map, 0, 1);
    if (event->key.code == sfKeyJ)
        object_on_map_move(&isow->player, &isow->map, -1, 0);
    if (event->key.code == sfKeyL)
        object_on_map_move(&isow->player, &isow->map, 1, 0);
}
