/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_rpg.h"

EVENT_HANDLER array[] = {
    &event_mouse_wheel_scroll,
    &event_keypressed,
    &event_keyreleased,
};

static const EVENT_TYPE event_type[] = {
    sfEvtMouseWheelScrolled,
    sfEvtKeyPressed,
    sfEvtKeyReleased,
};

static const int EVENT_ARRAY_SIZE = 3;

void isow_event_manager(game_t *game, sfEvent *event)
{
    if (ISOW.kinem.start == true) {
        kinem_event(game, event);
        return;
    }
    for (int i = 0; i < EVENT_ARRAY_SIZE; i++) {
        if (event_type[i] == event->type) {
            array[i](&ISOW, event, OPTION);
            break;
        }
    }
}
