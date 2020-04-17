/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-15T15:22:40+02:00 | Author: simon
*/

#include "isow.h"

void event_object_move(isow_t *isow, sfEvent *event)
{
    if (event->key.code != sfKeyUp
        && event->key.code != sfKeyDown
        && event->key.code != sfKeyLeft
        && event->key.code != sfKeyRight) {
        return;
    }
    if (event->type == sfEvtKeyPressed) {
        isow->event.player_move = true;
        isow->event.player_move_key = event->key.code;
    } else if (event->type == sfEvtKeyReleased) {
        isow->event.player_move = false;
    }
}
