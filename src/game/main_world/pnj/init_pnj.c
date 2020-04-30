/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

static const sfInt32 INIT_SPEED_PNJ = 1000;

static void movement_pnj_creat(chara_animation_t *mov,
    sfSprite *sprite, sfTexture *texture)
{
    mov->sprite = sprite;
    mov->texture = texture;
    for (size_t i = 0; i < 4; i++)
        mov->orient[i] = false;
    mov->orient[3] = true;
    mov->in_move = true;
    mov->clock = sfClock_create();
    mov->count = 1;
    mov->timer = 0;
    mov->rec = (sfIntRect) {0, 0, 32, 65};
}

static void init_pnj(pnj_t *pnj, sfVector2i pos,
    sfSprite *sprite, sfTexture *texture)
{
    pnj->clock = sfClock_create();
    pnj->fpos = (sfVector2i) {-1, 0};
    pnj->timer = 0;
    pnj->ms_loop = INIT_SPEED_PNJ;
    pnj->pos.x = pos.x;
    pnj->pos.y = pos.y;
    pnj->go_act = true;
    movement_pnj_creat(&pnj->move, sprite, texture);
    built_it(&pnj->move, 1);
}

void destroy_pnj(pnj_manage_t *pnj_man)
{
    sfSprite_destroy(pnj_man->all_pnj[0].move.sprite);
    sfTexture_destroy(pnj_man->all_pnj[0].move.texture);
    for (size_t i = 0; i < pnj_man->nb_pnj; i++) {
        sfClock_destroy(pnj_man->all_pnj[i].clock);
        sfClock_destroy(pnj_man->all_pnj[i].move.clock);
    }
}

bool init_all_pnj(pnj_manage_t *pnj_man, env_t *env)
{
    bool err = false;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("./asset/sprite/enemy.png",
        NULL);
    sfVector2i pos[] = {(sfVector2i) {65, 32}, (sfVector2i) {44, 49},
                        (sfVector2i) {43, 35}, (sfVector2i) {47, 62},
                        (sfVector2i) {40, 71}
                        };

    pnj_man->nb_pnj = my_env_get_value_int(env, "NB_PNJ", &err);
    pnj_man->all_pnj = malloc(sizeof(pnj_t) * pnj_man->nb_pnj);
    if (!pnj_man->all_pnj || !sprite || !texture)
        return false;
    pnj_man->activate = false;
    sfSprite_setPosition(sprite, (sfVector2f) {1136, 368});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {2, 2});
    for (size_t i = 0; i < pnj_man->nb_pnj; i++)
        init_pnj(&pnj_man->all_pnj[i], pos[i], sprite, texture);
    return true;
}

void display_all_pnj(game_t *game)
{
    for (size_t i = 0; i < game->wmain->pnj_man.nb_pnj; i++)
        simple_pnj_move(&game->wmain->pnj_man.all_pnj[i], game);
}
