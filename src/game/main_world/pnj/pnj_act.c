/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"
#include "fight.h"

static void default_action(game_t *game, const size_t id)
{
    pnj_t *pnj_list = WMAIN->pnj_man.all_pnj;
    fight_mode_t fight_config = fight_get_config(game);

    if ((pnj_list[id].go_act || pnj_list[id].is_hostile)
            && play_fight(game, fight_config) == 1) {
        WMAIN->pnj_man.all_pnj[id].go_act = false;
        if (QUEST.is_active[2]) {
            move_item_in_inventory(game, "114");
        }
    }
}

void act_manage(game_t *game, const size_t id)
{
    switch(id) {
        case 2:
            if (WMAIN->pnj_man.all_pnj[id].go_act)
                quest_enable(game, 1);
            WMAIN->pnj_man.all_pnj[id].go_act = false;
            break;
        case 5:
            if (WMAIN->pnj_man.all_pnj[id].go_act)
                quest_enable(game, 2);
            WMAIN->pnj_man.all_pnj[id].go_act = false;
            break;
        default:
            default_action(game, id);
    }
}
