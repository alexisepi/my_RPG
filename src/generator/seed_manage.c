/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** seed_manage
*/

#include "my.h"
#include "my_libbox.h"

int seed_manage(game_t *gen)
{
    int *line = my_xmodulo(gen->seed, 10, -1);

    if (!line)
        return ERROR;
    gen->generator->seed = my_intcpy(line, -1, 1);
    gen->generator->nbrooms = calc_room(gen);
    gen->generator->nbmonster = calc_monster(gen);
    return NORMAL;
}