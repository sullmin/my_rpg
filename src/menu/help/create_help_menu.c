/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_help_menu
*/

#include "my_rpg.h"

static const char *return_path[] = {
    "asset/sprite/buttons/quit.png",
    "asset/sprite/buttons/quit_h.png",
    "asset/sprite/buttons/quit_c.png",
    NULL,
};
static const sfVector2f button_s = {300, 75};
static const sfVector2f button_p = {500, 400};
const char *filepath = "asset/sprite/man.jpg";
static const char *font = "asset/font/MADETOMMY.ttf";

static int load_help_img(game_t *game)
{
    MENU_HELP->spr_help = sfSprite_create();
    MENU_HELP->ter_help = sfTexture_createFromFile(filepath ,NULL);
    if (MENU_HELP->spr_help == NULL || MENU_HELP->ter_help == NULL)
        return EXIT_ERROR;
    sfSprite_setTexture(MENU_HELP->spr_help, MENU_HELP->ter_help, sfTrue);
    return EXIT_SUCCESS;
}

int create_help_menu(game_t *game)
{
    MENU_HELP = malloc(sizeof(help_menu_t));
    if (MENU_HELP == NULL)
        return EXIT_ERROR;
    MENU_HELP->main_menu = create_button(button_p, button_s);
    if (MENU_HELP->main_menu == NULL)
        return EXIT_ERROR;
    if (set_button_texture(MENU_HELP->main_menu, return_path) == EXIT_ERROR)
        return EXIT_ERROR;
    set_button_label(MENU_HELP->main_menu, "return", font, 50);
    if (load_help_img(game) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}