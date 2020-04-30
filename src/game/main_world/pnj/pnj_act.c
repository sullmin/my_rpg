/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"
#include "fight.h"

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
            if (WMAIN->pnj_man.all_pnj[id].go_act && 
                play_fight(game->w, (fight_mode_t) {1, 1000, 0.8, 1}) == 1)
                WMAIN->pnj_man.all_pnj[id].go_act = false;
                if (QUEST.is_active[2])
                    move_item_in_inventory(game, "114");
    }
}