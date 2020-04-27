/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-27T09:59:13+02:00 | Author: simon
*/

#include "my_rpg.h"

float zoom = 4;

static bool vertical(game_t *game, enum direction dir)
{
    if (dir == UP) {
        if (WMAIN->rect.top - WMAIN->shift_rect > 0) {
            //WMAIN->rect.top = WMAIN->rect_init.top + round(WMAIN->position_on_map.y * WMAIN->shift_rect);
            WMAIN->rect.top += WMAIN->shift_rect;
            //WMAIN->rect.top = (WMAIN->position_player.y * WMAIN->shift_rect) * zoom;
            sfSprite_setTextureRect(WMAIN->sprite, WMAIN->rect);
            return true;
        }
    } else if (dir == DOWN) {
        if (WMAIN->rect.top + WMAIN->shift_rect <= 1232) {
            //WMAIN->rect.top = WMAIN->rect_init.top - round(WMAIN->position_on_map.y * WMAIN->shift_rect);
            //WMAIN->rect.top = (WMAIN->position_player.y * WMAIN->shift_rect)  * zoom;
            WMAIN->rect.top -= WMAIN->shift_rect;
            sfSprite_setTextureRect(WMAIN->sprite, WMAIN->rect);
            return true;
        }
    }
    return false;
}

static bool horizontal(game_t *game, enum direction dir)
{
    if (dir == LEFT) {
        if (WMAIN->rect.left - WMAIN->shift_rect > 0) {
            WMAIN->rect.left -= WMAIN->shift_rect;
            //WMAIN->rect.left = (WMAIN->position_player.x * WMAIN->shift_rect) * zoom;
            sfSprite_setTextureRect(WMAIN->sprite, WMAIN->rect);
            return true;
        }
    } else if (dir == RIGHT) {
        if (WMAIN->rect.left + WMAIN->shift_rect <= 992) {
            WMAIN->rect.left += WMAIN->shift_rect;
            //WMAIN->rect.left = (WMAIN->position_player.x * WMAIN->shift_rect) * zoom;
            sfSprite_setTextureRect(WMAIN->sprite, WMAIN->rect);
            return true;
        }
    }
    return false;
}

bool mw_camera_move(game_t *game, enum direction dir)
{
    if (vertical(game, dir)) {
        return true;
    } else if (horizontal(game, dir)) {
        return true;
    }
    return false;
}
