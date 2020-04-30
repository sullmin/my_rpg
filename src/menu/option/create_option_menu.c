/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_option_menu
*/

#include "my_rpg.h"

static const char *PATH_BACK = "asset/sprite/option_menu_back.png";

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
    game->option_menu->sound = create_slider((sfVector2f){700, 730}, 500);
    if (create_option_menu_button(game) != EXIT_SUCCESS) {
        return EXIT_ERROR;
    }
    if (create_background_texture(game) != EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
