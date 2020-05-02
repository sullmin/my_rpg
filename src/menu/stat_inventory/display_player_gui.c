/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"
#include "display_stat.h"
#include "inventory_system.h"

static void player_stat_init(game_t *game, stat_t *ret)
{
    ret->resistance = 1;
    ret->strength = 1;
    ret->agility = 1;
    ret->health = 100;
    ret->speed = 1;
    ret->iq = 1;
    if (INVENTORY.equiped) {
        ret->resistance += INVENTORY.equiped->stats.resistance;
        ret->strength += INVENTORY.equiped->stats.strength;
        ret->agility += INVENTORY.equiped->stats.agility;
        ret->health += INVENTORY.equiped->stats.health;
        ret->speed += INVENTORY.equiped->stats.speed;
        ret->iq += INVENTORY.equiped->stats.iq;
    }
}

stat_t get_player_stat(game_t *game)
{
    stat_t ret;

    player_stat_init(game, &ret);
    for (size_t i = 0; i < game->inventory.size; i++) {
        if (game->inventory.inventory[i]) {
            ret.resistance += game->inventory.inventory[i]->stats.resistance;
            ret.strength += game->inventory.inventory[i]->stats.strength;
            ret.agility += game->inventory.inventory[i]->stats.agility;
            ret.health += game->inventory.inventory[i]->stats.health;
            ret.speed += game->inventory.inventory[i]->stats.speed;
            ret.iq += game->inventory.inventory[i]->stats.iq;
        }
    }
    return ret;
}

void display_player_gui(game_t *game)
{
    stat_t player_stat = get_player_stat(game);

    display_stat(game->w.window, &game->ui.display_stat, &player_stat);
    display_inventory(&game->inventory, game->w.window);
    stat_inv(game, &game->ui.display_stat, &game->inventory);
    display_equiped_item(game);
}
