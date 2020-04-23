/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:06:24+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const char *font;

static const char *PATH_BACK = "asset/sprite/menu_quest_back.png";

static const sfVector2f BUTTON_POS = {1920 - 600, 150};
static const sfVector2f BUTTON_SIZE = {300, 75};

static const char *BUTTON_TXT[] = {
    "asset/sprite/buttons/quit.png",
    "asset/sprite/buttons/quit_h.png",
    "asset/sprite/buttons/quit_c.png",
    NULL,
};

static int create_background_texture(quest_menu_t *menu)
{
    menu->txr_background = sfTexture_createFromFile(PATH_BACK, NULL);
    menu->spr_background = sfSprite_create();
    if (menu->txr_background == NULL || !menu->spr_background) {
        return puterr("load quest menu texture : fail\n", EXIT_ERROR);
    }
    sfSprite_setTexture(menu->spr_background,
    menu->txr_background, true);
    return EXIT_SUCCESS;
}

int menu_quest_create(game_t *game)
{
    if (create_background_texture(&MENU_QUEST) != EXIT_SUCCESS) {
        return puterr("quest menu create\n", EXIT_ERROR);
    }
    MENU_QUEST.exit = create_button(BUTTON_POS, BUTTON_SIZE);
    if (!MENU_QUEST.exit)
        return puterr("quest menu create\n", EXIT_ERROR);
    if (set_button_texture(MENU_QUEST.exit, BUTTON_TXT) != 0)
        return puterr("quest menu create\n", EXIT_ERROR);
    set_button_label(MENU_QUEST.exit, "EXIT", font, 50);
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
