/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T09:26:46+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const quest_t QUEST_ARRAY[];

int sysquest_create(sys_quest_t *quests)
{
    quests->curr_quest_id = -1;
    quests->curr_diag_id = -1;
    quests->size = NB_QUEST;
    quests->size_enable = 0;
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
    return EXIT_SUCCESS;
}

void sysquest_destroy(sys_quest_t *quests)
{
    for (size_t i = 0; i < quests->size; i++) {
        dialogue_destroy(quests->pnj_dialogue[i]);
    }
    quests->size = 0;
}
