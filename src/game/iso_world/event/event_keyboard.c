/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "isow.h"

void event_keypressed(isow_t *isow, sfEvent *event, option_t *option)
{
    event_object_move(isow, event, option);
}

void event_keyreleased(isow_t *isow, sfEvent *event, option_t *option)
{
    event_object_move(isow, event, option);
}
