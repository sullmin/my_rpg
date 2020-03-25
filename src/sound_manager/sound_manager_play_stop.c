/*
** EPITECH PROJECT, 2019
** sound_manager
** File description:
** sound manager
*/

#include "sound_manager.h"

void sound_manager_play(sound_manager_t *sm, int id_sound)
{
    if (id_sound < 0 || id_sound >= sm->size) {
        my_putstr_error("ERROR: sound_manager_play : invalid sound id.\n");
        return;
    }
    sfMusic_stop(sm->sounds[id_sound]);
    sfMusic_play(sm->sounds[id_sound]);
}

void sound_manager_stop(sound_manager_t *sm, int id_sound)
{
    if (id_sound < 0 || id_sound >= sm->size) {
        my_putstr_error("ERROR: sound_manager_stop : invalid sound id.\n");
        return;
    }
    sfMusic_stop(sm->sounds[id_sound]);
}

void sound_manager_stop_all(sound_manager_t *sm)
{
    for (ssize_t i = 0; i < sm->size; i++) {
        sound_manager_stop(sm, i);
    }
}
