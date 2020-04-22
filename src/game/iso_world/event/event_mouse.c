/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "isow.h"

void event_mouse_wheel_scroll(isow_t *isow, sfEvent *event, option_t *option)
{
    sfMouseWheelScrollEvent evt = event->mouseWheelScroll;

    option->volume = option->volume;
    map_scale_all(isow, evt.delta);
}
