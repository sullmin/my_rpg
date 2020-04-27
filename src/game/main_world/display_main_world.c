/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_main_world
*/

#include "my_rpg.h"

void display_main_world(game_t *game)
{
    game->wmain->rect.width = 480 * WMAIN->zoom;
    game->wmain->rect.height = 256 * WMAIN->zoom;
    sfSprite_setTextureRect(WMAIN->sprite, WMAIN->rect);
    sfSprite_setScale(WMAIN->sprite, (sfVector2f){WMAIN->zoom, WMAIN->zoom});
    sfRenderWindow_drawSprite(game->w.window, game->wmain->sprite, NULL);
    display_player(game->w.window, &game->player_move,
        game->player_move.in_move, game->wmain->zoom);
    //simple_pnj_move(&game->enemy, game);
}
