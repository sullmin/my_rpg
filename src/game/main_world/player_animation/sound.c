/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include <SFML/Audio/SoundBuffer.h>
#include "my_rpg.h"

static sound_t create_sound(char *filepath)
{
    sound_t my_sound = {NULL, NULL, NULL};

    my_sound.sound = sfSound_create();
    if (my_sound.sound == NULL)
        return my_sound;
    my_sound.clock = sfClock_create();
    my_sound.buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(my_sound.sound, my_sound.buffer);
    return my_sound;
}

static void sound_destroy(sound_t *sound)
{
    sfClock_destroy(sound->clock);
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
}

void sound_effect_set_volume(game_t *game)
{
    for (size_t i = 0; WMAIN->sound_effect[i].sound; i++)
        sfSound_setVolume(WMAIN->sound_effect[i].sound, OPTION->volume);
}

bool load_sound_effect(game_t *game)
{
    size_t size = 3;
    char *name[] = {"./asset/sound/effect/door.ogg",
                    "./asset/sound/effect/walk.ogg",
                    "./asset/sound/effect/lock.ogg"};

    WMAIN->sound_effect = malloc(sizeof(sound_t) * (size + 1));
    if (!WMAIN->sound_effect)
        return false;
    WMAIN->sound_effect[size].sound = NULL;
    for (size_t i = 0; i < size; i++) {
        WMAIN->sound_effect[i] = create_sound(name[i]);
        if (!WMAIN->sound_effect[i].sound)
            return false;
    }
    update_map_position(game);
    return true;
}

void destroy_sound_effect(game_t *game)
{
    for (size_t i = 0; WMAIN->sound_effect[i].sound; i++) {
        sound_destroy(&WMAIN->sound_effect[i]);
    }
    free(WMAIN->sound_effect);
}