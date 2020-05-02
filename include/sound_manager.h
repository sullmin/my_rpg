/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** header
*/

#ifndef H_SOUND
#define H_SOUND

#include <SFML/Audio.h>
#include <stdlib.h>

#include "my.h"

enum sounds {
    WALK = 0,
    FANTASY_THEME = 1,
    ISO_WORLD_THEME = 2,
    SUCCESS = 3,
    HIT = 4,
    CLOCHE = 5,
    BATTLE = 6,
    MENU_THEME = 7
};

typedef struct sound_manager {
    int size;
    file_list_t *file_list;
    sfMusic **sounds;
    bool have_err;
} sound_manager_t;

void sound_manager_destroy(sound_manager_t *sm);
int sound_manager_create(sound_manager_t *sm, float volume,
const char *dirpath, bool show_loaded);
int sound_manager_load(sound_manager_t *sm, float volume, const char *dirpath,
bool show_loaded);

void sound_manager_play(sound_manager_t *sm, int id_sound);
void sound_manager_stop(sound_manager_t *sm, int id_sound);
void sound_manager_stop_all(sound_manager_t *sm);

void sound_manager_show_list(sound_manager_t *sm);
void sound_manager_show_array(sound_manager_t *sm);

sfMusic *sound_manager_get(sound_manager_t *sm, int id);
int sound_manager_set_loop(sound_manager_t *sm, int id, bool state);
int sound_manager_set_volume(sound_manager_t *sm, float volume);

#endif
