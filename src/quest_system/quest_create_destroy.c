/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T09:26:46+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const quest_t QUEST_ARRAY[];
extern const char *FILE_PNJ_DIALOGUE_END;
extern const char *FILE_PNJ_DIALOGUE_FAIL;

static const sfColor BACK_COLOR = {30, 30, 30, 255};
static const float BACK_OUTLINE = 4.0f;
static const sfColor TEXT_COLOR = {255, 255, 255, 255};
static const unsigned int TEXT_SIZE = 20;
static const char *FONT_FILEPATH = "./asset/font/MADETOMMY.ttf";

static int load_gui_elements(sys_quest_t *sysquest)
{
    sysquest->back = sfRectangleShape_create();
    sysquest->text = sfText_create();
    sysquest->font = sfFont_createFromFile(FONT_FILEPATH);
    if (!sysquest->back || !sysquest->text || !sysquest->font)
        return EXIT_ERROR;
    sfRectangleShape_setFillColor(sysquest->back, BACK_COLOR);
    sfRectangleShape_setOutlineThickness(sysquest->back, BACK_OUTLINE);
    sfText_setColor(sysquest->text, TEXT_COLOR);
    sfText_setFont(sysquest->text, sysquest->font);
    sfText_setCharacterSize(sysquest->text, TEXT_SIZE);
    return EXIT_SUCCESS;
}

static int load_dialogues(sys_quest_t *quests)
{
    for (size_t i = 0; i < quests->size; i++) {
        quests->is_active[i] = false;
        quests->time_begin[i] = 0;
        if (QUEST_ARRAY[i].file_pnj_dialogue == NULL) {
            quests->pnj_dialogue[i] = NULL;
        } else if (dialogue_load(&quests->pnj_dialogue[i],
                QUEST_ARRAY[i].file_pnj_dialogue) == EXIT_ERROR) {
            return EXIT_ERROR;
        }
    }
    if (dialogue_load(&quests->pnj_dialogue_end, FILE_PNJ_DIALOGUE_END) != 0)
        return EXIT_ERROR;
    if (dialogue_load(&quests->pnj_dialogue_end, FILE_PNJ_DIALOGUE_FAIL) != 0)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int sysquest_create(sys_quest_t *quests)
{
    quests->play_dialogue = false;
    quests->dialogue_id = -1;
    quests->size = NB_QUEST;
    quests->size_enable = 0;
    if (load_dialogues(quests) == EXIT_ERROR)
        return puterr("sysquest_create : fail load dialogues\n", EXIT_ERROR);
    if (load_gui_elements(quests) == EXIT_ERROR)
        return puterr("sysquest_create : fail load gui elements\n", 84);
    return EXIT_SUCCESS;
}

void sysquest_destroy(sys_quest_t *quests)
{
    if (!quests)
        return;
    for (size_t i = 0; i < quests->size; i++) {
        dialogue_destroy(quests->pnj_dialogue[i]);
    }
    quests->size = 0;
    quests->play_dialogue = false;
    sfText_destroy(quests->text);
    sfRectangleShape_destroy(quests->back);
    sfFont_destroy(quests->font);
}
