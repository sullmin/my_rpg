/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_texture_vertex_destroy
*/

#include "my_rpg.h"

void map_vertex_texture_destroy(map_t *map)
{
    for (int y = 0; y < map->height - 1; y++) {
        for (int x = 0; x < map->width - 1; x++) {
            sfVertexArray_destroy(map->txtr_vrtx_a[y][x]);
            sfVertexArray_destroy(map->txtr_vrtx_b[y][x]);
        }
        free(map->txtr_vrtx_a[y]);
        free(map->txtr_vrtx_b[y]);
    }
    free(map->txtr_vrtx_a);
    free(map->txtr_vrtx_b);
}