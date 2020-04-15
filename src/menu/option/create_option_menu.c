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
    {100, 0},
    {100, 400},
    {100, 800},
    {500, 600},
};

extern const char *font;

static int set_option_menu_button(game_t *game)
{
    char *label = "main menu";
    int ret = 0;

    ret += set_button_texture(game->option_menu->azerty, azerty_path);
    ret += set_button_texture(game->option_menu->qwerty, qwerty_path);
    ret += set_button_texture(game->option_menu->keypad, keypad_path);
    ret += set_button_texture(game->option_menu->main_menu, main_menu_path);
    ret += set_button_label(game->option_menu->main_menu, label, font, 50);
    game->option_menu->azerty->is_activate = true;
    return ret;
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
    game->option_menu->sound = create_slider((sfVector2f){500, 500}, 500);
    if (game->option_menu->azerty == NULL || !game->option_menu->qwerty
        || !game->option_menu->keypad || !game->option_menu->main_menu)
        return EXIT_ERROR;
    if (set_option_menu_button(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
