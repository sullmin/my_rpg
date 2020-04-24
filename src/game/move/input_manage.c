/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "option_t.h"
#include "movement.h"
#include "my_rpg.h"

void input_manage(game_t *game, sfEvent *event)
{
    option_t *option = game->option;

    for (size_t i = 0; i < 4; game->player_move.orient[i] = false, i++);
    if (event->key.code == UP_KEY) {
        game->player_move.orient[3] = true;
        game->player_move.in_move = true;
    }
    if (event->key.code == DOWN_KEY) {
        game->player_move.orient[2] = true;
        game->player_move.in_move = true;
    }
    if (event->key.code == LEFT_KEY) {
        game->player_move.orient[1] = true;
        game->player_move.in_move = true;
    }
    if (event->key.code == RIGHT_KEY) {
        game->player_move.orient[0] = true;
        game->player_move.in_move = true;
    }
}