/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:36:54+01:00 | Author: simon
*/

#ifndef H_GAME_T
#define H_GAME_T

#include "quest_t.h"

/*
    Define the state of the program (in game loop)
*/
typedef enum game_status {
    QUIT = 0,
    ERR = 1,
    MAIN_MENU = 2,
    PAUSE_MENU = 3,
    MAIN_WORLD = 4,
    ISO_WORLD = 5,
    OPTION_MENU = 6,
    HELP_MENU = 7
} game_status_t;

typedef enum submenu_status {
    NO_MENU = -1,
    MQUEST = 0,
    MINVSTAT = 1,
    MHELP = 2,
    MHIST = 3
} submenu_status_t;

#define NB_GAME_STATE 8
#define NB_SUB_MENU 4

#define OPTION game->option
#define MENU_OPTION game->option_menu
#define MMENU game->menu
#define WINDOW game->w.window
#define SOUND game->sound
#define MENU_QUEST game->quest_menu
#define QUEST game->sysquest
#define MENU_HELP game->help_menu
#define WMAIN game->wmain
#define MENU_CREDIT game->credit_menu

#include "gui_t.h"
#include "option_t.h"
#include "display_stat.h"
#include "pause_menu_t.h"
#include "option_menu_t.h"
#include "quest_menu_t.h"
#include "inventory_system_t.h"
#include "isow_t.h"
#include "main_world_t.h"
#include "movement_t.h"
#include "pnj_t.h"
#include "help_menu_t.h"
#include "credit_menu_t.h"

/*
    Main structure of the program
*/
typedef struct game {
    submenu_status_t submenu;
    game_status_t prev_state;
    game_status_t state;
    sfClock *clock;
    window_t w;
    env_t env;
    sound_manager_t sound;
    sys_quest_t sysquest;
    gui_t ui;
    player_inventory_t inventory;
    list_t *item_load;
    isow_t wiso;
    main_world_t *wmain;
    quest_menu_t quest_menu;
    main_menu_t *menu;
    option_menu_t *option_menu;
    pause_menu_t *pause;
    credit_menu_t credit_menu;
    help_menu_t *help_menu;
    option_t *option;
} game_t;

#endif
