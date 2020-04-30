/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "movement.h"
#include "my_rpg.h"

static const char *PLAYER_SPRITE[] =
{
    "./asset/sprite/hero.png",
    "./asset/sprite/hero2.png"
};

static const size_t SIZE_PLAYER_SPRITE = 2;

bool movement_creat(chara_animation_t *mov)
{
    mov->sprite = sfSprite_create();
    mov->texture = sfTexture_createFromFile(PLAYER_SPRITE[0], NULL);
    mov->clock = sfClock_create();
    if (!mov->sprite || !mov->texture)
        return false;
    sfSprite_setPosition(mov->sprite, (sfVector2f) {984, 540});
    sfSprite_setTexture(mov->sprite, mov->texture, sfTrue);
    sfSprite_setScale(mov->sprite, (sfVector2f) {2, 2});
    for (size_t i = 0; i < 4; i++)
        mov->orient[i] = false;
    mov->orient[3] = true;
    mov->in_move = false;
    mov->timer = 0;
    mov->rec = (sfIntRect) {0, 0, 32, 65};
    mov->count = 1;
    return true;
}

void destroy_movement(chara_animation_t *mov)
{
    sfSprite_destroy(mov->sprite);
    sfTexture_destroy(mov->texture);
    sfClock_destroy(mov->clock);
}

int reload_player_sprite(game_t *game, size_t idx)
{
    if (idx >= SIZE_PLAYER_SPRITE) {
        return EXIT_ERROR;
    }
    sfTexture_destroy(WMAIN->player_move.texture);
    WMAIN->player_move.texture = sfTexture_createFromFile(PLAYER_SPRITE[idx],
    NULL);
    if (!WMAIN->player_move.texture) {
        return EXIT_ERROR;
    }
    sfSprite_setTexture(WMAIN->player_move.sprite, WMAIN->player_move.texture,
    sfTrue);
    sfSprite_setScale(WMAIN->player_move.sprite, (sfVector2f) {2, 2});
    return EXIT_SUCCESS;
}
