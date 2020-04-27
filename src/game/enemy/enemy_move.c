/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

static bool is_in_player_vis(pnj_t *pnj, game_t *game)
{
    int x = pnj->pos.x * 16;
    int y = pnj->pos.y * 16;

    if (x > game->wmain->rect.left &&
        x < game->wmain->rect.left + game->wmain->rect.width)
        if (y > game->wmain->rect.top &&
            y < game->wmain->rect.top + game->wmain->rect.height)
            return true;
    return false;
}

static bool is_col(game_t *game, pnj_t *pnj)
{
    if (game->wmain->hitbox[pnj->pos.y][pnj->pos.x + 1] == 'o' ||
            game->wmain->hitbox[pnj->pos.y][pnj->pos.x - 1] == 'o')
        return true;
    return false;
}

static void display_pnj(pnj_t *pnj, game_t *game, bool stat)
{
    sfVector2f pos = {0};

    if (is_in_player_vis(pnj, game)) {
        pos.x = (pnj->pos.x - PLAYER.x) * 64 + 1152;
        pos.y = (pnj->pos.y - PLAYER.y) * 64 + 384;
        sfSprite_setPosition(pnj->move.sprite, pos);
        display_player(game->w.window, &pnj->move, stat);
    }
}

void simple_pnj_move(pnj_t *pnj, game_t *game)
{
    bool stat = true;

    if (((pnj->pos.x - 1 == PLAYER.x || pnj->pos.x + 1 == PLAYER.x) &&
        pnj->pos.y == PLAYER.y))
        stat = false;
    if (as_seconds(pnj->clock) > 0.5) {
        if (!((pnj->pos.x - 1 == PLAYER.x || pnj->pos.x + 1 == PLAYER.x) &&
            pnj->pos.y == PLAYER.y))
            pnj->pos.x += (pnj->sens) ? -1 : 1;
        if (is_col(game, pnj)) {
            pnj->sens = (pnj->sens) ? false : true;
            if (pnj->sens)
                built_it(&pnj->move, 1);
            else
                built_it(&pnj->move, 0);
        }
        sfClock_restart(pnj->clock);
    }
    display_pnj(pnj, game, stat);
}
