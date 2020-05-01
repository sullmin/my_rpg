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

static int master_contruct_part2(game_t *game)
{
    if (!player_inventory_creat(&game->inventory, &game->env))
        return EXIT_ERROR;
    if (!item_manage(&game->item_load) ||
        !init_display_stat(&game->ui.display_stat, &game->env))
        return EXIT_ERROR;
    if (menu_quest_create(game) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (!movement_creat(&WMAIN->player_move))
        return EXIT_ERROR;
    if (!init_all_pnj(&WMAIN->pnj_man, &game->env))
        return EXIT_ERROR;
    if (create_help_menu(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (credit_menu_create(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (!init_particles_effect(game))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int master_contruct_part1(game_t *game)
{
    if (load_config_files(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (window_create(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_main_menu(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_option_menu(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_pause_menu(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (sysquest_create(&game->sysquest) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_main_world(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (!load_sound_effect(game))
        return EXIT_ERROR;
    if (game_create(game) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int master_destroy(game_t *game)
{
    destroy_particles_effct(game);
    destroy_sound_effect(game);
    destroy_pnj(&WMAIN->pnj_man);
    destroy_movement(&WMAIN->player_move);
    destroy_main_menu(game);
    destroy_option_menu(game);
    destroy_pause_menu(game);
    game_destroy(game);
    window_destroy(&game->w);
    config_manager_destroy(&game->env);
    sysquest_destroy(&game->sysquest);
    player_inventory_destroy(&game->inventory);
    distroy_item_list(game->item_load);
    destroy_main_world(game);
    destroy_help_menu(game);
    menu_quest_destroy(game);
    credit_menu_destroy(game);
    return EXIT_SUCCESS;
}

int master(void)
{
    int ret;
    game_t game;

    if (master_contruct_part1(&game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (master_contruct_part2(&game) == EXIT_ERROR)
        return EXIT_ERROR;
    ret = game_loop(&game);
    if (master_destroy(&game) == EXIT_ERROR)
        return EXIT_ERROR;
    return ret;
}
