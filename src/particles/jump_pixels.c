/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** jump particles
*/

#include <stdlib.h>
#include <math.h>
#include "particles.h"

int create_jump_pixels(tpe_part_t *tpe_part, sfColor color, float max_height)
{
    jump_pixels_t *jump_pixels = malloc(sizeof(jump_pixels_t) * MAX_PARTICLES);

    tpe_part->jump_pixels = jump_pixels;
    if (jump_pixels == NULL)
        return EXIT_ERROR;
    for (int i = 0; i < MAX_PARTICLES; i++) {
        jump_pixels[i].coord = (sfVector2f) {0, 0};
        jump_pixels[i].height = 0;
        jump_pixels[i].start_height = 0;
        jump_pixels[i].end_height = max_height;
        jump_pixels[i].color = color;
    }
    return EXIT_SUCCESS;
}

int draw_jump_pixels(particles_pack_t *pack)
{
    jump_pixels_t *jmp_pix = NULL;

    for (int i = 0; i < MAX_PARTICLES; i++) {
        jmp_pix = &pack->tpe_part.jump_pixels[i];
        my_draw_rect(pack->framebuffer, (sfVector2f) {jmp_pix->coord.x,
            jmp_pix->coord.y - jmp_pix->height}, (sfVector2f) {2, 2},
            sfTransparent);
        if (sfClock_getElapsedTime(pack->clock).microseconds > 40000) {
            jmp_pix->height++;
            if (jmp_pix->height > jmp_pix->end_height || (rand() % 8) == 1)
                jmp_pix->height = jmp_pix->start_height;
        }
        my_draw_rect(pack->framebuffer, (sfVector2f) {jmp_pix->coord.x,
            jmp_pix->coord.y - jmp_pix->height}, (sfVector2f) {2, 2},
            jmp_pix->color);
    }
    if (sfClock_getElapsedTime(pack->clock).microseconds > 40000)
        sfClock_restart(pack->clock);
    return EXIT_SUCCESS;
}

void destroy_jump_pixels(tpe_part_t tpe_part)
{
    free(tpe_part.jump_pixels);
}

void set_pos_jump_pixels(tpe_part_t *tpe_part, sfVector2f coord, int radius)
{
    for (int i = 0; i < MAX_PARTICLES; i++) {
        tpe_part->jump_pixels[i].coord.x = coord.x
            - radius + (rand() % (radius * 2));
        tpe_part->jump_pixels[i].coord.y = coord.y
            + radius + (rand() % (radius * 2));
    }
}