/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:30:25+01:00 | Author: simon
*/

#include "my_rpg.h"

static int game_init_struct(game_t *game)
{
    game->state = MAIN_MENU;
    return EXIT_SUCCESS;
}

int game_create(game_t *game)
{
    if (game_init_struct(game) == EXIT_ERROR)
        return EXIT_ERROR;
    
    return EXIT_SUCCESS;
}
