/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T12:20:15+02:00 | Author: simon
*/

#include "my_rpg.h"

const quest_t QUEST_ARRAY[NB_QUEST] =
{
    {
        .id = ['A', 'A', 'A', 0],
        .title = "QUEST A TITLE",
        .text = "description of the quest",
        .is_active = false,
        .file_pnj_dialogue = "diag1",
        .type_reward = REW_STAT,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = ['x', 'x', 'x', 0],
        .time_begin = {0},
        .max_duration = 0,
        .ref_item_end = ['x', 'x', 'x', 0]
    }
};
