/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool is_pnj_col(sfVector2i *player, sfVector2i *pnj)
{
    if (player->x == pnj->x + 1  || player->x == pnj->x ||
        player->x == pnj->x - 1)
        if (player->y == pnj->y + 1  || player->y == pnj->y ||
            player->y == pnj->y - 1)
            return true;
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
    ssize_t ret = collision_manage(game);

    if (ret == -1)
        return;
    //execute act for pnj ret
}