/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** particles
*/

#include <stdlib.h>
#include "particles.h"
#include "window_t.h"

int (* const create_func_id[MAX_ID])(particles_pack_t *pack,
                                    sfColor color, float value) = {
    create_jump_pixels,
    create_sand
};

int (* const draw_func_id[MAX_ID])(particles_pack_t *pack) = {
    draw_jump_pixels,
    draw_sand
};

void (* const destroy_func_id[MAX_ID])(tpe_part_t tpe_part) = {
    destroy_jump_pixels,
    destroy_sand
};

void (* const set_pos_func_id[MAX_ID])(particles_pack_t *pack, sfVector2f pos,
                                        int radius) = {
    set_pos_jump_pixels
};

particles_pack_t *create_particles(window_t window, int const id,
                                sfColor color, float value)
{
    particles_pack_t *pack = malloc(sizeof(particles_pack_t));

    if (pack == NULL || id <= 0 || id > MAX_ID)
        return NULL;
    pack->id = id;
    pack->texture = sfTexture_create(window.width, window.height);
    pack->sprite = sfSprite_create();
    pack->framebuffer = framebuffer_create(window.width, window.height);
    pack->clock = sfClock_create();
    if (!pack->texture || !pack->framebuffer || !pack->sprite || !pack->clock
    || create_func_id[id - 1](pack, color, value) == EXIT_ERROR)
        return NULL;
    sfSprite_setTexture(pack->sprite, pack->texture, sfTrue);
    return pack;
}

int draw_particles(particles_pack_t *pack)
{
    return draw_func_id[pack->id - 1](pack);
}

void destroy_particles(particles_pack_t *pack)
{
    sfTexture_destroy(pack->texture);
    framebuffer_destroy(pack->framebuffer);
    sfClock_destroy(pack->clock);
    destroy_func_id[pack->id - 1](pack->tpe_part);
    free(pack);
}

void set_particles_pos(particles_pack_t *pack, sfVector2f pos, int radius)
{
    set_pos_func_id[pack->id - 1](pack, pos, radius);
}

void update_particles(particles_pack_t *pack, window_t win)
{
    sfTexture_updateFromPixels(pack->texture, pack->framebuffer->pixels,
        pack->framebuffer->width, pack->framebuffer->height, 0, 0);
    sfRenderWindow_drawSprite(win.window, pack->sprite, NULL);
}