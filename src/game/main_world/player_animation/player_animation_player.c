/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "movement.h"
#include "my_rpg.h"

static void player_in_movement(chara_animation_t *mov, float time, sfIntRect *rec)
{
    if (time > TIME_MOVE) {
        sfClock_restart(mov->clock);
        time = as_seconds(mov->clock);
    }
    if (time < TIME_MOVE * 0.3) {
        rec->left = rec->width * 1;
    }
    else if (time < TIME_MOVE * 0.6) {
        rec->left = rec->width * 2;
    }
    else {
        rec->left = rec->width * 3;
    }
}

void display_player(sfRenderWindow *window, chara_animation_t *mov, bool act_move,
    float zoom)
{
    sfIntRect rec = {0, 0, 32, 65};
    size_t i;
    float time = as_seconds(mov->clock);

    mov->in_move = false;
    for (i = 0; i < 3 && !mov->orient[i]; i++);
    rec.top = rec.height * i;
    if (!act_move && time > TIME_MOVE) {
        sfSprite_setScale(mov->sprite, (sfVector2f) {zoom / 2, zoom / 2});
        sfSprite_setTextureRect(mov->sprite, rec);
        sfRenderWindow_drawSprite(window, mov->sprite, NULL);
        return;
    }
    player_in_movement(mov, time, &rec);
    sfSprite_setPosition(mov->sprite,
        (sfVector2f) {1136 * (zoom / 4), 368 * (zoom / 4)});
    sfSprite_setScale(mov->sprite, (sfVector2f) {zoom / 2, zoom / 2});
    sfSprite_setTextureRect(mov->sprite, rec);
    sfRenderWindow_drawSprite(window, mov->sprite, NULL);
}