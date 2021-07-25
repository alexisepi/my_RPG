/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** don't forget free maps !
*/

#include "my.h"
#include "my_libbox.h"

static int height_calc(int size)
{
    int calc = 0;

    if (size == 2) {
        calc = 3;
        return calc;
    }
    if (size == 3) {
        calc = 2;
        return calc;
    }
    if (size == 4) {
        calc = 1;
        return calc;
    }
    return calc;
}

static int begin_calc(int size)
{
    int calc = 0;

    if (size == 2) {
        calc = my_randomnb(5, 7);
        return calc;
    }
    if (size == 3) {
        calc = my_randomnb(3, 6);
        return calc;
    }
    if (size == 4) {
        calc = my_randomnb(1, 3);
        return calc;
    }
    return calc;
}

static void deform_map(int **array, int size)
{
    int begin = 0;
    int lower = size * 3;
    int high = size * 4;
    int count = 0;
    int range = height_calc(size);

    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t lenx = 0; array[leny][lenx] != -1; lenx++) {
            if (array[leny][lenx] == 0)
                array[leny][lenx] = 1;
        }
    }
    for (size_t leny = range; array[leny + range][0] != -2; leny++) {
        begin = begin_calc(size);
        count = my_randomnb(lower, high);
        for (size_t cpt = 0; cpt < (size_t)count; cpt++)
            array[leny][begin + cpt] = 0;
    }
}

int generator(game_t *gen, int size)
{
    int realsize = 0;
    int **array = NULL;
    int nbmonster = gen->generator->nbmonster;

    if (size > 3 || size < 1)
        return ERROR;
    realsize = size + 1;
    nbmonster = my_randomnb(1, nbmonster);
    array = my_intarraycopy(gen->generator->mapdefault->map, -1, -2);
    if (!array)
        return ERROR;
    deform_map(array, realsize);
    if (!array)
        return ERROR;
    gen->generator->actual->map = my_intarraycopy(array, -1, -2);
    realsize = sprite_generator(gen, array);
    if (realsize != 0)
        return ERROR;
    my_freeintarray(array, -2);
    return NORMAL;
}