/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T10:16:31+01:00 | Author: simon
*/

#include "my_rpg.h"

static void event_window_close(game_t *game)
{
    sfRenderWindow_close(game->w.window);
}

static void event_crossroads(game_t *game, sfEvent *event)
{
    switch (game->state) {
        case MAIN_MENU:
            // Main menu exec event
            break;
        case PAUSE_MENU:
            // Pause menu exec event
            break;
        case FIGHT_MODE:
            // Fight Mode exec event
            break;
        case MAIN_WORLD:
            // Main world exec event
            break;
        case ISO_WORLD:
            // Iso world exec event
            break;
        default:
            break;
    }
}

void call_event_manager(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        event_window_close(game);
        return;
    }
    event_crossroads(game, event);
}
