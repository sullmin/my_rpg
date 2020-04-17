/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Created: 2020-03-05T14:51:13+01:00 | Author: SimonRacaud
*/

#include "my_rpg.h"

static bool is_valid_map_coord(sfVector2i *coord, map_t *map)
{
    if (coord->x >= map->width - 1)
        return false;
    else if (coord->x < 0)
        return false;
    if (coord->y >= map->height - 1)
        return false;
    else if (coord->y < 0)
        return false;
    return true;
}

static bool check_coord(sfVector2i *coord, map_t *map)
{
    sfVector2i coord_diag = {coord->x + 1, coord->y + 1};

    if (!is_valid_map_coord(coord, map)) {
        return false;
    }
    if (map->map_3d[coord->y][coord->x] <= 0) {
        return false;
    }
    if (is_valid_map_coord(&coord_diag, map)) {
        if (map->map_3d[coord_diag.y][coord_diag.x] <= 0) {
            return false;
        }
        if (map->map_3d[coord->y][coord->x]
            - map->map_3d[coord_diag.y][coord_diag.x]
            > (map->sampling.x / 3)) {
            return false;
        }
    }
    return true;
}

int object_on_map_move(object_t *obj, map_t *map, int x, int y)
{
    sfVector2i new_coord;

    if (!obj || !map)
        return EXIT_FAILURE;
    new_coord.x = obj->coord_map.x + x;
    new_coord.y = obj->coord_map.y + y;
    if (check_coord(&new_coord, map) == false) {
        return EXIT_SUCCESS;
    }
    obj->coord_map = new_coord;
    object_on_map_refresh(obj, map);
    return EXIT_SUCCESS;
}
