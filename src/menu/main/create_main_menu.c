/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_main_menu
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

static const char *help_path[] = {
    "asset/sprite/buttons/help.png",
    "asset/sprite/buttons/help_h.png",
    "asset/sprite/buttons/help_c.png",
    NULL,
};

static const sfVector2f button_s = {300, 75};

static const sfVector2f button_p[4] = {
    {500, 400},
    {500, 500},
    {500, 600},
    {500, 700}
};

static int set_main_menu_button(game_t *game)
{
    char *font = GET_VAR(game, "BASE_FONT");
    int ret = 0;

    if (!font)
        return EXIT_ERROR;
    ret += set_button_texture(MMENU->play, play_path);
    ret += set_button_texture(MMENU->quit, quit_path);
    ret += set_button_texture(MMENU->option, option_path);
    ret += set_button_texture(MMENU->help, help_path);
    ret += set_button_label(MMENU->play, "play", font, 50);
    ret += set_button_label(MMENU->quit, "quit", font, 50);
    ret += set_button_label(MMENU->option, "option", font, 50);
    ret += set_button_label(MMENU->help, "help", font, 50);
    free(font);
    return ret;
}

static int load_texture(game_t *game)
{
    char *path_back = GET_VAR(game, "MMAIN_BACK");

    if (!path_back)
        return EXIT_ERROR;
    MMENU->txr_background = sfTexture_createFromFile(path_back, NULL);
    MMENU->spr_background = sfSprite_create();
    if (MMENU->txr_background == NULL || !MMENU->spr_background) {
        return puterr("load main menu texture : fail\n", EXIT_ERROR);
    }
    sfSprite_setTexture(MMENU->spr_background, MMENU->txr_background, true);
    free(path_back);
    return EXIT_SUCCESS;
}

int create_main_menu(game_t *game)
{
    MMENU = malloc(sizeof(main_menu_t));
    if (game->menu == NULL)
        return EXIT_ERROR;
    MMENU->play = create_button(button_p[0], button_s);
    MMENU->quit = create_button(button_p[1], button_s);
    MMENU->option = create_button(button_p[2], button_s);
    MMENU->help = create_button(button_p[3], button_s);
    if (!MMENU->play || !MMENU->quit || !MMENU->option || !MMENU->help)
        return EXIT_ERROR;
    if (set_main_menu_button(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    else if (load_texture(game) == EXIT_ERROR) {
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
