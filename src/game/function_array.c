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
    &display_main_menu,
    &display_pause_menu,
    &display_main_world,
    &isow_run,
    &display_option_menu,
    &display_help_menu,
    &credit_menu_display
};

FUNC_EVENT fct_event[NB_GAME_STATE] = {
    NULL,
    NULL,
    &event_main_menu,
    &event_pause_menu,
    &event_main_world,
    &isow_event_manager,
    &event_option_menu,
    &event_help_menu,
    &credit_menu_event
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
