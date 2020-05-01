/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

static const sfInt32 INIT_SPEED_PNJ = 1000;

const size_t SIZE_LIST_PNJ = 9;
static const pnj_plan_t LIST_PNJ[] = {
    {
        .position = {65, 32},
        .is_hostile = true,
        .path_sprite = "./asset/sprite/enemy.png"
    },
    {
        .position = {44, 49},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_barbe.png"
    },
    {
        .position = {44, 34},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_barbe2.png"
    },
    {
        .position = {47, 62},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_x.png"
    },
    {
        .position = {40, 71},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_y.png"
    },
    {
        .position = {39, 39},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_x.png"
    },
    {
        .position = {66, 15},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_x.png"
    },
    {
        .position = {62, 15},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_x.png"
    },
    {
        .position = {28, 41},
        .is_hostile = false,
        .path_sprite = "./asset/sprite/pnj_x.png"
    }
};

static int movement_pnj_creat(chara_animation_t *mov, size_t idx)
{
    mov->sprite = sfSprite_create();
    mov->texture = sfTexture_createFromFile(LIST_PNJ[idx].path_sprite, NULL);
    if (!mov->texture) {
        return EXIT_ERROR;
    }
    for (size_t i = 0; i < 4; i++)
        mov->orient[i] = false;
    mov->orient[3] = true;
    mov->in_move = true;
    mov->is_static = false;
    mov->clock = sfClock_create();
    mov->count = 1;
    mov->timer = 0;
    mov->rec = (sfIntRect) {0, 0, 32, 65};
    sfSprite_setPosition(mov->sprite, (sfVector2f) {1136, 368});
    sfSprite_setTexture(mov->sprite, mov->texture, sfTrue);
    sfSprite_setScale(mov->sprite, (sfVector2f) {2, 2});
    return EXIT_SUCCESS;
}

static int init_pnj(pnj_t *pnj, size_t idx)
{
    pnj->clock = sfClock_create();
    pnj->fpos = (sfVector2i) {-1, 0};
    pnj->timer = 0;
    pnj->ms_loop = INIT_SPEED_PNJ;
    pnj->pos.x = LIST_PNJ[idx].position.x;
    pnj->pos.y = LIST_PNJ[idx].position.y;
    pnj->go_act = true;
    pnj->is_hostile = LIST_PNJ[idx].is_hostile;
    pnj->nb_interaction = 0;
    if (movement_pnj_creat(&pnj->move, idx) != EXIT_SUCCESS)
        return EXIT_ERROR;
    built_it(&pnj->move, 1);
    return EXIT_SUCCESS;
}

bool init_all_pnj(pnj_manage_t *pnj_man, env_t *env)
{
    bool err = false;

    pnj_man->nb_pnj = my_env_get_value_int(env, "NB_PNJ", &err);
    if (pnj_man->nb_pnj > SIZE_LIST_PNJ) {
        my_putstr_error("WARNING: NB_PNJ greater than SIZE of array\n");
        pnj_man->nb_pnj = SIZE_LIST_PNJ;
    }
    pnj_man->all_pnj = malloc(sizeof(pnj_t) * pnj_man->nb_pnj);
    if (!pnj_man->all_pnj || err)
        return false;
    pnj_man->activate = false;
    for (size_t i = 0; i < pnj_man->nb_pnj; i++) {
        if (init_pnj(&pnj_man->all_pnj[i], i) == EXIT_ERROR)
            return false;
    }
    pnj_man->all_pnj[2].move.is_static = true;
    pnj_man->all_pnj[6].move.is_static = true;
    return true;
}

void destroy_pnj(pnj_manage_t *pnj_man)
{
    for (size_t i = 0; i < pnj_man->nb_pnj; i++) {
        sfSprite_destroy(pnj_man->all_pnj[i].move.sprite);
        sfTexture_destroy(pnj_man->all_pnj[i].move.texture);
        sfClock_destroy(pnj_man->all_pnj[i].clock);
        sfClock_destroy(pnj_man->all_pnj[i].move.clock);
    }
}

void display_all_pnj(game_t *game)
{
    for (size_t i = 0; i < game->wmain->pnj_man.nb_pnj; i++)
        simple_pnj_move(&game->wmain->pnj_man.all_pnj[i], game);
}
