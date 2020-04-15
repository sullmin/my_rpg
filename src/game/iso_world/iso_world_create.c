/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-15T09:13:14+02:00 | Author: simon
*/

#include "isow.h"

extern const int MAP_INIT_HEIGHT;
extern const int MAP_INIT_WIDTH;
extern const sfInt32 MS_UPDATE_PANEL;

static const char *PLAYER_TXR[3] = {
    "asset/img/real_black.png",
    "asset/img/red.png",
    "asset/img/blue.png"
};

static int create_clock(isow_t *isow)
{
    ISOW.timer = 0;
    ISOW.ms_loop = MS_UPDATE_PANEL;
    ISOW.clock = sfClock_create();
    if (!ISOW.clock)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int create_player(isow_t *isow)
{
    if (object_create(&ISOW.player, NULL, NULL, PLAYER_TXR))
        return EXIT_ERROR;
    object_set_size(&ISOW.player, 0, 0, ISOW.map.sampling.x);
    object_on_map_set_coord(&ISOW.player, &ISOW.map, 1, 1);
    return EXIT_SUCCESS;
}

int isow_create(isow_t *isow)
{
    if (map_create(&ISOW.map_water, MAP_INIT_HEIGHT, MAP_INIT_WIDTH) != 0)
        return EXIT_ERROR;
    if (map_create(&ISOW.map, MAP_INIT_HEIGHT, MAP_INIT_WIDTH) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_clock(isow) == EXIT_ERROR)
        return EXIT_ERROR;
    if (create_player(isow) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (load_map("./asset/map/iso.world", &iso->map) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
