/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-25T18:25:07+01:00 | Author: simon
*/

#ifndef H_MY_RPG
#define H_MY_RPG

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my.h"
#include "sound_manager.h"
#include "config_manager.h"
#include "gui.h"
#include "my_math.h"
#include "window.h"
#include "quest_menu.h"
#include "game.h"
#include "isow.h"
#include "quest_system.h"
#include "inventory_system.h"
#include "option_menu.h"
#include "main_menu.h"
#include "credit_menu.h"
#include "help_menu.h"
#include "pause_menu.h"
#include "main_world.h"
#include "movement.h"
#include "pnj.h"
#include "sound.h"
#include "door_t.h"

#define ENV(game) &game->env

// Get env str
#define GET_VAR(game, label) my_env_get_value(ENV(game), label)
// Get env integer
#define GET_VAR_NBR(game, label, err_ptr) my_env_get_value_int(ENV(game),\
                                                            label,\
                                                            err_ptr)
// Get env double
#define GET_VAR_DEC(game, label, err_ptr) my_env_get_value_dec(ENV(game),\
                                                            label,\
                                                            err_ptr)

typedef void (* const FUNC_EXEC)(game_t *game);
typedef void (* const FUNC_EVENT)(game_t *game, sfEvent *event);

typedef void (* const FUNC_PNJ_ACTION)(game_t *game, const size_t id_pnj);

// Just the main function's prototypes are in this header
int usage(int status, const char *program_name);
int master(void);

void set_game_state(game_t *game, game_status_t new_state);

// TEMP
stat_t get_player_stat(game_t *game);
void display_player_gui(game_t *game);
void reload_particules(game_t *game);

#endif
