/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:30:25+01:00 | Author: simon
*/

#include "my_rpg.h"

extern const int azerty[];

static int game_init_struct(game_t *game)
{
    set_game_state(game, MAIN_MENU);
    game->prev_state = QUIT;
    game->submenu = NO_MENU;
    return EXIT_SUCCESS;
}

static int load_sound_manager(game_t *game)
{
    bool err = false;
    float volume = GET_VAR_DEC(game, "DEF_VOLUME", &err);
    char *dirpath = GET_VAR(game, "DIR_SOUNDS");

    if (err) {
        return my_puterror("game_create: fail get volume\n", EXIT_ERROR);
    }
    if (volume < 0 || volume > 100) {
        return my_puterror("game_create: volume invalid\n", EXIT_ERROR);
    }
    if (sound_manager_create(&game->sound, volume, dirpath, true) != 0)
        return my_puterror("game_create: sound_manager ERROR\n", EXIT_ERROR);
    free(dirpath);
    return EXIT_SUCCESS;
}

static int init_option(game_t *game)
{
    bool err = false;
    int volume = GET_VAR_NBR(game, "DEF_VOLUME", &err);

    if (err)
        return EXIT_ERROR;
    OPTION->volume = (float)volume;
    set_slider_position(game->option_menu->sound, OPTION->volume);
    set_keyboard_config(OPTION, azerty);
    return EXIT_SUCCESS;
}

int game_create(game_t *game)
{
    game->clock = sfClock_create();
    if (!game->clock)
        return EXIT_ERROR;
    if (load_sound_manager(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (game_init_struct(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (isow_create(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (init_option(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
