/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T10:05:35+02:00 | Author: simon
*/

#include "my_rpg.h"

void dialogue_play(sys_quest_t *quests, int id)
{
    if (quests->play_dialogue == true)
        return;
    if (id != IDX_DIALOGUE_END && id != IDX_DIALOGUE_FAIL && id < 0)
        return;
    else if (id >= (int)quests->size)
        return;
    if (id >= 0 && quests->pnj_dialogue[id] == NULL)
        return;
    if (id == IDX_DIALOGUE_END && quests->pnj_dialogue_end == NULL)
        return;
    if (id == IDX_DIALOGUE_FAIL && quests->pnj_dialogue_fail == NULL)
        return;
    quests->play_dialogue = true;
    quests->dialogue_id = id;
    quests->curr_sentence = NULL;
}
