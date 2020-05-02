/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"

void move_to_equiped(game_t *game, item_t *item)
{
    INVENTORY.equiped = item;
}

void unequiped(game_t *game)
{
    INVENTORY.equiped = NULL;
}

static bool can_rm_item(item_t *item)
{
    char *key[] = {"113", "213", "313", "413"};

    if (sfMouse_isButtonPressed(sfMouseRight)) {
        for (size_t i = 0; i < 4; i++) {
            if (my_strcmp(item->id, key[i]) == 0)
                return false;
        }
        return true;
    }
    return false;
}

void inventory_edit(game_t *game, display_stat_t *info, const size_t i)
{
    compare_item(game->w.window, info, INVENTORY.inventory[i]);
    if (can_rm_item(INVENTORY.inventory[i])) {
        if (INVENTORY.equiped &&
            my_strcmp(INVENTORY.inventory[i]->id, INVENTORY.equiped->id) == 0)
            unequiped(game);
        if (INVENTORY.ctrl)
            empty_slot(&INVENTORY, i);
    }
    else if (sfMouse_isButtonPressed(sfMouseLeft))
        move_to_equiped(game, INVENTORY.inventory[i]);
}

void display_equiped_item(game_t *game)
{
    sfText *txt;
    sfVector2f pos = game->ui.display_stat.pos;
    sfVector2f pos_sprite = {pos.x + INTER_LINE * 16, pos.y + 15};
    sfSprite *sprite;

    pos.x += INTER_LINE * 12;
    if (INVENTORY.equiped) {
        sprite = INVENTORY.equiped->sprite;
        txt = sfText_create();
        sfText_setFont(txt, game->ui.display_stat.font);
        sfText_setCharacterSize(txt, 35);
        sfText_setColor(txt, sfWhite);
        if (!txt)
            return;
        display_str(game->w.window, txt, &pos, "Is equiped :");
        sfSprite_setPosition(sprite, pos_sprite);
        sfRenderWindow_drawSprite(game->w.window, sprite, NULL);
        sfText_destroy(txt);
    }
}