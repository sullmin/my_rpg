/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "option_t.h"
#include "movement.h"
#include "my_rpg.h"

void built_it(chara_animation_t *mov, size_t pos)
{
    for (size_t i = 0; i < 4; mov->orient[i] = false, i++);
    mov->orient[pos] = true;
}

void input_manage(game_t *game, sfEvent *event)
{
    option_t *option = game->option;

    if (event->key.code == UP_KEY)
        built_it(&WMAIN->player_move, 3);
    if (event->key.code == DOWN_KEY)
        built_it(&WMAIN->player_move, 2);
    if (event->key.code == LEFT_KEY)
        built_it(&WMAIN->player_move, 1);
    if (event->key.code == RIGHT_KEY)
        built_it(&WMAIN->player_move, 0);
}
