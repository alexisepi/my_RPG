/*
** EPITECH PROJECT, 2021
** button_hover
** File description:
** button_hover
*/

#include "exielcsfml.h"

int button_is_hover(button_t *button, sfVector2i mouse_pos)
{
    if ((mouse_pos.x >= button->object->pos.x &&
        mouse_pos.x <= (button->object->pos.x + button->object->rect.width)) &&
        (mouse_pos.y >= button->object->pos.y &&
        mouse_pos.y <= (button->object->pos.y + button->object->rect.height)))
        return (1);
    else
        return (0);
}