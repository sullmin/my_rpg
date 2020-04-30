/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T12:20:15+02:00 | Author: simon
*/

#include "my_rpg.h"

const char *FILE_PNJ_DIALOGUE_END = "end.diag";
const char *FILE_PNJ_DIALOGUE_FAIL = "fail.diag";

const quest_t QUEST_ARRAY[NB_QUEST] =
{
    {
        .title = "STARTING QUEST",
        .text = "find the holy savonette and conquier the world",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'1', '1', '3', 0},
        .ref_item_end = {'1', '1', '1', 0},
        .max_duration = 0
    },
    {
        .title = "Get the guardian key",
        .text = "In order to open the door of the prison...",
        .file_pnj_dialogue = "getkey.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'1', '1', '3', 0},
        .ref_item_end = {'1', '1', '2', 0},
        .max_duration = 120000000
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "TEST",
        .text = "TEST",
        .file_pnj_dialogue = "start.diag",
        .type_reward = REW_ITEM,
        .reward_stat =
        {
            .agility = 0,
            .strength = 0,
            .speed = 0,
            .health = 0,
            .resistance = 0,
            .iq = 0
        },
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    }
};
