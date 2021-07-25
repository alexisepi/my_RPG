/*
** EPITECH PROJECT, 2021
** init_rectangle
** File description:
** init_rectangle
*/

#include "exielcsfml.h"

rectangle_t *init_rectangle(const char *rectsheet_path, sfVector2f pos,
sfIntRect rect)
{
    rectangle_t *rectangle = malloc(sizeof(rectangle_t));

    rectangle->rectangle = sfRectangleShape_create();
    rectangle->rectangle_t = sfTexture_createFromFile(rectsheet_path, NULL);
    sfRectangleShape_setTexture(rectangle->rectangle, rectangle->rectangle_t,
    sfFalse);
    rectangle->pos = pos;
    sfRectangleShape_setPosition(rectangle->rectangle, rectangle->pos);
    rectangle->rect = rect;
    sfRectangleShape_setTextureRect(rectangle->rectangle, rectangle->rect);
    return (rectangle);
}

void destroy_rectangle(rectangle_t *rectangle)
{
    sfTexture_destroy(rectangle->rectangle_t);
    sfRectangleShape_destroy(rectangle->rectangle);
    free(rectangle);
}

void destroy_rectangle_array(rectangle_t **rectangles, int nb_rectangles)
{
    for (int i = 0; i != nb_rectangles; i++)
        destroy_rectangle(rectangles[i]);
    free(rectangles);
}