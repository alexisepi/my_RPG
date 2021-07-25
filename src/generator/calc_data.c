/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** calc_data
*/

#include "my.h"
#include "my_libbox.h"

int calc_room(game_t *gen)
{
    int room = 0;

    room = gen->generator->seed[0] + gen->generator->seed[2] +
    gen->generator->seed[4];
    if (room > 15)
        room -= 4;
    if (room >= 20)
        room -= 15;
    return room;
}

int calc_monster(game_t *gen)
{
    int monster = 0;

    monster = gen->generator->seed[1] + gen->generator->seed[2];
    if (monster > 15)
        monster -= 5;
    if (monster > 12)
        monster -= 3;
    return monster;
}