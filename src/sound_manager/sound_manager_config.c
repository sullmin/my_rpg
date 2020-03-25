/*
** EPITECH PROJECT, 2020
** sound_manager
** File description:
** Created: 2020-03-25T19:13:50+01:00 | Author: simon
*/

#include "sound_manager.h"

int sound_manager_set_volume(sound_manager_t *sm, float volume)
{
    for (ssize_t i = 0; i < sm->size; i++) {
        sfMusic_setVolume(sm->sounds[i], volume);
    }
    return EXIT_SUCCESS;
}

int sound_manager_set_loop(sound_manager_t *sm, int id, bool state)
{
    if (id < 0 || id >= sm->size) {
        return EXIT_ERROR;
    }
    sfMusic_setLoop(sm->sounds[id], state);
    return EXIT_SUCCESS;
}

sfMusic *sound_manager_get(sound_manager_t *sm, int id)
{
    if (id < 0 || id >= sm->size) {
        return NULL;
    }
    return sm->sounds[id];
}
