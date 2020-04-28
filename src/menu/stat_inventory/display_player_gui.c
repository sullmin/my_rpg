/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"
#include "display_stat.h"
#include "inventory_system.h"

static void player_stat_filler(stat_t *stat, game_t *game)
{
    stat->resistance = 1;
    stat->strength = 1;
    stat->agility = 1;
    stat->health = 100;
    stat->speed = 1;
    stat->iq = 1;
    for (size_t i = 0; i < game->inventory.size; i++) {
        if (!game->inventory.inventory[i])
            continue;
        stat->resistance += game->inventory.inventory[i]->stats.resistance;
        stat->strength += game->inventory.inventory[i]->stats.strength;
        stat->agility += game->inventory.inventory[i]->stats.agility;
        stat->health += game->inventory.inventory[i]->stats.health;
        stat->speed += game->inventory.inventory[i]->stats.speed;
        stat->iq += game->inventory.inventory[i]->stats.iq;
    }
}

void display_player_gui(game_t *game)
{
    stat_t player_stat = {0};

    player_stat_filler(&player_stat, game);
    display_stat(game->w.window, &game->ui.display_stat, &player_stat);
    display_inventory(&game->inventory, game->w.window);
}
