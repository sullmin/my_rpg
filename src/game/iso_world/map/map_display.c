/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** draw_2d_map
*/

#include "my_rpg.h"

extern const float MAP_SHADOW_SUM;
extern const float MAP_SHADOW_MUL;

static int get_delta(int **map_3d, int x, int y, int size)
{
    if (x == size - 1 || y == 0)
        return 0;
    if (map_3d[y][x] > map_3d[y][x + 1] &&
        map_3d[y - 1][x] > map_3d[y - 1][x + 1])
        return (map_3d[y][x] + MAP_SHADOW_SUM) * MAP_SHADOW_MUL;
    if (map_3d[y][x] > map_3d[y][x + 1] &&
        map_3d[y + 1][x] > map_3d[y + 1][x + 1])
        return (map_3d[y][x] + MAP_SHADOW_SUM) * MAP_SHADOW_MUL;
    return 0;
}

static void map_display_last_line(sfRenderWindow *win, map_t *map)
{
    for (int i = 0; i < map->width - 1; i++) {
        sfRenderWindow_drawVertexArray(win, map->vrtx_x[map->height - 1][i],
        NULL);
    }
    for (int i = 0; i < map->height - 1; i++) {
        sfRenderWindow_drawVertexArray(win, map->vrtx_y[i][map->width - 1],
        NULL);
    }
}

void display_texture(sfRenderWindow *win, map_t *map, sfVector2i p, int v)
{
    int delta = get_delta(map->map_3d, p.x, p.y, map->width);

    map->render_state.texture = map->textures[map->texture_const[p.y][p.x]];
    if (v == 1) {
    sfRenderWindow_drawVertexArray(win, map->txtr_vrtx_a[p.y][p.x],
                                    &map->render_state);
        for (int i = 0; i < delta; i++)
            sfRenderWindow_drawVertexArray(win,
            map->txtr_vrtx_a[p.y][p.x], &map->rs_black);
    }
    else if (v == 2) {
        sfRenderWindow_drawVertexArray(win, map->txtr_vrtx_b[p.y][p.x],
                                        &map->render_state);
        for (int i = 0; i < delta; i++) {
            sfRenderWindow_drawVertexArray(win,
            map->txtr_vrtx_b[p.y][p.x], &map->rs_black);
        }
    }
}

void display_line(sfRenderWindow *win, map_t *map, int x, int y)
{
    sfRenderWindow_drawVertexArray(win, map->vrtx_x[y][x], NULL);
    sfRenderWindow_drawVertexArray(win, map->vrtx_y[y][x], NULL);
}

int map_display(isow_t *isow, map_t *map, sfRenderWindow *window)
{
    if (map->modified)
        map_update_all(isow, map);
    for (int x = 0; x < map->width - 1; x++) {
        for (int y = 0; y < map->height - 1; y++) {
            display_texture(window, map, (sfVector2i){x, y}, 1);
            display_line(window, map, x, y);
                display_texture(window, map, (sfVector2i){x, y}, 2);
            if (isow->map.map_3d[y][x] < isow->map_water.map_3d[y][x]) {
                display_texture_water(window, &isow->map_water,
                (sfVector2i){x, y});
            }
        }
    }
    map_display_last_line(window, map);
    return EXIT_SUCCESS;
}
