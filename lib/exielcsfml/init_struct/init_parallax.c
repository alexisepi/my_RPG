/*
** EPITECH PROJECT, 2021
** init_parallax
** File description:
** init_parallax
*/

#include "exielcsfml.h"

parallax_t *init_parallax(const char *spritesheet_path, sfVector2f pos,
sfIntRect rect)
{
    parallax_t *parallax = malloc(sizeof(parallax_t));

    parallax->parallax = init_object(spritesheet_path, pos, rect);
    parallax->clock = sfClock_create();
    return (parallax);
}

void destroy_parallax(parallax_t *parallax)
{
    destroy_object(parallax->parallax);
    sfClock_destroy(parallax->clock);
    free(parallax);
}

void destroy_parallax_array(parallax_t **parallaxs, int nb_parallaxs)
{
    for (int i = 0; i != nb_parallaxs; i++)
        destroy_parallax(parallaxs[i]);
    free(parallaxs);
}