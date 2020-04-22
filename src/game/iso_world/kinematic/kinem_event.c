/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-21T10:09:27+02:00 | Author: simon
*/

#include "isow.h"

void kinem_event(isow_t *isow, sound_manager_t *sound, sfEvent *event)
{
    if (isow->kinem.start == false) {
        return;
    }
    if (event->type == sfEvtKeyReleased) {
        sound_manager_play(sound, CLOCHE);
        kinem_stop(isow, sound);
    }
}
