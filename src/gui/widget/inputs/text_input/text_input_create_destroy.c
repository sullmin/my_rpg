/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** create and destroy a text input
*/

#include "my_rpg.h"

const sfVector2f TEXT_IN_INIT_POS = {4, 4};
const unsigned int TEXT_IN_INIT_CHARSIZE = 50;
const sfColor TEXT_IN_INIT_TXTCOLOR = {255, 255, 255, 255};
const sfColor TEXT_IN_INIT_BGCOLOR = {55, 55, 55, 255};
const char *TEXT_IN_INIT_FONT = "./asset/font/BebasNeue-Regular.ttf";
const unsigned int TEXT_IN_INIT_HEIGHT = 70;
const unsigned int TEXT_IN_INIT_CHAR_WIDTH = 28;
const unsigned int TEXT_IN_INIT_WIN_FPS = 30;
const int TEXT_IN_WIN_BPP = 32;

void text_input_destroy(text_in_t *input)
{
    if (!input)
        return;
    free(input->buffer);
    free(input->title);
    sfText_destroy(input->text);
    sfFont_destroy(input->font);
    sfRenderWindow_destroy(input->window);
}

static int text_input_create_text(text_in_t *input)
{
    input->font = sfFont_createFromFile(TEXT_IN_INIT_FONT);
    input->text = sfText_create();
    if (!input->text || !input->font) {
        my_putstr_error("text_input_create : error text or font object\n");
        return EXIT_FAILURE;
    }
    sfText_setFont(input->text, input->font);
    sfText_setPosition(input->text, TEXT_IN_INIT_POS);
    sfText_setString(input->text, input->buffer);
    sfText_setColor(input->text, TEXT_IN_INIT_TXTCOLOR);
    sfText_setCharacterSize(input->text, TEXT_IN_INIT_CHARSIZE);
    return EXIT_SUCCESS;
}

static int text_input_create_window(text_in_t *input)
{
    sfVideoMode mode = {0, TEXT_IN_INIT_HEIGHT, TEXT_IN_WIN_BPP};

    mode.width = TEXT_IN_INIT_CHAR_WIDTH * input->max_char;
    input->window = sfRenderWindow_create(mode, input->title, sfTitlebar,
    sfContextDefault);
    if (!input->window) {
        my_putstr_error("text_input_create : error create window object.\n");
        return EXIT_FAILURE;
    }
    sfRenderWindow_setMouseCursorVisible(input->window, sfFalse);
    sfRenderWindow_setFramerateLimit(input->window, TEXT_IN_INIT_WIN_FPS);
    sfRenderWindow_setVisible(input->window, sfFalse);
    return EXIT_SUCCESS;
}

static int init_widget_buffer(text_in_t *input, const char *init_buffer)
{
    input->buffer = malloc(sizeof(char) * (input->max_char + 2));
    if (!input->buffer || !input->title) {
        my_putstr_error("txt_input_create: malloc error\n");
        return EXIT_FAILURE;
    }
    my_strcpy(input->buffer, ">");
    if (init_buffer)
        my_strncpy(input->buffer + 1, init_buffer, input->max_char);
    input->i_buffer = 1 + my_strlen(init_buffer);
    return EXIT_SUCCESS;
}

int text_input_create(text_in_t *input, const char *title,
unsigned int max_char, const char *init_buffer)
{
    if (!input || max_char > 100)
        return EXIT_FAILURE;
    input->max_char = max_char + 2;
    input->title = my_strdup(title);
    input->is_enable = false;
    input->window = NULL;
    if (init_widget_buffer(input, init_buffer) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (text_input_create_text(input) == EXIT_FAILURE)
        return EXIT_FAILURE;
    else if (text_input_create_window(input) == EXIT_FAILURE)
        return EXIT_FAILURE;
    input->color_bg = TEXT_IN_INIT_BGCOLOR;
    input->color_txt = TEXT_IN_INIT_TXTCOLOR;
    return EXIT_SUCCESS;
}
