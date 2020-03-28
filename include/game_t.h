/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:36:54+01:00 | Author: simon
*/

#ifndef H_GAME_T
#define H_GAME_T

/*
    Define the state of the program (in game loop)
*/
typedef enum game_status {
    QUIT,
    ERR,
    MAIN_MENU,
    PAUSE_MENU,
    FIGHT_MODE,
    MAIN_WORLD,
    ISO_WORLD
} game_status_t;

/*
    Main structure of the program
*/
typedef struct game {
    game_status_t state;
    window_t w;
    env_t env;
    sound_manager_t sound;
    //inventoy_t inventory;
    //sys_quest_t sysquest;
    //gui_t ui;
    //iso_world_t wiso;
    //main_world_t wmain;
    //fight_mode_t wfight;
    //main_menu_t menu;
} game_t;

#endif
