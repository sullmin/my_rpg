/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-15T15:22:40+02:00 | Author: simon
*/

#include "isow.h"

static void begin_move(isow_t *isow, sfEvent *event)
{
    if (event->key.code == sfKeyUp || event->key.code == sfKeyDown) {
        isow->event.player_move = true;
        isow->event.player_move_key_v = event->key.code;
    } else if (event->key.code == sfKeyLeft
            || event->key.code == sfKeyRight) {
        isow->event.player_move = true;
        isow->event.player_move_key_h = event->key.code;
    }
}

static void stop_move(isow_t *isow, sfEvent *event)
{
    if (event->key.code == sfKeyUp || event->key.code == sfKeyDown) {
        isow->event.player_move_key_v = 0;
    } else if (event->key.code == sfKeyLeft
            || event->key.code == sfKeyRight) {
        isow->event.player_move_key_h = 0;
    }
    if (isow->event.player_move_key_v == 0
        && isow->event.player_move_key_h == 0) {
        isow->event.player_move = false;
    }
}

void event_object_move(isow_t *isow, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        begin_move(isow, event);
    } else if (event->type == sfEvtKeyReleased) {
        stop_move(isow, event);
    }
}
