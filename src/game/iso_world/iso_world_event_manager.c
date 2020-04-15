/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "my_rpg.h"

static void (* const EVENT_HANDLER[])(isow_t *, sfEvent *) =
{
    &event_mouse_button_pressed,
    &event_mouse_button_released,
    &event_mouse_wheel_scroll,
    &event_keypressed,
    &event_mouse_move,
};

static const sfEventType EVENT_TYPE[] =
{
    sfEvtMouseButtonPressed,
    sfEvtMouseButtonReleased,
    sfEvtMouseWheelScrolled,
    sfEvtKeyPressed,
    sfEvtMouseMoved,
};

static int EVENT_ARRAY_SIZE = 5;

void isow_event_manager(game_t *game, sfEvent *event)
{
    for (int i = 0; i < EVENT_ARRAY_SIZE; i++) {
        if (EVENT_TYPE[i] == event->type) {
            EVENT_HANDLER[i](&ISOW, event);
            break;
        }
    }
}
