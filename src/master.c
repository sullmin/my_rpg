/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:38:48+01:00 | Author: simon
*/

#include "my_rpg.h"

static int load_config_files(game_t *game)
{
    int ret;

    game->env = config_manager_create();
    ret = config_manager_read(&game->env, "./asset/config/window.conf");
    if (ret == EXIT_ERROR)
        return EXIT_ERROR;
    ret = config_manager_read(&game->env, "./asset/config/game.conf");
    if (ret == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int master(void)
{
    int ret;
    game_t game;

    if (load_config_files(&game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (window_create(&game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (game_create(&game) == EXIT_ERROR)
        return EXIT_ERROR;

    ret = game_loop(&game);

    game_destroy(&game);
    window_destroy(&game.w);
    config_manager_destroy(&game.env);
    return ret;
}
