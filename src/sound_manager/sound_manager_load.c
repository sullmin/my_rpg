/*
** EPITECH PROJECT, 2019
** sound_manager
** File description:
** sound manager
*/

#include "sound_manager.h"

const char *FILE_SOUND[] =
{
    "walk.ogg",
    "theme_fantasy.ogg",
    "isow_theme.ogg",
    "success.ogg",
    "hit.ogg",
    "cloche.ogg",
    "battle.ogg",
    "menu_theme.ogg",
    NULL
};

static int sound_manager_alloc(sound_manager_t *sm)
{
    sm->sounds = malloc(sizeof(sfMusic *) * sm->size);
    if (sm->sounds == NULL) {
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

static int sound_manager_load_sound(sound_manager_t *sm, float volume,
const char *dirpath)
{
    char *filepath = NULL;

    for (size_t i = 0; i < (size_t)sm->size; i++) {
        filepath = my_str_concat(dirpath, FILE_SOUND[i]);
        if (!filepath)
            return EXIT_ERROR;
        sm->sounds[i] = sfMusic_createFromFile(filepath);
        if (sm->sounds[i] == NULL)
            return EXIT_ERROR;
        sfMusic_setVolume(sm->sounds[i], volume);
        free(filepath);
    }
    return EXIT_SUCCESS;
}

static void config_music_loop(sound_manager_t *sm)
{
    sound_manager_set_loop(sm, FANTASY_THEME, true);
    sound_manager_set_loop(sm, ISO_WORLD_THEME, true);
    sound_manager_set_loop(sm, BATTLE, true);
    sound_manager_set_loop(sm, MENU_THEME, true);
}

int sound_manager_load(sound_manager_t *sm, float volume, const char *dirpath,
bool show_loaded)
{
    for (sm->size = 0; FILE_SOUND[sm->size] != NULL; sm->size++);
    if (sm->size == 0)
        return EXIT_SUCCESS;
    if (sound_manager_alloc(sm) == EXIT_ERROR) {
        return my_puterror("sound_manager : malloc error\n", 84);
    }
    if (sound_manager_load_sound(sm, volume, dirpath) != 0) {
        sm->have_err = true;
        return my_puterror("sound_manager : load sound error\n", 84);
    }
    if (show_loaded)
        sound_manager_show_array(sm);
    sm->have_err = false;
    config_music_loop(sm);
    sm->file_list = NULL;
    return EXIT_SUCCESS;
}
