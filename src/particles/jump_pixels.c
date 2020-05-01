/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** jump particles
*/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "particles.h"

const int jmpix_max_par = 15;

int create_jump_pixels(particles_pack_t *pack, sfColor color, float size)
{
    jump_pixels_t *jump_pixels = malloc(sizeof(jump_pixels_t) * jmpix_max_par);

    pack->tpe_part.jump_pixels = jump_pixels;
    if (jump_pixels == NULL)
        return EXIT_ERROR;
    for (int i = 0; i < jmpix_max_par; i++) {
        jump_pixels[i].coord = (sfVector2f) {0, 0};
        jump_pixels[i].size = size;
        jump_pixels[i].color = color;
    }
    return EXIT_SUCCESS;
}

int draw_jump_pixels(particles_pack_t *pack)
{
    for (int i = 0; i < jmpix_max_par; i++)
        my_draw_rect(pack->framebuffer, JMP_PIX(i).coord, (sfVector2f)
            {JMP_PIX(i).size, JMP_PIX(i).size}, JMP_PIX(i).color);
    return EXIT_SUCCESS;
}

void destroy_jump_pixels(tpe_part_t tpe_part)
{
    free(tpe_part.jump_pixels);
}

void set_pos_jump_pixels(particles_pack_t *pack, sfVector2f coord, int radius)
{
    for (int i = 0; i < jmpix_max_par; i++) {
        my_draw_rect(pack->framebuffer, JMP_PIX(i).coord, (sfVector2f)
            {JMP_PIX(i).size, JMP_PIX(i).size}, sfTransparent);
        JMP_PIX(i).coord.x = coord.x - radius + (rand() % (radius * 2));
        JMP_PIX(i).coord.y = coord.y + radius + (rand() % (radius * 2));
    }
}