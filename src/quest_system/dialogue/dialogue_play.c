/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T10:05:35+02:00 | Author: simon
*/

#include "my_rpg.h"

void dialogue_play(sys_quest_t *quests, int id)
{
    if (id < 0) {

        return;
    } else if (quests->pnj_dialogue[id] == NULL) {
        return;
    }

}
