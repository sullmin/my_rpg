/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"
#include "particles.h"

const sfVector2i toilets_parts[] = {
    {28, 27},
    {32, 27},
    {36, 27},
    {40, 27},
    {48, 27},
    {52, 27},
    {56, 27},
    {28, 37},
    {32, 37},
    {40, 37},
    {44, 37},
    {48, 37},
    {56, 37},
    {60, 37}
};

static bool is_display_part(sfVector2i pos, game_t *game)
{
    int x = pos.x * 16;
    int y = pos.y * 16;

    if (x > game->wmain->rect.left &&
        x < game->wmain->rect.left + game->wmain->rect.width)
        if (y > game->wmain->rect.top &&
            y < game->wmain->rect.top + game->wmain->rect.height)
            return true;
    return false;
}

void display_particule(game_t *game)
{
    sfVector2f fin = {0};

    for (size_t i = 0; i < 14; i++) {
        if (is_display_part(toilets_parts[i], game)) {
            fin.x = (toilets_parts[i].x + 0.5 - PLAYER.x) * 64 + 984;
            fin.y = (toilets_parts[i].y + 0.2 - PLAYER.y) * 64 + 550;
            set_particles_pos(WMAIN->effect[i], fin, 10);
            draw_particles(WMAIN->effect[i]);
            update_particles(WMAIN->effect[i], game->w);
        }
    }
}

bool init_particles_effect(game_t *game)
{
    for (size_t i = 0; i < 14; i++) {
        WMAIN->effect[i] = create_particles(game->w, 1, sfBlue, 2);
        if (!WMAIN->effect[i])
            return false;
    }
    return true;
}

void destroy_particles_effct(game_t *game)
{
    for (size_t i = 0; i < 14; i++)
        destroy_particles(WMAIN->effect[i]);
}