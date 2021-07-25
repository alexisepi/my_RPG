/*
** EPITECH PROJECT, 2021
** spinbox_hover
** File description:
** spinbox_hover
*/

#include "exielcsfml.h"

int spinbox_is_hover(spinbox_t *spinbox, sfVector2i mouse_pos)
{
    if ((mouse_pos.x >= spinbox->button_top->pos.x &&
        mouse_pos.x <= (spinbox->button_top->pos.x +
        spinbox->button_top->rect.width)) &&
        (mouse_pos.y >= spinbox->button_top->pos.y &&
        mouse_pos.y <= (spinbox->button_top->pos.y +
        spinbox->button_top->rect.height)))
        return (1);
    else if ((mouse_pos.x >= spinbox->button_bottom->pos.x &&
        mouse_pos.x <= (spinbox->button_bottom->pos.x +
        spinbox->button_bottom->rect.width)) &&
        (mouse_pos.y >= spinbox->button_bottom->pos.y &&
        mouse_pos.y <= (spinbox->button_bottom->pos.y +
        spinbox->button_bottom->rect.height)))
        return (2);
    else
        return (0);
}