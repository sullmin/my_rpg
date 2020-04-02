/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T11:21:15+02:00 | Author: simon
*/

#include "my_rpg.h"

void (* const FUNC_EXEC[NB_GAME_STATE])(game_t *game) =
{
    NULL,
    NULL,
    &display_main_menu, // Main Menu
    NULL, // Pause Menu
    NULL, // Fight Mode
    NULL, // Main World
    NULL // Iso World
};

void (* const FUNC_EVENT[NB_GAME_STATE])(game_t *game, sfEvent *event) =
{
    NULL,
    NULL,
    &event_main_menu, // Main Menu
    NULL, // Pause Menu
    NULL, // Fight Mode
    NULL, // Main World
    NULL // Iso World
};
