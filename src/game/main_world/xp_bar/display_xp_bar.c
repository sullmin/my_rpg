/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_xp_bar
*/

#include "my_rpg.h"

int display_xp_bar(game_t *game)
{
    if (update_xp_bar(game) == EXIT_ERROR)
        return EXIT_ERROR;
    progress_display(WMAIN->bar, WINDOW);
    return EXIT_SUCCESS;
}