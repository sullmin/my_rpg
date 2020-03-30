/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_button.h"
#include "my_world.h"

my_button_shape_t *get_button_shape(sfVector2f pos, sfVector2f scale)
{
    my_button_shape_t *my_button = malloc(sizeof(my_button_shape_t));

    if (!my_button)
        return NULL;
    my_button->pos = pos;
    my_button->scale = scale;
    my_button->toggle = 0;
    my_button->name = NULL;
    my_button->texture = NULL;
    return my_button;
}

int set_texture_button(my_button_shape_t *my_button, char *path_one,
    char *path_two, char *path_three)
{
    my_button->texture = malloc(sizeof(sfTexture *) * NB_TEXTURE);
    if (!my_button->texture)
        return EXIT_ERROR;
    my_button->texture[0] = sfTexture_createFromFile(path_one, NULL);
    my_button->texture[1] = sfTexture_createFromFile(path_two, NULL);
    my_button->texture[2] = sfTexture_createFromFile(path_three, NULL);

    if (!my_button->texture[0] || !my_button->texture[1] ||
        !my_button->texture[3])
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

void button_shape_destroy(my_button_shape_t *my_button)
{
    if (my_button->name) {
        free(my_button->name);
        sfFont_destroy(my_button->font);
        sfText_destroy(my_button->text);
    }
    sfClock_destroy(my_button->clock_start);
    free(my_button);
}

void button_refresh_stat(my_button_shape_t *my_button, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int temp = my_button->toggle;

    if (mouse_pos.x >= my_button->pos.x &&
    mouse_pos.x <= my_button->pos.x + my_button->scale.x &&
    mouse_pos.y >= my_button->pos.y &&
    mouse_pos.y <= my_button->pos.y + my_button->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            my_button->is_pressed = true;
            temp = 2;
        }
        else
            temp = 1;
    } else
        temp = 0;
    button_status(temp, my_button);
}

void button_display(my_button_shape_t *my_button, sfRenderWindow *window)
{
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, my_button->texture[my_button->toggle], sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {3, 3});
    sfSprite_setPosition(sprite, my_button->pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    if (my_button->name)
        sfRenderWindow_drawText(window, my_button->text, NULL);
    if (my_button->is_activate)
        sfSound_play(my_button->sound.sound);
}

bool button_ispressed(my_button_shape_t *my_button)
{
    if (my_button->toggle == 2) {
        sfText_setPosition(my_button->text, (sfVector2f)
            {my_button->pos.x + 55, my_button->pos.y + 40});
        return true;
    }
    sfText_setPosition(my_button->text, (sfVector2f)
        {my_button->pos.x + 55, my_button->pos.y + 30});
    return false;
}

int set_button_id(my_button_shape_t *my_button, char *str, char *font_path,
    float size_char)
{
    sfVector2f pos = {my_button->pos.x + 55, my_button->pos.y + 30};
    my_button->text = sfText_create();
    my_button->font = sfFont_createFromFile(font_path);

    if (!str || !my_button->font)
        return EXIT_ERROR;
    my_button->name = my_strdup(str);
    if (!my_button->name)
        return EXIT_ERROR;
    sfText_setString(my_button->text, str);
    sfText_setFont(my_button->text, my_button->font);
    sfText_setCharacterSize(my_button->text, size_char);
    sfText_setPosition(my_button->text, pos);
    return EXIT_SUCCESS;
}

static sound_s create_sound(char *filepath)
{
    sound_s my_sound = {NULL, NULL};

    my_sound.sound = sfSound_create();
    if (my_sound.sound == NULL)
        return my_sound;
    my_sound.buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(my_sound.sound, my_sound.buffer);
    return my_sound;
}

int sound_set(button_manage_t *button)
{
    sound_s sound = create_sound(BUTT_DEFAULT_SOUND);

    button->exit->sound = create_sound(BUTT_EXIT_SOUND);
    if (!sound.buffer || !button->exit->sound.buffer)
        return EXIT_ERROR;
    sound_filler(button, sound);
    return EXIT_SUCCESS;
}