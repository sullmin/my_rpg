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
#include "window.h"
#include "game.h"

// Information Importantes !!!!
// Etant donne que le projet est consequent et pour eviter les merges
// ne PAS mettre les prototypes de vos fonctions dans ce header
// mais creer une .h dedie et l'inclure le dans celui-ci

// #include "quest_system.h"
// #include "inventory_system.h"
// #include "main_menu.h"
// ...

// Just the main function's prototypes are in this header
int usage(int status, const char *program_name);
int master(void);

#endif
