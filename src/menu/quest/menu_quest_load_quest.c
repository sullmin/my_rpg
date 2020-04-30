/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:06:24+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const quest_t QUEST_ARRAY[];

static const sfVector2f INIT_POSITION = {320, 250};
static const sfVector2f SIZE = {1000, 80};
static const float POS_Y_SHIFT = 10;
static const sfColor COLOR_RECT_ACTIVE = {10, 10, 10, 180};
static const sfColor COLOR_RECT_FINISH = {255, 225, 255, 200};
static const sfColor COLOR_TEXT = {255, 255, 255, 255};

static int create_text(sfText **txt, game_t *game, const char *label,
sfVector2f position)
{
    bool err = false;
    int char_size = GET_VAR_NBR(game, "QUEST_CHAR_SIZE", &err);

    *txt = sfText_create();
    if (!(*txt) || err)
        return EXIT_ERROR;
    sfText_setCharacterSize(*txt, char_size);
    sfText_setColor(*txt, COLOR_TEXT);
    sfText_setFont(*txt, QUEST.font);
    sfText_setPosition(*txt, position);
    sfText_setString(*txt, label);
    return EXIT_SUCCESS;
}

static int load_element(quest_ui_t *el, game_t *game, size_t quest_id,
bool is_active)
{
    sfVector2f pos_title = {el->position.x + 30, el->position.y + 5};
    sfVector2f pos_desc = {el->position.x + 10, el->position.y + 50};

    el->back = sfRectangleShape_create();
    if (!el->back)
        return EXIT_ERROR;
    if (is_active)
        sfRectangleShape_setFillColor(el->back, COLOR_RECT_ACTIVE);
    else
        sfRectangleShape_setFillColor(el->back, COLOR_RECT_FINISH);
    sfRectangleShape_setPosition(el->back, el->position);
    sfRectangleShape_setSize(el->back, SIZE);
    if (create_text(&el->title, game, QUEST_ARRAY[quest_id].title,
            pos_title) != EXIT_SUCCESS) {
        return EXIT_ERROR;
    }
    if (create_text(&el->description, game, QUEST_ARRAY[quest_id].text,
                                            pos_desc) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int create_ui_element(game_t *game)
{
    sfVector2f position = INIT_POSITION;
    size_t idx = 0;

    for (size_t i = 0; i < NB_QUEST; i++) {
        if (!QUEST.is_active[i] && !QUEST.is_finish[i])
            continue;
        MENU_QUEST.ui_element[idx].position = position;
        if (load_element(&MENU_QUEST.ui_element[idx], game, i,
                QUEST.is_active[i]) != 0)
            return EXIT_ERROR;
        position.y += (SIZE.y + POS_Y_SHIFT);
        idx++;
    }
    return EXIT_SUCCESS;
}

int menu_quest_load(game_t *game)
{
    size_t size = 0;

    for (size_t i = 0; i < NB_QUEST; i++) {
        if (QUEST.is_active[i] || QUEST.is_finish[i]) {
            size++;
        }
    }
    if (size == 0) {
        MENU_QUEST.ui_size = 0;
        return EXIT_SUCCESS;
    }
    MENU_QUEST.ui_element = malloc(sizeof(quest_ui_t) * size);
    if (!MENU_QUEST.ui_element)
        return EXIT_ERROR;
    MENU_QUEST.ui_size = size;
    if (create_ui_element(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

void menu_quest_unload(game_t *game)
{
    for (size_t i = 0; i < MENU_QUEST.ui_size; i++) {
        sfRectangleShape_destroy(MENU_QUEST.ui_element[i].back);
        sfText_destroy(MENU_QUEST.ui_element[i].title);
        sfText_destroy(MENU_QUEST.ui_element[i].description);
    }
    MENU_QUEST.ui_size = 0;
}
