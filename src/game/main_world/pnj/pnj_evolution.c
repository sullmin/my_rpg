/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

static sfVector2i get_rand(bool *tab, pnj_t *pnj)
{
    size_t nb = rand() % 4;

    for (size_t cnt = 0; !tab[nb % 4]; nb++, cnt++)
        if (cnt > 4)
            return (sfVector2i) {0, 0};
    built_it(&pnj->move, nb % 4);
    if (nb % 4 == 0)
        return (sfVector2i) {1, 0};
    if (nb % 4 == 1)
        return (sfVector2i) {-1, 0};
    if (nb % 4 == 2)
        return (sfVector2i) {0, 1};
    if (nb % 4 == 3)
        return (sfVector2i) {0, -1};
    return (sfVector2i) {0, 0};
}

static sfVector2i get_futur_pos(game_t *game, pnj_t *pnj, sfVector2i pos)
{
    bool tab[4] = {false, false, false, false};

    if (WMAIN->hitbox[pos.y][pos.x + 1] == '.')
        tab[0] = true;
    if (WMAIN->hitbox[pos.y][pos.x - 1] == '.')
        tab[1] = true;
    if (WMAIN->hitbox[pos.y + 1][pos.x] == '.')
        tab[2] = true;
    if (WMAIN->hitbox[pos.y - 1][pos.x] == '.')
        tab[3] = true;
    return get_rand(tab, pnj);
}

static bool is_col(game_t *game, pnj_t *pnj)
{
    if (WMAIN->hitbox[pnj->pos.y + pnj->fpos.y][pnj->pos.x + pnj->fpos.x]
        != '.')
        return true;
    return false;
}

void pnj_evol(pnj_t *pnj, game_t *game, bool stat)
{
    if (pnj->move.is_static)
        return;
    if (stat && !is_col(game, pnj)) {
        pnj->pos.x += pnj->fpos.x;
        pnj->pos.y += pnj->fpos.y;
    }
    else if (stat) {
        pnj->fpos = get_futur_pos(game, pnj, pnj->pos);
    }
}