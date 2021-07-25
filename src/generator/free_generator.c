/*
** EPITECH PROJECT, 2021
** test
** File description:
** free_generator
*/

#include "my.h"
#include "my_libbox.h"

void free_generator(game_t *gen)
{
    my_freeintarray(gen->generator->mapdefault->map, -2);
    my_freeintarray(gen->generator->mapdefault->sprite, -2);
    my_freeintarray(gen->generator->shop->map, -2);
    my_freeintarray(gen->generator->shop->sprite, -2);
    my_freeintarray(gen->generator->boss->map, -2);
    my_freeintarray(gen->generator->boss->sprite, -2);
    free(gen->generator->mapdefault);
    free(gen->generator->shop);
    free(gen->generator->boss);
    free(gen->generator->actual);
    free(gen->generator->seed);
    free(gen->generator);
}