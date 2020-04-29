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

static void display_pnj(pnj_t *pnj, game_t *game, bool stat)
{
    sfVector2f pos = {0};

    if (is_in_player_vis(pnj, game)) {
        pos.x = (pnj->pos.x - PLAYER.x) * 64 + 984;
        pos.y = (pnj->pos.y - PLAYER.y) * 64 + 550;
        sfSprite_setPosition(pnj->move.sprite, pos);
        display_player(game, &pnj->move, stat);
    }
}

static void play_sound(game_t *game, pnj_t *pnj, bool stat)
{
    float dist = point_length((sfVector2f) {PLAYER.x, PLAYER.y},
        (sfVector2f) {pnj->pos.x, pnj->pos.y});

    if (dist > 10 || !stat || game->wmain->player_move.in_move)
        return;
    dist = 10 - dist;
    sfSound_setVolume(WMAIN->sound_effect[1].sound, dist * 10);
    sfSound_play(WMAIN->sound_effect[1].sound);
}

void simple_pnj_move(pnj_t *pnj, game_t *game)
{
    bool stat = true;

    if (is_pnj_col(&WMAIN->pos_on_map_int, &pnj->pos))
        stat = false;
    pnj->timer += TIME_MILLI(pnj->clock);
    while (pnj->timer >= pnj->ms_loop) {
        pnj->timer -= pnj->ms_loop;
        pnj_evol(pnj, game, stat);
        play_sound(game, pnj, stat);
        sfClock_restart(pnj->clock);
    }
    display_pnj(pnj, game, stat);
}
