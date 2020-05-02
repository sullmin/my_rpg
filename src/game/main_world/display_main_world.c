/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_main_world
*/

#include "my_rpg.h"
#include "particles_manager.h"

void display_main_world(game_t *game)
{
    sfRenderWindow_setView(game->w.window, WMAIN->view);
    game->wmain->rect.width = 480 * WMAIN->zoom;
    game->wmain->rect.height = 256 * WMAIN->zoom;
    sfSprite_setTextureRect(WMAIN->sprite, WMAIN->rect);
    sfSprite_setScale(WMAIN->sprite, (sfVector2f){WMAIN->zoom, WMAIN->zoom});
    sfRenderWindow_drawSprite(game->w.window, game->wmain->sprite, NULL);
    display_box(game);
    display_all_pnj(game);
    set_particles_pos(WMAIN->player_move.effect, (sfVector2f) {1014, 650}, 10);
    display_player(game, &WMAIN->player_move, WMAIN->player_move.in_move);
    player_move(game);
    if (game->debug_mode) {
        player_display_hitbox(game);
    }
    display_particule(game);
    display_xp_bar(game);
}