/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-15T09:13:14+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const int MAP_INIT_HEIGHT;
extern const int MAP_INIT_WIDTH;
extern const sfInt32 MS_UPDATE_PANEL;

static const char *PLAYER_TXR[3] = {
    "asset/sprite/iso_world/real_black.png",
    "asset/sprite/iso_world/red.png",
    "asset/sprite/iso_world/blue.png"
};

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
    if (object_create(&isow->player, NULL, NULL, PLAYER_TXR))
        return EXIT_ERROR;
    object_set_size(&isow->player, 0, 0, isow->map.sampling.x);
    object_on_map_set_coord(&isow->player, &isow->map, 1, 1);
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
