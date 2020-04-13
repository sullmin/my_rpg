/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-30T11:21:15+02:00 | Author: simon
*/

#include "my_rpg.h"

FUNC_EXEC fct_exec[NB_GAME_STATE] = {
    NULL,
    NULL,
    &display_main_menu, // Main Menu
    &display_pause_menu, // Pause Menu
    NULL, // Fight Mode
    NULL, // Main World
    NULL, // Iso World
    &display_option_menu // Option Menu
};

FUNC_EVENT fct_event[NB_GAME_STATE] = {
    NULL,
    NULL,
    &event_main_menu, // Main Menu
    &event_pause_menu, // Pause Menu
    NULL, // Fight Mode
    NULL, // Main World
    NULL, // Iso World
    &event_option_menu // Option Menu
};
