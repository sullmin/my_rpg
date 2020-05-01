/*
** EPITECH PROJECT, 2019
** sound_manager
** File description:
** sound manager
*/

#include "sound_manager.h"

static int sound_manager_alloc(sound_manager_t *sm)
{
    sm->sounds = malloc(sizeof(sfMusic *) * sm->size);
    if (sm->sounds == NULL) {
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

static int sound_manager_load_sound(sound_manager_t *sm, file_list_t *list,
float volume, const char *dirpath)
{
    char *filename = NULL;
    char *filepath = NULL;
    size_t i = 0;

    do {
        filename = my_file_list_read(list);
        if (!filename)
            break;
        filepath = my_str_concat(dirpath, filename);
        if (!filepath)
            return EXIT_ERROR;
        sm->sounds[i] = sfMusic_createFromFile(filepath);
        if (sm->sounds[i] == NULL)
            return EXIT_ERROR;
        sfMusic_setVolume(sm->sounds[i], volume);
        i++;
        free(filepath);
    } while (filename != NULL);
    return EXIT_SUCCESS;
}

static void config_music_loop(sound_manager_t *sm)
{
    sound_manager_set_loop(sm, FANTASY_THEME, true);
    sound_manager_set_loop(sm, ISO_WORLD_THEME, true);
    sound_manager_set_loop(sm, BATTLE, true);
    sound_manager_set_loop(sm, MENU_THEME, true);
}

int sound_manager_create(sound_manager_t *sm, float volume, const char *dirpath,
bool show_loaded)
{
    sm->size = my_read_dir(&sm->file_list, dirpath);
    if (sm->size == 0)
        return EXIT_SUCCESS;
    if (sm->size == -1) {
        sm->have_err = true;
        return my_puterror("sound_manager : sound filenames ERR\n", 84);
    } else if (sound_manager_alloc(sm) == EXIT_ERROR) {
        return my_puterror("sound_manager : malloc error\n", 84);
    }
    if (sound_manager_load_sound(sm, sm->file_list, volume, dirpath) != 0) {
        sm->have_err = true;
        return my_puterror("sound_manager : load sound error\n", 84);
    }
    if (show_loaded) {
        sound_manager_show_list(sm);
        sm->have_err = false;
    }
    config_music_loop(sm);
    return EXIT_SUCCESS;
}

void sound_manager_destroy(sound_manager_t *sm)
{
    if (!sm || sm->have_err)
        return;
    for (int i = 0; i < sm->size; i++) {
        if (sm->sounds[i]) {
            sfMusic_destroy(sm->sounds[i]);
        }
    }
    free(sm->sounds);
    my_file_list_destroy(sm->file_list);
}
