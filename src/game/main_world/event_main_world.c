/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_world
*/

#include "my_rpg.h"

static void set_player_movement_state(game_t *game, sfEvent *event)
{
    if (is_key_pressed(event, game->option->move->forward)
            || is_key_pressed(event, game->option->move->backward)
            || is_key_pressed(event, game->option->move->right)
            || is_key_pressed(event, game->option->move->left)) {
        WMAIN->player_move.in_move = true;
    } else {
        WMAIN->player_move.in_move = false;
    }
}

void event_main_world(game_t *game, sfEvent *event)
{
    event_player(game, event);
    if (event->type == sfEvtMouseWheelScrolled) {
        if (event->mouseWheelScroll.delta == 1) {
            sfView_zoom(WMAIN->view, 0.9);
            WMAIN->nb_zoom++;

        } else if (event->mouseWheelScroll.delta == -1 && WMAIN->nb_zoom) {
            sfView_zoom(WMAIN->view,
            powf(0.9, WMAIN->nb_zoom - 1) / powf(0.9, WMAIN->nb_zoom));
            WMAIN->nb_zoom--;
        }
    }
    set_player_movement_state(game, event);
}
