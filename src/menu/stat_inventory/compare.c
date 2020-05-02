/*
** EPITECH PROJECT, 2019
** myrpg

** File description:
** myrpg
*/

#include "my_rpg.h"
#include "display_stat.h"

static bool get_vector(sfVector2f p_one, sfVector2f p_two, sfVector2f p_x)
{
    float val = (p_one.x - p_x.x) * (p_two.y - p_x.y);

    val -= (p_one.y - p_x.y) * (p_two.x - p_x.x);
    if (val > 0)
        return true;
    return false;
}

static bool is_in_triangle(sfVector2f p_one, sfVector2f p_two,
    sfVector2f p_three, sfVector2f p_x)
{
    bool tab[3];

    tab[0] = get_vector(p_one, p_two, p_x);
    tab[1] = get_vector(p_two, p_three, p_x);
    tab[2] = get_vector(p_three, p_one, p_x);
    if (tab[0] && tab[1] && tab[2])
        return true;
    if (!tab[0] && !tab[1] && !tab[2])
        return true;
    return false;
}

static bool display_this_stat(sfVector2f pos, sfVector2f hit)
{
    if (is_in_triangle(pos, (sfVector2f) {pos.x, pos.y - 55},
        (sfVector2f) {pos.x - 56, pos.y}, hit))
        return true;
    if (is_in_triangle((sfVector2f) {pos.x - 56, pos.y - 55},
        (sfVector2f) {pos.x, pos.y - 55},
        (sfVector2f) {pos.x - 15, pos.y}, hit))
        return true;
    return false;
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

void stat_inv(sfRenderWindow *window,
    display_stat_t *info, player_inventory_t *inv)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = (sfVector2f) {tmp.x, tmp.y};
    sfVector2f pos;
    size_t y;
    size_t x;

    for (size_t i = 0; i < inv->size; i++) {
        y = (i < 9) ? 0 : 1;
        x = (y == 0) ? i : i  - 9;
        pos.x = inv->pos.x + x * (INV_X_SIZE / 9) + 56;
        pos.y = inv->pos.y + y * (INV_Y_SIZE / 2) + 55;
        if (inv->inventory[i] && display_this_stat(pos, mouse)) {
            compare_item(window, info, inv->inventory[i]);
            if (can_rm_item(inv->inventory[i]))
                empty_slot(inv, i);
        }
    }
}