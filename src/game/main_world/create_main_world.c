/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_main_world
*/

#include "my_rpg.h"

static const char *background = "asset/sprite/background.png";
static const char *hitbox = "asset/map/map.hitbox";
static const char *player = "asset/sprite/player.png";

static int get_rect_view(game_t *game)
{
    game->wmain->rect = malloc(sizeof(sfIntRect));
    if (game->wmain->rect == NULL)
        return EXIT_ERROR;
    game->wmain->rect->top = 400;
    game->wmain->rect->left = 400;
    game->wmain->rect->width = 480;
    game->wmain->rect->height = 256;
    return EXIT_SUCCESS;
}

static int get_background(game_t *game)
{
    game->wmain->texture = sfTexture_createFromFile(background, NULL);
    game->wmain->sprite = sfSprite_create();
    if (game->wmain->texture == NULL || game->wmain->sprite == NULL)
        return EXIT_ERROR;
    sfSprite_setScale(WMAIN->sprite, (sfVector2f){WMAIN->zoom, WMAIN->zoom});
    sfSprite_setPosition(game->wmain->sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(game->wmain->sprite, game->wmain->texture, sfFalse);
    sfSprite_setTextureRect(game->wmain->sprite, *game->wmain->rect);
    return EXIT_SUCCESS;
}

static int get_player(game_t *game)
{
    game->wmain->position_player.x = 18 * 16 * game->wmain->zoom;
    game->wmain->position_player.y = 6 * 16 * game->wmain->zoom;
    game->wmain->position_on_map.x = 43;
    game->wmain->position_on_map.y = 32;
    game->wmain->t_player = sfTexture_createFromFile(player, NULL);
    game->wmain->s_player = sfSprite_create();
    if (game->wmain->s_player == NULL || game->wmain->t_player == NULL)
        return EXIT_ERROR;
    sfSprite_setPosition(game->wmain->s_player, game->wmain->position_player);
    sfSprite_setTexture(game->wmain->s_player, game->wmain->t_player, sfFalse);
    sfSprite_setScale(WMAIN->s_player, (sfVector2f){WMAIN->zoom, WMAIN->zoom});
    return EXIT_SUCCESS;
}

int create_main_world(game_t *game)
{
    game->wmain = malloc(sizeof(main_world_t));
    if (game->wmain == NULL)
        return EXIT_ERROR;
    game->wmain->zoom = 4;
    if (get_rect_view(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (get_background(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (get_player(game) == EXIT_ERROR)
        return EXIT_ERROR;
    game->wmain->hitbox = my_read_file(hitbox);
    if (game->wmain->hitbox == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}