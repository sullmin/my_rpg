/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_main_world
*/

#include "my_rpg.h"

static const char *background = "asset/sprite/background.png";
static const char *hitbox = "asset/map/map.hitbox";

static int get_rect_view(game_t *game)
{
    game->wmain->rect_init.top = 400;
    game->wmain->rect_init.left = 400;
    game->wmain->rect_init.width = 480;
    game->wmain->rect_init.height = 256;
    game->wmain->rect = game->wmain->rect_init;
    WMAIN->size_map = (sfVector2i){91, 92};
    return EXIT_SUCCESS;
}

static int get_background(game_t *game)
{
    game->wmain->texture = sfTexture_createFromFile(background, NULL);
    game->wmain->sprite = sfSprite_create();
    if (game->wmain->texture == NULL || game->wmain->sprite == NULL)
        return EXIT_ERROR;
    sfSprite_setScale(game->wmain->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(game->wmain->sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(game->wmain->sprite, game->wmain->texture, sfFalse);
    sfSprite_setTextureRect(game->wmain->sprite, game->wmain->rect);
    return EXIT_SUCCESS;
}

static int get_player(game_t *game)
{
    game->wmain->position_player.x = 18 * 16 * 4;
    game->wmain->position_player.y = 6 * 16 * 4;
    game->wmain->position_on_map.x = 43;
    game->wmain->position_on_map.y = 32;
    return EXIT_SUCCESS;
}

static int create_clock(game_t *game)
{
    bool err = false;
    int value = GET_VAR_NBR(game, "PLAYER_MOVE_CLOCK", &err);

    if (err == true) {
        return EXIT_ERROR;
    }
    WMAIN->clock = sfClock_create();
    WMAIN->timer = 0;
    WMAIN->ms_loop = value;
    return EXIT_SUCCESS;
}

int create_main_world(game_t *game)
{
    game->wmain = malloc(sizeof(main_world_t));
    if (game->wmain == NULL)
        return EXIT_ERROR;
    if (get_rect_view(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (get_background(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (get_player(game) == EXIT_ERROR)
        return EXIT_ERROR;
    game->wmain->hitbox = my_read_file(hitbox);
    if (game->wmain->hitbox == NULL)
        return EXIT_ERROR;
    if (create_clock(game) == EXIT_ERROR) {
        return EXIT_ERROR;
    }
    WMAIN->shift_rect = 16;
    return EXIT_SUCCESS;
}
