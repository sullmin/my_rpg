/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_world
*/

#include "my_rpg.h"

void event_main_world(game_t *game, sfEvent *event)
{
    event_player(game, event);
    if (event->type == sfEvtMouseWheelScrolled) {
        game->wmain->zoom += event->mouseWheelScroll.delta / 5;
        if (game->wmain->zoom < 2)
            game->wmain->zoom -= event->mouseWheelScroll.delta / 5;
        if (game->wmain->zoom > 8)
            game->wmain->zoom -= event->mouseWheelScroll.delta / 5;
    }
}
