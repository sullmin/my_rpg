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

static const sfVector3f PLAYER_TXR_SIZE = {32, 86, 32};

static int create_clock(isow_t *isow)
{
    isow->timer = 0;
    isow->ms_loop = MS_UPDATE_PANEL;
    isow->clock = sfClock_create();
    if (!isow->clock)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int create_player(isow_t *isow)
{
    if (object_create(&isow->player, PLAYER_TXR_SIZE, NULL, PLAYER_TXR))
        return EXIT_ERROR;
    object_set_size(&isow->player, isow->map.sampling.x, isow->map.sampling.y, isow->map.sampling.x * 2);
    object_on_map_set_coord(&isow->player, &isow->map, 18, 18);

    //object_set_size(&isow->player, isow->map.sampling.x * 20, isow->map.sampling.y * 20, isow->map.sampling.x * 10);
    //object_on_map_set_coord(&isow->player, &isow->map, 0, 0);
    return EXIT_SUCCESS;
}

int isow_create(isow_t *isow)
{
    if (map_create(&isow->map, 1, 1) == EXIT_ERROR)
        return EXIT_ERROR;
    if (load_map("./asset/map/iso.world", &isow->map) == EXIT_ERROR)
        return EXIT_ERROR;
    if (map_create(&isow->map_water, isow->map.height, isow->map.width) != 0)
        return EXIT_ERROR;
    if (create_clock(isow) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_player(isow) != EXIT_SUCCESS)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
