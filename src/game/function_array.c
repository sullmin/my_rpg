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
    &fight_mode, // Fight Mode
    &display_main_world, // Main World
    &isow_run, // Iso World
    &display_option_menu, // Option Menu
    &display_help_menu
};

FUNC_EVENT fct_event[NB_GAME_STATE] = {
    NULL,
    NULL,
    &event_main_menu, // Main Menu
    &event_pause_menu, // Pause Menu
    NULL, // Fight Mode
    &event_main_world, // Main World
    &isow_event_manager, // Iso World
    &event_option_menu, // Option Menu
    &event_help_menu
};

FUNC_EXEC fct_exec_sub_menu[NB_SUB_MENU] = {
    &menu_quest_display,
    &display_player_gui,
    NULL,   // Help menu
    NULL    // History menu
};

FUNC_EVENT fct_event_sub_menu[NB_SUB_MENU] = {
    &menu_quest_event,
    NULL,   // inventory / stat menu
    NULL,   // Help menu
    NULL    // History menu
};
