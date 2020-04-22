/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_main_world
*/

#include "my_rpg.h"

static const char *filepath = "asset/sprite/background.png";

int create_main_world(game_t *game)
{
    game->wmain = malloc(sizeof(main_world_t));
    game->wmain->rect = malloc(sizeof(sfIntRect));
    game->wmain->rect->top = 400;
    game->wmain->rect->left = 400;
    game->wmain->rect->width = 480;
    game->wmain->rect->height = 256;
    game->wmain->texture = sfTexture_createFromFile(filepath, NULL);
    game->wmain->sprite = sfSprite_create();
    sfSprite_setScale(game->wmain->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(game->wmain->sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(game->wmain->sprite, game->wmain->texture, sfFalse);
    sfSprite_setTextureRect(game->wmain->sprite, *game->wmain->rect);
    if (game->wmain == NULL || game->wmain->texture == NULL || game->wmain->sprite == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}