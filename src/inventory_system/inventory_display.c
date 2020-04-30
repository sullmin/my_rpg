/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"

static void display_item(player_inventory_t *inv, sfRenderWindow *window,
    size_t i)
{
    sfVector2f pos = {0};
    size_t y = (i < 9) ? 0 : 1;
    size_t x = (y == 0) ? i : i  - 9;

    pos.x = inv->pos.x + x * (INV_X_SIZE / 9) + 15;
    pos.y = inv->pos.y + y * (INV_Y_SIZE / 2) + 20;
    sfSprite_setPosition(inv->inventory[i]->sprite, pos);
    sfRenderWindow_drawSprite(window, inv->inventory[i]->sprite, NULL);
}

void display_inventory(player_inventory_t *inv, sfRenderWindow *window)
{
    sfSprite_setPosition(inv->sprite, inv->pos);
    sfRenderWindow_drawSprite(window, inv->sprite, NULL);
    for (size_t i = 0; i < inv->size; i++) {
        if (inv->inventory[i])
            display_item(inv, window, i);
    }
}

void display_only_inventory(game_t *game)
{
    display_inventory(&INVENTORY, WINDOW);
}
