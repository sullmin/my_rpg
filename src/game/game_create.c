/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:30:25+01:00 | Author: simon
*/

#include "my_rpg.h"

extern const int keypad[];
extern const int azerty[];
extern const int qwerty[];

static int game_init_struct(game_t *game)
{
    game->state = MAIN_MENU;
    game->prev_state = QUIT;
    game->submenu = NO_MENU;
    game->debug_mode = false;
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
    char *keypad_conf = NULL;
    bool err = false;
    int volume = GET_VAR_NBR(game, "DEF_VOLUME", &err);

    if (err)
        return EXIT_ERROR;
    OPTION->volume = (float)volume;
    set_slider_position(game->option_menu->sound, OPTION->volume);
    keypad_conf = GET_VAR(game, "DEFAULT_KEY");
    if (keypad_conf == NULL)
        return EXIT_ERROR;
    if (!my_strcmp(keypad_conf, "keypad"))
        set_keyboard_config(OPTION, keypad);
    if (!my_strcmp(keypad_conf, "azerty"))
        set_keyboard_config(OPTION, azerty);
    if (!my_strcmp(keypad_conf, "qwerty"))
        set_keyboard_config(OPTION, qwerty);
    free(keypad_conf);
    return EXIT_SUCCESS;
}

int game_create(game_t *game)
{
    char *help_path = GET_VAR(game, "MHELP_BACK");

    game->clock = sfClock_create();
    if (!game->clock || !help_path)
        return EXIT_ERROR;
    if (load_sound_manager(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (game_init_struct(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (isow_create(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (init_option(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (image_viewer_create(&game->help_popup, help_path, "HELP BOX") != 0)
        return EXIT_ERROR;
    free(help_path);
    set_game_state(game, MAIN_MENU);
    return EXIT_SUCCESS;
}
