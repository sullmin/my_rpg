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

const int jmpix_max_par = 30;

int create_jump_pixels(particles_pack_t *pack, sfColor color, float max_height)
{
    jump_pixels_t *jump_pixels = malloc(sizeof(jump_pixels_t) * jmpix_max_par);

    pack->tpe_part.jump_pixels = jump_pixels;
    if (jump_pixels == NULL)
        return EXIT_ERROR;
    for (int i = 0; i < jmpix_max_par; i++) {
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
    bool restart = false;

    for (int i = 0; i < jmpix_max_par; i++) {
        my_draw_rect(pack->framebuffer, (sfVector2f) {JMP_PIX(i).coord.x,
            JMP_PIX(i).coord.y - JMP_PIX(i).height}, (sfVector2f) {2, 2},
            sfTransparent);
        if (sfClock_getElapsedTime(pack->clock).microseconds > 40000) {
            JMP_PIX(i).height++;
            if (JMP_PIX(i).height > JMP_PIX(i).end_height || (rand() % 8) == 1)
                JMP_PIX(i).height = JMP_PIX(i).start_height;
            restart = true;
        }
        my_draw_rect(pack->framebuffer, (sfVector2f) {JMP_PIX(i).coord.x,
            JMP_PIX(i).coord.y - JMP_PIX(i).height}, (sfVector2f) {2, 2},
            JMP_PIX(i).color);
    }
    if (restart)
        sfClock_restart(pack->clock);
    return EXIT_SUCCESS;
}

void destroy_jump_pixels(tpe_part_t tpe_part)
{
    free(tpe_part.jump_pixels);
}

void set_pos_jump_pixels(tpe_part_t *tpe_part, sfVector2f coord, int radius)
{
    for (int i = 0; i < jmpix_max_par; i++) {
        tpe_part->jump_pixels[i].coord.x = coord.x
            - radius + (rand() % (radius * 2));
        tpe_part->jump_pixels[i].coord.y = coord.y
            + radius + (rand() % (radius * 2));
    }
}