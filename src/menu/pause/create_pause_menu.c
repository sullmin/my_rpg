/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_pause_menu
*/

#include "my_rpg.h"

static const char *play_path[] = {
    "asset/sprite/buttons/play.png",
    "asset/sprite/buttons/play_h.png",
    "asset/sprite/buttons/play_c.png",
    NULL,
};

static const char *quit_path[] = {
    "asset/sprite/buttons/quit.png",
    "asset/sprite/buttons/quit_h.png",
    "asset/sprite/buttons/quit_c.png",
    NULL,
};

static const char *option_path[] = {
    "asset/sprite/buttons/option.png",
    "asset/sprite/buttons/option_h.png",
    "asset/sprite/buttons/option_c.png",
    NULL,
};

static const sfVector2f button_s = {300, 75};

static const sfVector2f button_p[3] = {
    {500, 400},
    {500, 500},
    {500, 600}
};

extern const char *font;

static int set_pause_menu_button(game_t *game)
{
    int ret = 0;

    ret += set_button_texture(game->pause->resume, play_path);
    ret += set_button_texture(game->pause->quit, quit_path);
    ret += set_button_texture(game->pause->main_menu, option_path);
    ret += set_button_label(game->pause->resume, "resume", font, 50);
    ret += set_button_label(game->pause->quit, "quit", font, 50);
    ret += set_button_label(game->pause->main_menu, "main menu", font, 50);
    return ret;
}

int create_pause_menu(game_t *game)
{
    game->pause = malloc(sizeof(pause_menu_t));
    if (game->pause == NULL)
        return EXIT_ERROR;
    game->pause->resume = create_button(button_p[0], button_s);
    game->pause->quit = create_button(button_p[1], button_s);
    game->pause->main_menu = create_button(button_p[2], button_s);
    if (!game->pause->resume || !game->pause->quit || !game->pause->main_menu)
        return EXIT_ERROR;
    if (set_pause_menu_button(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
