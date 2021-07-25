/*
** EPITECH PROJECT, 2021
** move_rect
** File description:
** move_rect
*/

#include <SFML/Graphics.h>

void move(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left > max_value)
        rect->left = 0;
}