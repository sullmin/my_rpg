/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"
#include "fight.h"

extern const size_t SIZE_LIST_PNJ;

FUNC_PNJ_ACTION PNJ_ACTIONS[9] =
{
    &guardian_action,
    NULL,
    &vladimir_action,
    NULL,
    &boss_action,
    &random_alpha_action,
    NULL,
    NULL,
    NULL
};

static void default_action(game_t *game, const size_t id)
{
    pnj_t *pnj_list = WMAIN->pnj_man.all_pnj;
    fight_mode_t fight_config = fight_get_config(game);

    if ((pnj_list[id].go_act || pnj_list[id].is_hostile) &&
        play_fight(game, fight_config) == 1) {
        WMAIN->pnj_man.all_pnj[id].move.is_static = false;
        WMAIN->pnj_man.all_pnj[id].go_act = false;
        if (QUEST.is_active[9]) {
            move_item_in_inventory(game, "114");
        }
    }
}

void act_manage(game_t *game, const size_t id)
{
    if (id >= WMAIN->pnj_man.nb_pnj) {
        return;
    }
    if (id < SIZE_LIST_PNJ && PNJ_ACTIONS[id]) {
        PNJ_ACTIONS[id](game, id);
    } else {
        default_action(game, id);
    }
    WMAIN->pnj_man.all_pnj[id].nb_interaction++;
}
