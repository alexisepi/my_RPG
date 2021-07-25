/*
** EPITECH PROJECT, 2021
** init_button
** File description:
** init_button
*/

#include "exielcsfml.h"

button_t *init_button(const char *spritesheet_path, sfVector2f pos,
sfIntRect rect)
{
    button_t *button = malloc (sizeof(button_t));

    button->object = init_object(spritesheet_path, pos, rect);
    return (button);
}

void destroy_button(button_t *button)
{
    destroy_object(button->object);
    free(button);
}

void destroy_button_array(button_t **buttons, int nb_buttons)
{
    for (int i = 0; i != nb_buttons; i++)
        destroy_button(buttons[i]);
    free(buttons);
}