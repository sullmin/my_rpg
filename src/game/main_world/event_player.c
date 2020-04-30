/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_player
*/

#include "my_rpg.h"

static void set_move_state(game_t *game, bool is_moving,
enum direction direction)
{
    WMAIN->player_move.in_move = is_moving;
    WMAIN->is_player_move = is_moving;
    WMAIN->move_dir = direction;
    printf("%d\n", WMAIN->player_move.in_move);
}

static bool is_player_move_start(sfEvent *event, game_t *game)
{
    if (is_key_pressed(event, game->option->move->forward)) {
        set_move_state(game, true, UP);
        return true;
    }
    if (is_key_pressed(event, game->option->move->backward)) {
        set_move_state(game, true, DOWN);
        return true;
    }
    if (is_key_pressed(event, game->option->move->left)) {
        set_move_state(game, true, LEFT);
        return true;
    }
    if (is_key_pressed(event, game->option->move->right)) {
        set_move_state(game, true, RIGHT);
        return true;
    }
    return false;
}

static bool is_player_move_stop(sfEvent *event, game_t *game)
{
    if (is_key_released(event, game->option->move->forward)) {
        set_move_state(game, false, UP);
        return true;
    }
    if (is_key_released(event, game->option->move->backward)) {
        set_move_state(game, false, DOWN);
        return true;
    }
    if (is_key_released(event, game->option->move->left)) {
        set_move_state(game, false, LEFT);
        return true;
    }
    if (is_key_released(event, game->option->move->right)) {
        set_move_state(game, false, RIGHT);
        return true;
    }
    return false;
}

void event_player(game_t *game, sfEvent *event)
{
    if (is_player_move_start(event, game) == false) {
        is_player_move_stop(event, game);
    }
    input_manage(game, event);
}
