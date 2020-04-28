/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_main_world
*/

#include "my_rpg.h"

void destroy_main_world(game_t *game)
{
    sfSprite_destroy(game->wmain->sprite);
    sfTexture_destroy(game->wmain->texture);
    word_array_destroy(game->wmain->hitbox);
    sfClock_destroy(WMAIN->clock);
    free(game->wmain);
}
