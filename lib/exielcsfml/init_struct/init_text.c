/*
** EPITECH PROJECT, 2021
** init_text
** File description:
** init_text
*/

#include "exielcsfml.h"

text_t *init_text(char *string, char *font_path, int char_size, sfVector2f pos)
{
    text_t *text = malloc(sizeof(text_t));

    text->text = sfText_create();
    text->string = string;
    sfText_setString(text->text, text->string);
    text->font = sfFont_createFromFile(font_path);
    sfText_setFont(text->text, text->font);
    text->char_size = char_size;
    sfText_setCharacterSize(text->text, text->char_size);
    text->pos = pos;
    sfText_setPosition(text->text, text->pos);
    return (text);
}

void destroy_text(text_t *text)
{
    sfText_destroy(text->text);
    free(text);
}

void destroy_text_array(text_t **texts, int nb_texts)
{
    for (int i = 0; i != nb_texts; i++)
        destroy_text(texts[i]);
    free(texts);
}