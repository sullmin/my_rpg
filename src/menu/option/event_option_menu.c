/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_option_menu
*/

#include "my_rpg.h"

static const int azerty[] = {sfKeyZ, sfKeyQ, sfKeyS, sfKeyD};
static const int qwerty[] = {sfKeyW, sfKeyA, sfKeyS, sfKeyD};
static const int keypad[] = {sfKeyUp, sfKeyLeft, sfKeyBack, sfKeyRight};

static void event_azerty_button(game_t *game)
{
    event_button(game->option_menu->azerty, game->w.window);
    if (game->option_menu->azerty->is_activate == true) {
        game->option_menu->azerty->toggle = 2;
        game->option_menu->qwerty->is_activate = false;
        game->option_menu->keypad->is_activate = false;
        set_keyboard_config(game->option, azerty);
    }
}

static void event_qwerty_button(game_t *game)
{
    event_button(game->option_menu->qwerty, game->w.window);
    if (game->option_menu->qwerty->is_activate == true) {
        game->option_menu->qwerty->toggle = 2;
        game->option_menu->azerty->is_activate = false;
        game->option_menu->keypad->is_activate = false;
        set_keyboard_config(game->option, qwerty);
    }
}

static void event_keypad_button(game_t *game)
{
    event_button(game->option_menu->keypad, game->w.window);
    if (game->option_menu->keypad->is_activate == true) {
        game->option_menu->keypad->toggle = 2;
        game->option_menu->azerty->is_activate = false;
        game->option_menu->qwerty->is_activate = false;
        set_keyboard_config(game->option, keypad);
    }
}

void event_option_menu(game_t *game, sfEvent *event)
{
    event_button(game->option_menu->main_menu, game->w.window);
    if (game->option_menu->main_menu->toggle == 2)
        game->state = MAIN_MENU;
    event_azerty_button(game);
    event_qwerty_button(game);
    event_keypad_button(game);
    event_slider(game->option_menu->sound, sfMouse_getPositionRenderWindow(game->w.window));
    game->option->volume = get_value_slider(game->option_menu->sound) * 100;
}
