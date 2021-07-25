/*
** EPITECH PROJECT, 2021
** object_hover
** File description:
** object_hover
*/

#include "exielcsfml.h"

int object_is_hover(object_t *object, sfVector2i mouse_pos)
{
    if ((mouse_pos.x >= object->pos.x &&
        mouse_pos.x <= (object->pos.x + object->rect.width)) &&
        (mouse_pos.y >= object->pos.y &&
        mouse_pos.y <= (object->pos.y + object->rect.height)))
        return (1);
    else
        return (0);
}