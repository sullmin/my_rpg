/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-01T10:51:53+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const sfVector2f PLAYER_POSITION;

int player_display_hitbox_create(game_t *game)
{
    char *path_img = GET_VAR(game, "PATH_HITBOX_DEBUG");

    if (!path_img)
        return EXIT_ERROR;
    WMAIN->player_hitbox_txr = sfTexture_createFromFile(path_img, NULL);
    if (!WMAIN->player_hitbox_txr)
        return EXIT_ERROR;
    WMAIN->player_hitbox_spr = sfSprite_create();
    sfSprite_setColor(WMAIN->player_hitbox_spr, (sfColor) {255, 0, 0, 150});
    sfSprite_setScale(WMAIN->player_hitbox_spr, (sfVector2f) {2, 2});
    sfSprite_setTexture(WMAIN->player_hitbox_spr, WMAIN->player_hitbox_txr,
    true);
    for (size_t i = 0; i < 4; i++) {
        WMAIN->player_hitbox_pos[i] = (sfVector2i) {-1, -1};
    }
    return EXIT_SUCCESS;
}

sfVector2f coord_to_position(game_t *game, sfVector2i coord)
{
    sfVector2f position;
    sfVector2i delta;

    delta.x = WMAIN->pos_on_map_int.x - coord.x;
    delta.y = WMAIN->pos_on_map_int.y - coord.y;
    position = PLAYER_POSITION;
    position.x -= delta.x * 64;
    position.y -= delta.y * 64;
    return position;
}

void player_display_hitbox(game_t *game)
{
    sfVector2f position;

    for (size_t i = 0; i < 4; i++) {
        if (WMAIN->player_hitbox_pos[i].x == -1
            || WMAIN->player_hitbox_pos[i].y == -1) {
            continue;
        }
        position = coord_to_position(game, WMAIN->player_hitbox_pos[i]);
        sfSprite_setPosition(WMAIN->player_hitbox_spr, position);
        sfRenderWindow_drawSprite(WINDOW, WMAIN->player_hitbox_spr, NULL);
    }
}
