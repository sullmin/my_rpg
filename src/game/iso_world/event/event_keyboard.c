/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "isow.h"

void event_keypressed(isow_t *isow, sfEvent *event)
{
    event_object_move(isow, event);
}

void event_keyreleased(isow_t *isow, sfEvent *event)
{
    event_object_move(isow, event);
}
