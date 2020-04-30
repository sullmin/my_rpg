/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_world
*/

#include "my_rpg.h"

static void set_pnj_activate(game_t *game, sfEvent *event)
{
    if (is_key_pressed(event, sfKeyF))
        collision_act(game);
}

void event_main_world(game_t *game, sfEvent *event)
{
    set_pnj_activate(game, event);
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
}
