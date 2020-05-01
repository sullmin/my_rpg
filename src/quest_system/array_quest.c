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
        .title = "[I] Un lieu inconne",
        .text = "Trouvez comment vous echapper de ce lieu",
        .file_pnj_dialogue = "m1.diag",
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
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "[II] Sur le chemin de la vangeance",
        .text = "Parlez a votre voisin de cellule",
        .file_pnj_dialogue = "m2.diag",
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
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "[III] Le debut de la liberte",
        .text = "Cherchez la cle dans les toilettes et sortez de la cellule",
        .file_pnj_dialogue = "m3.diag",
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
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'1', '1', '2', 0},
        .max_duration = 0
    },
    {
        .title = "[IV] Le debut de la liberte II",
        .text = "Tabasser le gardien et volez lui sa cle",
        .file_pnj_dialogue = "m4.diag",
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
        .ref_item_end = {'?', '?', '?', 0},
        .max_duration = 0
    },
    {
        .title = "[V] Le precieux",
        .text = "Trouvez l'objet convoite dans les douches",
        .file_pnj_dialogue = "m5.diag",
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
        .reward_ref_item = {'x', 'x', 'x', 0},
        .ref_item_end = {'x', 'x', 'x', 0},
        .max_duration = 0
    },
    {
        .title = "[VI] Sur la route du pouvoir",
        .text = "Augmentez vos statistiques en vous battant",
        .file_pnj_dialogue = "m6.diag",
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
        .title = "[VII A] L'affrontement finale",
        .text = "Trouvez votre ennemie jure et battez le",
        .file_pnj_dialogue = "m7_a.diag",
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
        .title = "[VII B] La fuite",
        .text = "Echappez vous de la prison",
        .file_pnj_dialogue = "m7_b.diag",
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
        .title = "[B1] La gratitude d'un prisonnier",
        .text = "Apportez une caisse de vodka à Vladimir pour le remercier",
        .file_pnj_dialogue = "b1.diag",
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
        .title = "[B2] Kill one guardian",
        .text = "Are you ready?",
        .file_pnj_dialogue = "kill_guard.diag",
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
        .reward_ref_item = {'1', '1', '5', 0},
        .ref_item_end = {'1', '1', '4', 0},
        .max_duration = 120000000
    }
};
