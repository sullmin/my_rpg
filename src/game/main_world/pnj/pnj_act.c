/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"
#include "fight.h"

static void quest_manage(game_t *game, const size_t id, const size_t quest_id)
{
    if (WMAIN->pnj_man.all_pnj[id].go_act)
        quest_enable(game, quest_id);
    WMAIN->pnj_man.all_pnj[id].go_act = false;
}

static void default_action(game_t *game, const size_t id)
{
    pnj_t *pnj_list = WMAIN->pnj_man.all_pnj;
    fight_mode_t fight_config = fight_get_config(game);

    if ((pnj_list[id].go_act || pnj_list[id].is_hostile) &&
        play_fight(game, fight_config) == 1) {
        WMAIN->pnj_man.all_pnj[id].move.is_static = false;
        WMAIN->pnj_man.all_pnj[id].go_act = false;
        if (QUEST.is_active[2])
            move_item_in_inventory(game, "114");
    }
}

void act_manage(game_t *game, const size_t id)
{
    switch(id) {
        case 2:
            quest_manage(game, id, 1);
            break;
        case 5:
            quest_manage(game, id, 2);
            break;
        case 7:
            quest_manage(game, id, 3);
            break;
        case 8:
            quest_manage(game, id, 4);
            break;
        default:
            default_action(game, id);
    }
}
