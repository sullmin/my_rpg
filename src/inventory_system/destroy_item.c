/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

void destroy_item(item_t *item)
{
    if (item->name)
        free(item->name);
    if (item->description)
        free(item->description);
    if (item->sprite)
        sfSprite_destroy(item->sprite);
    if (item->texture)
        sfTexture_destroy(item->texture);
    if (item->framebuffer->pixels)
        free(item->framebuffer->pixels);
    if (item->framebuffer)
        free(item->framebuffer);
}