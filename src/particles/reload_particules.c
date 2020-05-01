/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-01T12:39:06+02:00 | Author: simon
*/

#include "my_rpg.h"

void reload_particules(game_t *game)
{
    destroy_particles(ISOW.sand);
    ISOW.sand = create_particles(game->w, 2, (sfColor) {255, 153, 0, 255}, 3);
}
