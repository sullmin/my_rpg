/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"
#include "display_stat.h"
#include "inventory_system.h"

void display_player_gui(game_t *game)
{
    if (game->ui.display_stat.display_it) {
        display_stat(game->w.window, &game->ui.display_stat,
            &game->item_load->item->stats);
        display_inventory(&game->inventory, game->w.window);
    }
}