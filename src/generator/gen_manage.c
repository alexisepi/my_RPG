/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** gen_manage
*/

#include "my.h"
#include "my_libbox.h"

static void free_logic(game_t *gen)
{
    if (gen->generator->actual->map != NULL) {
        my_freeintarray(gen->generator->actual->map, -2);
        my_freeintarray(gen->generator->actual->sprite, -2);
    }
}

static void display_map(game_t *gen)
{
    my_putintarray(gen->generator->actual->map, -1, -2);
    my_putchar('\n');
    my_putintarray(gen->generator->actual->sprite, -1, -2);
    my_putchar('\n');
    my_putintline(gen->generator->seed, -1);
    my_putchar('\n');
}

static int call_generation(game_t *gen)
{
    int check = my_randomnb(1, 3);

    free_logic(gen);
    check = generator(gen, check);
    if (check != 0)
        return ERROR;
    gen->generator->actual->nbmonster = my_randomnb(1,
    gen->generator->nbmonster);
    return NORMAL;
}

int gen_manage(game_t *gen)
{
    int check = 0;

    if (gen->generator->pastille == 0) {
        check = seed_manage(gen);
        if (check != 0)
            return ERROR;
        check = default_maps(gen);
        if (check != 0)
            return ERROR;
        check = default_sprite(gen);
        if (check != 0)
            return ERROR;
        gen->generator->pastille = 1;
    }
    call_generation(gen);
    display_map(gen);
    return NORMAL;
}