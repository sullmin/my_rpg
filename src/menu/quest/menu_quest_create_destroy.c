/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:06:24+02:00 | Author: simon
*/

#include "my_rpg.h"

static const sfVector2f BUTTON_POS = {1920 - 600, 150};
static const sfVector2f BUTTON_SIZE = {300, 75};

static const char *BUTTON_TXT[] = {
    "asset/sprite/buttons/quit.png",
    "asset/sprite/buttons/quit_h.png",
    "asset/sprite/buttons/quit_c.png",
    NULL,
};

static int create_background_texture(game_t *game, quest_menu_t *menu)
{
    char *path_back = GET_VAR(game, "QUEST_BACK");

    if (path_back == NULL)
        return EXIT_ERROR;
    menu->txr_background = sfTexture_createFromFile(path_back, NULL);
    menu->spr_background = sfSprite_create();
    if (menu->txr_background == NULL || !menu->spr_background) {
        return puterr("load quest menu texture : fail\n", EXIT_ERROR);
    }
    sfSprite_setTexture(menu->spr_background,
    menu->txr_background, true);
    free(path_back);
    return EXIT_SUCCESS;
}

int menu_quest_create(game_t *game)
{
    bool err = false;
    int max_display_quest = GET_VAR_NBR(game, "MQUEST_MAX_DISP", &err);
    char *fontpath = GET_VAR(game, "BASE_FONT");

    if (create_background_texture(game, &MENU_QUEST) != EXIT_SUCCESS || err) {
        return puterr("quest menu create\n", EXIT_ERROR);
    }
    MENU_QUEST.max_display = max_display_quest;
    MENU_QUEST.exit = create_button(BUTTON_POS, BUTTON_SIZE);
    if (!MENU_QUEST.exit || !fontpath)
        return puterr("quest menu create\n", EXIT_ERROR);
    if (set_button_texture(MENU_QUEST.exit, BUTTON_TXT) != 0)
        return puterr("quest menu create\n", EXIT_ERROR);
    set_button_label(MENU_QUEST.exit, "EXIT", fontpath, 50);
    MENU_QUEST.ui_size = 0;
    if (menu_quest_load(game) != EXIT_SUCCESS)
        return puterr("quest menu create\n", EXIT_ERROR);
    return EXIT_SUCCESS;
}

void menu_quest_destroy(game_t *game)
{
    sfTexture_destroy(MENU_QUEST.txr_background);
    sfSprite_destroy(MENU_QUEST.spr_background);
    destroy_button(MENU_QUEST.exit);
    menu_quest_unload(game);
}
