/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** jump particles
*/

#include <stdlib.h>
#include <math.h>
#include "particles.h"

const int sand_max_par = 1000;

int create_sand(particles_pack_t *pack, sfColor color, float size)
{
    sand_t *sand = malloc(sizeof(sand_t) * sand_max_par);
    float rand_angle = rand() % 360;

    if (sand == NULL)
        return EXIT_ERROR;
    pack->tpe_part.sand = sand;
    for (int i = 0; i < sand_max_par; i++) {
        sand[i].coord = (sfVector2f) {rand() % pack->framebuffer->width,
                                    rand() % pack->framebuffer->height};
        sand[i].color = color;
        sand[i].angle = rand_angle;
        sand[i].size = size;
    }
    return EXIT_SUCCESS;
}

static void check_over_screen(sfVector2f *coord,
                            unsigned int width, unsigned int height)
{
    if (coord->x > width)
        coord->x = 1;
    if (coord->x < 0)
        coord->x = width - 1;
    if (coord->y > height)
        coord->y = 1;
    if (coord->y < 0)
        coord->y = height - 1;
}

int draw_sand(particles_pack_t *pack)
{
    float ms = sfClock_getElapsedTime(pack->clock).microseconds / 10000;
    float rand_angle = RAND(7, 7);

    for (int i = 0; i < sand_max_par; i++) {
        my_draw_rect(pack->framebuffer, (sfVector2f) {SAND(i).coord.x,
                    SAND(i).coord.y}, (sfVector2f) {2, 2}, sfTransparent);
        SAND(i).angle = SAND(i).angle + rand_angle;
        SAND(i).coord.x += ms * cos(SAND(i).angle * M_PI / 180);
        SAND(i).coord.y += ms * sin(SAND(i).angle * M_PI / 180);
        check_over_screen(&SAND(i).coord, pack->framebuffer->width,
                        pack->framebuffer->height);
        my_draw_rect(pack->framebuffer, SAND(i).coord,
                    (sfVector2f) {SAND(i).size, SAND(i).size}, SAND(i).color);
    }
    sfClock_restart(pack->clock);
    return EXIT_SUCCESS;
}

void destroy_sand(tpe_part_t tpe_part)
{
    free(tpe_part.sand);
}