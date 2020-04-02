/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T10:16:31+01:00 | Author: simon
*/

#include "my_rpg.h"

extern void (* const FUNC_EVENT[NB_GAME_STATE])(game_t *game, sfEvent *event);

static void event_window_close(game_t *game)
{
    sfRenderWindow_close(game->w.window);
}

static void event_crossroads(game_t *game, sfEvent *event)
{
    if (game->state == QUIT || game->state == ERR) {
        return;
    }
    if (FUNC_EVENT[game->state] != NULL)
        FUNC_EVENT[game->state](game, event);
    if (game->sysquest.play_dialogue == true) {
        dialogue_event_manager(game, event);
    }
}

void call_event_manager(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed || game->state == QUIT) {
        event_window_close(game);
        return;
    }
    event_crossroads(game, event);
}
