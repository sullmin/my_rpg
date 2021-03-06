/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_update
*/

#include "my_rpg.h"

int map_update_all(isow_t *isow, map_t *map)
{
    if (map_update(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    map->modified = sfFalse;
    if (map_update(&isow->map_water) == EXIT_FAILURE)
        return EXIT_FAILURE;
    isow->map_water.modified = sfFalse;
    object_on_map_refresh(&isow->prison, map);
    object_on_map_refresh(&isow->player, &isow->map);
    return EXIT_SUCCESS;
}

int map_update(map_t *map)
{
    destroy_2d_map(map->map_2d, map->height);
    if (create_2d_map(map))
        return EXIT_FAILURE;
    if (!map->map_2d)
        return EXIT_FAILURE;
    map_vertex_destroy(map);
    if (map_vertex_create(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    map_vertex_texture_destroy(map);
    if (map_vertex_texture_create(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
