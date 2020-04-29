/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_player
*/

#include "my_rpg.h"


static bool is_player_move(enum direction *dir, sfEvent *event, game_t *game)
{
    if (is_key_pressed(event, game->option->move->forward)) {
        *dir = UP;
        return true;
    }
    if (is_key_pressed(event, game->option->move->backward)) {
        *dir = DOWN;
        return true;
    }
    if (is_key_pressed(event, game->option->move->left)) {
        *dir = LEFT;
        return true;
    }
    if (is_key_pressed(event, game->option->move->right)) {
        *dir = RIGHT;
        return true;
    }
    return false;
}

void event_player(game_t *game, sfEvent *event)
{
    enum direction dir;
    bool state = is_player_move(&dir, event, game);

    if (state == true) {
        WMAIN->is_player_move = true;
        WMAIN->move_dir = dir;
    } else if (WMAIN->is_player_move == true) {
        WMAIN->is_player_move = false;
    }
}
