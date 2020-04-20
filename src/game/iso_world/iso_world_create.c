/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-15T09:13:14+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const sfInt32 MS_UPDATE_PANEL;

static const char *PLAYER_TXR[3] = {
    "asset/sprite/iso_world/player_head.png",
    "asset/sprite/iso_world/player.png",
    "asset/sprite/iso_world/player.png"
};

static const char *PRISON_TXR[3] = {
    "asset/sprite/iso_world/prison_up.png",
    "asset/sprite/iso_world/prison_right.png",
    "asset/sprite/iso_world/prison_left.png"
};

static const sfVector3f PLAYER_TXR_SIZE = {32, 86, 32};

static const sfVector3f PRISON_TXR_SIZE = {250, 200, 230};

static int create_clock(isow_t *isow)
{
    isow->timer = 0;
    isow->ms_loop = MS_UPDATE_PANEL;
    isow->clock = sfClock_create();
    if (!isow->clock)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int create_objects(isow_t *isow)
{
    if (object_create(&isow->player, PLAYER_TXR_SIZE, NULL, PLAYER_TXR))
        return EXIT_ERROR;
    object_set_size(&isow->player, isow->map.sampling.x, isow->map.sampling.y,
    isow->map.sampling.x * 2);
    object_on_map_set_coord(&isow->player, &isow->map, 20, 28);
    if (object_create(&isow->prison, PRISON_TXR_SIZE, NULL, PRISON_TXR))
        return EXIT_ERROR;
    object_set_size(&isow->prison, isow->map.sampling.x * 23,
    isow->map.sampling.y * 25, isow->map.sampling.x * 14);
    object_on_map_set_coord(&isow->prison, &isow->map, 0, 0);
    isow->event.player_move = false;
    return EXIT_SUCCESS;
}

int isow_create(game_t *game)
{
    if (map_create(&ISOW.map, 1, 1) == EXIT_ERROR)
        return EXIT_ERROR;
    if (load_map("./asset/map/iso.world", &ISOW.map) == EXIT_ERROR)
        return EXIT_ERROR;
    if (map_create(&ISOW.map_water, ISOW.map.height, ISOW.map.width) != 0)
        return EXIT_ERROR;
    if (create_clock(&ISOW) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_objects(&ISOW) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (kinem_create(&ISOW) != EXIT_SUCCESS) {
        return EXIT_ERROR;
    }
    if (kinem_start(&ISOW, &game->sound) != EXIT_SUCCESS)
        return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}
