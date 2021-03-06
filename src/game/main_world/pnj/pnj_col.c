/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool is_pnj_col(sfVector2i *player, sfVector2i *pnj)
{
    if (player->x <= pnj->x + 2 && player->x >= pnj->x - 2)
        if (player->y <= pnj->y + 2 && player->y >= pnj->y - 2)
            return true;
    return false;
}

bool collision_for_player(sfVector2i *player, game_t *game)
{
    for (size_t i = 0; i < game->wmain->pnj_man.nb_pnj; i++) {
        if (player->x == WMAIN->pnj_man.all_pnj[i].pos.x &&
            player->y == WMAIN->pnj_man.all_pnj[i].pos.y)
            return true;
        if (player->x + 1 == WMAIN->pnj_man.all_pnj[i].pos.x &&
            player->y == WMAIN->pnj_man.all_pnj[i].pos.y)
            return true;
    }
    return false;
}

static ssize_t collision_manage(game_t *game)
{
    for (size_t i = 0; i < game->wmain->pnj_man.nb_pnj; i++)
        if (is_pnj_col(&WMAIN->pos_on_map_int, &WMAIN->pnj_man.all_pnj[i].pos))
            return i;
    return -1;
}

void collision_act(game_t *game)
{
    ssize_t id;

    id = collision_manage(game);
    if (id == -1)
        return;
    act_manage(game, id);
}