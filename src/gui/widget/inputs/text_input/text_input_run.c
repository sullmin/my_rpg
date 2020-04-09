/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input
*/

#include "my_rpg.h"

extern const unsigned int TEXT_IN_INIT_CHAR_WIDTH;
extern const unsigned int TEXT_IN_INIT_WIN_FPS;
extern const unsigned int TEXT_IN_INIT_HEIGHT;
extern const int TEXT_IN_WIN_BPP;

static const sfKeyCode KEY_ENTER = 58;
static const sfKeyCode KEY_4 = 51;
static const sfKeyCode KEY_6 = 56;

static const char ASCII_KEY[] =
{
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '_'
};

static const sfKeyCode CSFML_KEY[] =
{
    sfKeyA,
    sfKeyB,
    sfKeyC,
    sfKeyD,
    sfKeyE,
    sfKeyF,
    sfKeyG,
    sfKeyH,
    sfKeyI,
    sfKeyJ,
    sfKeyK,
    sfKeyL,
    sfKeyM,
    sfKeyN,
    sfKeyO,
    sfKeyP,
    sfKeyQ,
    sfKeyR,
    sfKeyS,
    sfKeyT,
    sfKeyU,
    sfKeyV,
    sfKeyW,
    sfKeyX,
    sfKeyY,
    sfKeyZ,
    sfKeyNum0,
    sfKeyNum1,
    sfKeyNum2,
    sfKeyNum3,
    KEY_4,
    sfKeyNum5,
    KEY_6,
    sfKeyNum7,
    sfKeyNum8,
    sfKeyNum9,
    sfKeyNumpad0,
    sfKeyNumpad1,
    sfKeyNumpad2,
    sfKeyNumpad3,
    sfKeyNumpad4,
    sfKeyNumpad5,
    sfKeyNumpad6,
    sfKeyNumpad7,
    sfKeyNumpad8,
    sfKeyNumpad9,
    sfKeySpace
};

static const int KEY_ARRAY_SIZE = 47;

static int get_index(sfKeyCode code)
{
    for (int i = 0; i < KEY_ARRAY_SIZE; i++) {
        if (CSFML_KEY[i] == code) {
            return i;
        }
    }
    return (-1);
}

static void text_input_keypressed(text_in_t *in, sfKeyCode code)
{
    int index;

    if (code == sfKeyBack && in->i_buffer > 1) {
        in->i_buffer--;
        in->buffer[in->i_buffer] = '\0';
        sfText_setString(in->text, in->buffer);
    } else if (code == KEY_ENTER) {
        text_input_change_status(in);
    } else {
        index = get_index(code);
        if (index != -1 && in->i_buffer < (int)(in->max_char - 1)) {
            in->buffer[in->i_buffer++] = ASCII_KEY[index];
            in->buffer[in->i_buffer] = '\0';
            sfText_setString(in->text, in->buffer);
        }
    }
}

static void text_input_event_manager(text_in_t *in, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        text_input_change_status(in);
    } else if (event->type == sfEvtKeyPressed) {
        text_input_keypressed(in, event->key.code);
    }
}

int text_input_run(text_in_t *in)
{
    sfEvent event;

    if (!in || in->is_enable == false) {
        return EXIT_SUCCESS;
    }
    while (sfRenderWindow_pollEvent(in->window, &event)) {
        text_input_event_manager(in, &event);
    }
    sfRenderWindow_clear(in->window, in->color_bg);
    sfRenderWindow_drawText(in->window, in->text, NULL);
    sfRenderWindow_display(in->window);
    return EXIT_SUCCESS;
}
