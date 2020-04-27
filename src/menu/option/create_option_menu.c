/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_option_menu
*/

#include "my_rpg.h"

static const char *azerty_path[] = {
    "asset/sprite/buttons/azerty.png",
    "asset/sprite/buttons/azerty_hoover.png",
    "asset/sprite/buttons/azerty_clicked.png",
    NULL,
};

static const char *qwerty_path[] = {
    "asset/sprite/buttons/qwerty.png",
    "asset/sprite/buttons/qwerty_hoover.png",
    "asset/sprite/buttons/qwerty_clicked.png",
    NULL,
};

static const char *keypad_path[] = {
    "asset/sprite/buttons/keypad.png",
    "asset/sprite/buttons/keypad_hoover.png",
    "asset/sprite/buttons/keypad_clicked.png",
    NULL,
};

static const char *main_menu_path[] = {
    "asset/sprite/buttons/quit.png",
    "asset/sprite/buttons/quit_h.png",
    "asset/sprite/buttons/quit_c.png",
    NULL,
};

static const sfVector2f button_s = {300, 75};

static const sfVector2f keypad_s = {250, 166};

static const sfVector2f button_p[4] = {
    {100, 200},
    {100, 400},
    {100, 600},
    {1920 / 2 - 150, 180},
};

extern const char *font;

static const char *PATH_BACK = "asset/sprite/option_menu_back.png";

static int set_option_menu_button(game_t *game)
{
    char *label = "main menu";
    int ret = 0;

    ret += set_button_texture(game->option_menu->azerty, azerty_path);
    ret += set_button_texture(game->option_menu->qwerty, qwerty_path);
    ret += set_button_texture(game->option_menu->keypad, keypad_path);
    ret += set_button_texture(game->option_menu->main_menu, main_menu_path);
    ret += set_button_label(game->option_menu->main_menu, label, font, 50);
    game->option_menu->keypad->is_activate = true;
    return ret;
}

static void update_button_state(game_t *game)
{
    event_azerty_button(game);
    event_qwerty_button(game);
    event_keypad_button(game);
}

static int create_background_texture(game_t *game)
{
    MENU_OPTION->txr_background = sfTexture_createFromFile(PATH_BACK, NULL);
    MENU_OPTION->spr_background = sfSprite_create();
    if (MENU_OPTION->txr_background == NULL || !MENU_OPTION->spr_background) {
        return puterr("load option menu texture : fail\n", EXIT_ERROR);
    }
    sfSprite_setTexture(MENU_OPTION->spr_background,
    MENU_OPTION->txr_background, true);
    return EXIT_SUCCESS;
}

int create_option_menu(game_t *game)
{
    game->option_menu = malloc(sizeof(option_menu_t));
    game->option = malloc(sizeof(option_t));
    game->option->move = malloc(sizeof(move_t));
    if (!game->option_menu || !game->option || !game->option->move)
        return EXIT_ERROR;
    game->option_menu->azerty = create_button(button_p[0], keypad_s);
    game->option_menu->qwerty = create_button(button_p[1], keypad_s);
    game->option_menu->keypad = create_button(button_p[2], keypad_s);
    game->option_menu->main_menu = create_button(button_p[3], button_s);
    game->option_menu->sound = create_slider((sfVector2f){700, 730}, 500);
    if (game->option_menu->azerty == NULL || !game->option_menu->qwerty
        || !game->option_menu->keypad || !game->option_menu->main_menu)
        return EXIT_ERROR;
    if (set_option_menu_button(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    update_button_state(game);
    if (create_background_texture(game) != EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
