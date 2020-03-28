/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:32:14+01:00 | Author: simon
*/

#include "my_rpg.h"

static void crossroads(game_t *game)
{
    switch (game->state) {
        case MAIN_MENU:
            // Main menu exec
            break;
        case PAUSE_MENU:
            // Pause menu exec
            break;
        case FIGHT_MODE:
            // Fight Mode exec
            break;
        case MAIN_WORLD:
            // Main world exec
            break;
        case ISO_WORLD:
            // Iso world exec
            break;
        default:
            break;
    }
}

static int run(game_t *game)
{
    sfRenderWindow_clear(game->w.window, sfBlack);
    crossroads(game);
    if (game->state == ERR)
        return EXIT_ERROR;
    sfRenderWindow_display(game->w.window);
    return EXIT_SUCCESS;
}

int game_loop(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->w.window)) {
        while (sfRenderWindow_pollEvent(game->w.window, &event))
            call_event_manager(game, &event);
        if (run(game) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
