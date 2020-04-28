/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_main_world
*/

#include "my_rpg.h"

void destroy_main_world(game_t *game)
{
    sfSprite_destroy(WMAIN->sprite);
    sfTexture_destroy(WMAIN->texture);
    word_array_destroy(WMAIN->hitbox);
    sfClock_destroy(WMAIN->clock);
    sfView_destroy(WMAIN->view);
    free(WMAIN);
}
