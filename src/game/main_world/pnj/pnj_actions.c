/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-01T19:19:48+02:00 | Author: simon
*/

#include "my_rpg.h"

static const size_t ID_QUEST_BONUS_A = 8;

void vladimir_action(game_t *game, const size_t id_pnj)
{
    if (WMAIN->pnj_man.all_pnj[id_pnj].nb_interaction == 0) {
        quest_finish(game, 1, true);
        quest_enable(game, 2);
    } else if (WMAIN->pnj_man.all_pnj[id_pnj].nb_interaction == 1) {
        quest_enable(game, ID_QUEST_BONUS_A);
    } else {
        sound_manager_play(&SOUND, HIT);
    }
}

void guardian_action(game_t *game, const size_t id_pnj)
{

}

void boss_action(game_t *game, const size_t id_pnj)
{

}

void random_alpha_action(game_t *game, const size_t id_pnj)
{
    if (WMAIN->pnj_man.all_pnj[id_pnj].nb_interaction == 0) {
        quest_finish(game, 1, true);
        quest_enable(game, 2);
    }
}
