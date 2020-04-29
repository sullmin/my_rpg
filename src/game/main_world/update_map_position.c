/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-27T09:59:13+02:00 | Author: simon
*/

#include "my_rpg.h"

void update_map_position(game_t *game)
{
    float percent_on_map_y = ((float)WMAIN->position_on_map.y
        / WMAIN->size_map.y);
    float percent_on_map_x = ((float)WMAIN->position_on_map.x
        / WMAIN->size_map.x);
    float pos;

    pos = (percent_on_map_y * (float)WMAIN->size_map_pixel.y);
    WMAIN->rect.top = pos;
    WMAIN->rect.top -= WMAIN->shift_rect * 10;
    pos = (percent_on_map_x * (float)WMAIN->size_map_pixel.x);
    WMAIN->rect.left = pos;
    WMAIN->rect.left -= WMAIN->shift_rect * 15.8;
    sfSprite_setTextureRect(WMAIN->sprite, WMAIN->rect);
    if (as_seconds(WMAIN->sound_effect[1].clock) > 0.3) {
        sfSound_setVolume(WMAIN->sound_effect[1].sound, OPTION->volume);
        sfSound_play(WMAIN->sound_effect[1].sound);
        sfClock_restart(WMAIN->sound_effect[1].clock);
    }
}
