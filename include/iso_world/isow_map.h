/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map
*/

#ifndef ISOW_MAP_H_
#define ISOW_MAP_H_

#include "isow_map_t.h"

// MAIN FUNCTIONS
int map_create(map_t *map, int height, int width);
int map_display(isow_t *isow, map_t *map, sfRenderWindow *window);
void display_texture_water(sfRenderWindow *window, map_t *map, sfVector2i p);

void map_destroy(map_t *map);
int map_update(map_t *map);
int map_update_all(isow_t *isow, map_t *map);

int **create_3d_map(int height, int width);
void destroy_3d_map(int **map_3d, int height);

int create_2d_map(map_t *map);
sfVector2f project_iso_point(int x, int y, int z, map_t *map);
void destroy_2d_map(sfVector2f **map_2d, int height);

int map_vertex_create(map_t *map);
void map_vertex_destroy(map_t *map);

// TEXTURE
int map_vertex_texture_create(map_t *map);
void map_vertex_texture_destroy(map_t *map);
void map_texture_destroy(map_t *map);
int map_texture_create(map_t *map);
int map_texture_set_height(map_t *map);

// VIEW TOOLS
int map_scale_all(isow_t *isow, float scale);
int map_scale(map_t *map, float scale);
int map_translate(map_t *map, float deltax, float deltay);
int map_rotate(map_t *map, float anglex, float angley);
int map_set_angley(map_t *map, float angley);
int map_set_anglex(map_t *map, float anglex);
int map_reset(map_t *map);
int map_resize(map_t *map, sfVector2i resize);
int map_resize_all(isow_t *isow, sfVector2i resize);

// FILE MAP
int load_map(const char *filepath, map_t *map);
int fill_map(map_t *map_load, char *data);
int fill_map_texture(map_t *map_load, char *data);

#endif
