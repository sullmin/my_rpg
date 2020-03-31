/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T12:21:31+02:00 | Author: simon
*/

#ifndef H_QUEST_T
#define H_QUEST_T

#define NB_QUEST 1

enum quest_reward_type {
    REW_STAT,
    REW_ITEM,
    REW_BOTH
};

typedef struct quest {
    const char id[4];
    const char *title;
    const char *text;
    const char *file_pnj_dialogue;
    bool is_active;
    enum quest_reward_type type_reward;
    stat_t reward_stat;
    char reward_ref_item[4];
    char ref_item_end[4];
    sfTime time_begin;
    sfInt64 max_duration;
} quest_t;

typedef struct quest_array {
    size_t enable_quest;
    size_t size;
    list_str_t *pnj_dialogue[NB_QUEST];
} sys_quest_t;

#endif
