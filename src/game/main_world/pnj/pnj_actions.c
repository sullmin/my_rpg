/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-01T19:19:48+02:00 | Author: simon
*/

#include "my_rpg.h"
#include "fight.h"

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
    fight_mode_t fight_config;

    if (WMAIN->pnj_man.all_pnj[id_pnj].nb_interaction == 0) {
        quest_enable(game, 3);
    } else if (QUEST.is_active[3] == true) {
        fight_config = fight_get_config(game);
        if (play_fight(game, fight_config) == 1) {
            quest_finish(game, 3, true);
            quest_enable(game, 4);
        }
    } else {
        sound_manager_play(&SOUND, HIT);
    }
}

void boss_action(game_t *game, const size_t id_pnj)
{
    fight_mode_t fight_config;

    (void)id_pnj;
    fight_config = fight_get_config(game);
    fight_config.actions += 8;
    fight_config.interval -= 500;
    fight_config.speed -= 0.1;
    fight_config.comb += 4;
    if (play_fight(game, fight_config) == 1) {
        if (QUEST.is_active[6] == true) {
            quest_finish(game, 6, false);
            set_game_state(game, CREDIT_MENU);
        }
    }
}

void random_alpha_action(game_t *game, const size_t id_pnj)
{
    if (WMAIN->pnj_man.all_pnj[id_pnj].nb_interaction == 0) {
        quest_enable(game, 9);
    }
}
