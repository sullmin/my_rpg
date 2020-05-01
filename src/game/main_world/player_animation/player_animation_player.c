/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "movement.h"
#include "my_rpg.h"

static const sfInt32 MS_LOOP = 200;
static const sfIntRect RECT_IDLE = {0, 130, 32, 65};

static void player_in_movement(chara_animation_t *mov)
{
    mov->count++;
    if (mov->count > 3) {
        mov->count = 1;
    }
    mov->rec.left = mov->rec.width * mov->count;
}

void display_player(game_t *game, chara_animation_t *mov, bool in_move)
{
    size_t i;

    mov->timer += sfTime_asMilliseconds(sfClock_getElapsedTime(mov->clock));
    sfClock_restart(mov->clock);
    for (i = 0; i < 3 && !mov->orient[i]; i++);
    mov->rec.top = mov->rec.height * i;
    if (!in_move) {
        mov->timer = 0;
        sfSprite_setTextureRect(mov->sprite, RECT_IDLE);
        sfRenderWindow_drawSprite(WINDOW, mov->sprite, NULL);
        return;
    }
    while (mov->timer >= MS_LOOP) {
        mov->timer -= MS_LOOP;
        player_in_movement(mov);
    }
    sfSprite_setTextureRect(mov->sprite, mov->rec);
    sfRenderWindow_drawSprite(WINDOW, mov->sprite, NULL);
    if (in_move) {
        //set_particles_pos(mov->effect, (sfVector2f) {1015, 650}, 10);
        draw_particles(mov->effect);
        update_particles(mov->effect, game->w);
    }
}
