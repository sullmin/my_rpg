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
    {800, 400},
    {800, 500},
    {800, 600}
};

static int set_pause_menu_button(game_t *game)
{
    int ret = 0;
    char *fontpath = GET_VAR(game, "BASE_FONT");

    if (!fontpath)
        return EXIT_ERROR;
    ret += set_button_texture(game->pause->resume, play_path);
    ret += set_button_texture(game->pause->quit, quit_path);
    ret += set_button_texture(game->pause->main_menu, option_path);
    ret += set_button_label(game->pause->resume, "resume", fontpath, 50);
    ret += set_button_label(game->pause->quit, "quit", fontpath, 50);
    ret += set_button_label(game->pause->main_menu, "main menu", fontpath, 50);
    free(fontpath);
    return ret;
}

static int create_pause_sprite(game_t *game)
{
    char *back_path = GET_VAR(game, "MPAUSE_BACK");

    if (!back_path)
        return EXIT_ERROR;
    game->pause->spr_screen = sfSprite_create();
    game->pause->txr_screen = sfTexture_createFromFile(back_path, NULL);
    if (game->pause->spr_screen == NULL || game->pause->txr_screen == NULL)
        return EXIT_ERROR;
    sfSprite_setTexture(game->pause->spr_screen, game->pause->txr_screen,
    sfTrue);
    free(back_path);
    return EXIT_SUCCESS;
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
    if (create_pause_sprite(game) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
