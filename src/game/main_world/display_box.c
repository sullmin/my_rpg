/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_box
*/

#include "my_rpg.h"

int display_box(game_t *game)
{
    sfVector2f position = {0};

    for (int y = 0; y < WMAIN->size_map.y; y++) {
        for (int x = 0; x < WMAIN->size_map.x; x++) {
            if (WMAIN->hitbox[y][x] == 'B') {
                position.x = (x - WMAIN->rect.left / 16 ) * 16 * 4 -
                            (WMAIN->rect.left % 16) * 4;
                position.y = (y - WMAIN->rect.top / 16) * 16 * 4 -
                            (WMAIN->rect.top % 16) * 4;
                sfSprite_setPosition(WMAIN->spr_box, position);
                sfRenderWindow_drawSprite(WINDOW, WMAIN->spr_box ,NULL);
            }
        }
    }
    return EXIT_SUCCESS;
}