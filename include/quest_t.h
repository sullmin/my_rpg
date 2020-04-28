/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T12:21:31+02:00 | Author: simon
*/

#ifndef H_QUEST_T
#define H_QUEST_T

#define NB_QUEST 10

#define IDX_DIALOGUE_END -1
#define IDX_DIALOGUE_FAIL -2

#include "stat_t.h"

enum quest_reward_type {
    REW_STAT,
    REW_ITEM,
    REW_BOTH
};

typedef struct quest {
    const char *title;
    const char *text;
    const char *file_pnj_dialogue;
    enum quest_reward_type type_reward;
    stat_t reward_stat;
    char reward_ref_item[4];
    char ref_item_end[4];
    sfInt64 max_duration;
} quest_t;

typedef struct quest_system {
    bool play_dialogue;
    ssize_t dialogue_id;
    char *curr_sentence;
    size_t size;
    size_t size_enable;
    list_str_t *pnj_dialogue_end;
    list_str_t *pnj_dialogue_fail;
    list_str_t *pnj_dialogue[NB_QUEST];
    bool is_active[NB_QUEST];
    sfInt64 time_begin[NB_QUEST];
    sfRectangleShape *back;
    sfText *text;
    sfFont *font;
} sys_quest_t;

#endif
