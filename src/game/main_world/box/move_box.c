/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_box
*/

#include "my_rpg.h"

static void quest_manage(game_t *game)
{
    sfVector2i box_dest = {42, 32};

    if (QUEST.is_active[8] == true) {
        if (check_box_on_pos(game, &box_dest, 1)) {
            quest_finish(game, 8, false);
        }
    }
}

static bool check_move_box(game_t *game, enum direction dir,
sfVector2i pos)
{
    if (dir == UP && pos.y - 2 >= 0) {
        dir_up(game, pos);
        return true;
    } else if (dir == DOWN && pos.y + 2 < WMAIN->size_map.y) {
        dir_down(game, pos);
        return true;
    }
    if (dir == LEFT && pos.x - 2 >= 0) {
        dir_left(game, pos);
        return true;
    } else if (dir == RIGHT && pos.y + 2 < WMAIN->size_map.x) {
        dir_right(game, pos);
        return true;
    }
    return false;
}

int move_box(game_t *game, enum direction dir)
{
    sfVector2i pos = {0};

    pos.x = ceil(WMAIN->position_on_map.x) - 1;
    pos.y = ceil(WMAIN->position_on_map.y) - 1;
    if (check_move_box(game, dir, pos)) {
        quest_manage(game);
    }
    return EXIT_SUCCESS;
}
