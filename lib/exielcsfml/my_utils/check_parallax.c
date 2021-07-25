/*
** EPITECH PROJECT, 2021
** check_parallax
** File description:
** check_parallax
*/

#include "exielcsfml.h"

void check_parallax(parallax_t *parallax, int pixels,
float speed, int max_value)
{
    if (timer(parallax->clock) >= speed) {
        move(&parallax->parallax->rect, pixels, max_value);
        sfClock_restart(parallax->clock);
    }
}