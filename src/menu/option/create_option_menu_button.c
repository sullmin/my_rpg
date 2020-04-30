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

static const char *CHARACTER1[] = {
    "asset/sprite/buttons/hero_icon.png",
    "asset/sprite/buttons/hero_icon_select.png",
    "asset/sprite/buttons/hero_icon_activ.png",
    NULL,
};

static const char *CHARACTER2[] = {
    "asset/sprite/buttons/hero2_icon.png",
    "asset/sprite/buttons/hero2_icon_select.png",
    "asset/sprite/buttons/hero2_icon_activ.png",
    NULL,
};

static const sfVector2f button_s = {300, 75};
static const sfVector2f button2_s = {96, 195};

static const sfVector2f keypad_s = {250, 166};

static const sfVector2f button_p[6] = {
    {100, 200},
    {100, 400},
    {100, 600},
    {1920 / 2 - 150, 180},
    {1920 - 370, 220},
    {1920 - 200, 220}
};

static int set_option_button(game_t *game)
{
    char *keypad_conf = GET_VAR(game, "DEFAULT_KEY");

    if (keypad_conf == NULL)
        return EXIT_ERROR;
    if (!my_strcmp(keypad_conf, "keypad"))
        game->option_menu->keypad->is_activate = true;
    if (!my_strcmp(keypad_conf, "azerty"))
        game->option_menu->azerty->is_activate = true;
    if (!my_strcmp(keypad_conf, "qwerty"))
        game->option_menu->qwerty->is_activate = true;
    free(keypad_conf);
    game->option_menu->chara1->is_activate = true;
    return EXIT_SUCCESS;
}

static int set_option_menu_button(game_t *game)
{
    char *label = "main menu";
    char *fontpath = GET_VAR(game, "BASE_FONT");
    int ret = 0;

    if (!fontpath)
        return EXIT_ERROR;
    ret += set_button_texture(game->option_menu->azerty, azerty_path);
    ret += set_button_texture(game->option_menu->qwerty, qwerty_path);
    ret += set_button_texture(game->option_menu->keypad, keypad_path);
    ret += set_button_texture(game->option_menu->main_menu, main_menu_path);
    ret += set_button_label(game->option_menu->main_menu, label, fontpath, 50);
    ret += set_button_texture(game->option_menu->chara1, CHARACTER1);
    ret += set_button_texture(game->option_menu->chara2, CHARACTER2);
    if (set_option_button(game) == EXIT_ERROR)
        return EXIT_ERROR;
    free(fontpath);
    return ret;
}

static void update_button_state(game_t *game)
{
    event_azerty_button(game);
    event_qwerty_button(game);
    event_keypad_button(game);
}

int create_option_menu_button(game_t *game)
{
    game->option_menu->azerty = create_button(button_p[0], keypad_s);
    game->option_menu->qwerty = create_button(button_p[1], keypad_s);
    game->option_menu->keypad = create_button(button_p[2], keypad_s);
    game->option_menu->main_menu = create_button(button_p[3], button_s);
    game->option_menu->chara1 = create_button(button_p[4], button2_s);
    game->option_menu->chara2 = create_button(button_p[5], button2_s);
    if (game->option_menu->azerty == NULL || !game->option_menu->qwerty
        || !game->option_menu->keypad || !game->option_menu->main_menu
        || !game->option_menu->chara1 || !game->option_menu->chara2)
        return EXIT_ERROR;
    if (set_option_menu_button(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    update_button_state(game);
    return EXIT_SUCCESS;
}
