/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-01T14:13:00+02:00 | Author: simon
*/

#include "my_rpg.h"
#include "fight.h"

static const float INIT_SPEED = 0.8;
static const int INIT_ACTIONS = 10;
static const float INIT_INTERVAL = 2400;
static const float MAX_INTERVAL = 3000;
static const int INIT_COMBO = 3;

static void config_actions(stat_t *player_stat,
fight_mode_t *config)
{
    config->actions = INIT_ACTIONS - player_stat->iq;
    config->actions += ((100 - player_stat->health) / 10);
    if (config->actions <= 0) {
        config->actions = 1;
    }
}

fight_mode_t fight_get_config(game_t *game)
{
    stat_t player_stat = get_player_stat(game);
    fight_mode_t config;
    float speed_div = ((float)player_stat.speed);

    if (speed_div == 0)
        speed_div = 1;
    config.speed = INIT_SPEED / (speed_div / 2);
    config.interval = INIT_INTERVAL + (player_stat.agility * 50);
    if (config.interval >= MAX_INTERVAL)
        config.interval = MAX_INTERVAL;
    config.comb = INIT_COMBO - (player_stat.resistance / 10);
    config.comb -= (player_stat.strength / 10);
    if (config.comb <= 0) {
        config.comb = 1;
    }
    config_actions(&player_stat, &config);
    return config;
}
