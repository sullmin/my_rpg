/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "particles.h"
#include "my_rpg.h"

const sfVector2i toilets_parts[] = {
    {28, 26},
    {32, 26},
    {36, 26},
    {40, 26},
    {52, 26},
    {56, 26},
    {28, 36},
    {32, 36},
    {40, 36},
    {44, 36},
    {48, 36},
    {56, 36},
    {60, 36}
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

    for (size_t i = 0; i < 13; i++) {
        if (is_display_part(toilets_parts[i], game)) {
            fin.x = (toilets_parts[i].x + 0.5 - PLAYER.x) * 64 + 984;
            fin.y = (toilets_parts[i].y + 1.2 - PLAYER.y) * 64 + 550;
            set_particles_pos(WMAIN->effect[i], fin, 10);
            draw_particles(WMAIN->effect[i]);
            update_particles(WMAIN->effect[i], game->w);
        }
    }
}

bool init_particles_effect(game_t *game)
{
    for (size_t i = 0; i < 13; i++) {
        WMAIN->effect[i] = create_particles(game->w, 1, sfBlue, 10);
        if (!WMAIN->effect[i])
            return false;
    }
    return true;
}

void destroy_particles_effct(game_t *game)
{
    for (size_t i = 0; i < 13; i++)
        destroy_particles(WMAIN->effect[i]);
}