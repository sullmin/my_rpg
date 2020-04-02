/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T12:21:31+02:00 | Author: simon
*/

#ifndef H_QUEST
#define H_QUEST

#include "quest_t.h"

// Quest
int sysquest_create(sys_quest_t *quests);
void sysquest_destroy(sys_quest_t *quests);

int quest_enable(game_t *game, size_t id);
int sysquest_check_end(game_t *game);

// DIALOGUE
void dialogue_play(sys_quest_t *quests, int id);
int dialogue_display(game_t *game);

// Quest sub-function
int quest_finish(sys_quest_t *quests, game_t *game, size_t id);

// Dialogue sub-function
int dialogue_load(list_str_t **dialogue, const char *file);
void dialogue_destroy(list_str_t *dialogue);
bool dialogue_read_next_sentence(sys_quest_t *sysquest);

#endif
