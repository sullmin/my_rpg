/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-28T17:53:56+02:00 | Author: simon
*/

#include "my_rpg.h"

static int load_texture(game_t *game)
{
    char *path_back = GET_VAR(game, "CREDIT_BACK");
    char *path_front = GET_VAR(game, "CREDIT_FRONT");

    if (!path_back || !path_front)
        return EXIT_ERROR;
    MENU_CREDIT.txr_front = sfTexture_createFromFile(path_front, NULL);
    MENU_CREDIT.txr_back = sfTexture_createFromFile(path_back, NULL);
    MENU_CREDIT.spr_back = sfSprite_create();
    MENU_CREDIT.spr_front = sfSprite_create();
    if (!MENU_CREDIT.txr_back || !MENU_CREDIT.txr_front) {
        return puterr("load credit menu texture : fail\n", EXIT_ERROR);
    }
    sfSprite_setTexture(MENU_CREDIT.spr_back, MENU_CREDIT.txr_back, true);
    sfSprite_setTexture(MENU_CREDIT.spr_front, MENU_CREDIT.txr_front, true);
    free(path_back);
    free(path_front);
    return EXIT_SUCCESS;
}

int credit_menu_create(game_t *game)
{
    bool err = false;

    MENU_CREDIT.pos_front = (sfVector2f) {0, (-game->w.height)};
    if (load_texture(game) != EXIT_SUCCESS) {
        return EXIT_ERROR;
    }
    MENU_CREDIT.clock = sfClock_create();
    MENU_CREDIT.timer = 0;
    MENU_CREDIT.ms_loop = GET_VAR_NBR(game, "CREDIT_CLOCK_MS", &err);
    MENU_CREDIT.shift_movement = GET_VAR_NBR(game, "CREDIT_SHIFT_MOVEMENT",
    &err);
    if (err == true) {
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

void credit_menu_destroy(game_t *game)
{
    sfSprite_destroy(MENU_CREDIT.spr_front);
    sfSprite_destroy(MENU_CREDIT.spr_back);
    sfTexture_destroy(MENU_CREDIT.txr_back);
    sfTexture_destroy(MENU_CREDIT.txr_front);
    sfClock_destroy(MENU_CREDIT.clock);
}
