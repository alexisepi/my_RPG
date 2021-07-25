/*
** EPITECH PROJECT, 2021
** test
** File description:
** sprite_generator
*/

#include "my.h"
#include "my_libbox.h"

static void door_replace(game_t *gen, int **array)
{
    int count = 0;
    int range = 0;

    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            if (array[leny][cpt] == 2)
                range++;
        }
    }
    range = my_randomnb(1, range);
    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            if (array[leny][cpt] == 2)
                count++;
            if (count == range && array[leny][cpt] == 2) {
                array[leny][cpt] = 3;
                gen->generator->actual->map[leny][cpt] = 2;
            }
        }
    }
}

static void gravel_env_2(int **array)
{
    int check = 0;
    int limiter = 10;

    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            check = my_randomnb(1, limiter);
            if (check == 5 && array[leny][cpt] == 0)
                array[leny][cpt] = MAP_GRAVEL3;
        }
    }
    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            check = my_randomnb(1, limiter);
            if (check == 5 && array[leny][cpt] == 0)
                array[leny][cpt] = MAP_GRAVEL4;
        }
    }
}

static void gravel_env_1(int **array)
{
    int check = 0;
    int limiter = 10;

    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            check = my_randomnb(1, limiter);
            if (check == 5 && array[leny][cpt] == 0)
                array[leny][cpt] = MAP_GRAVEL1;
        }
    }
    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            check = my_randomnb(1, limiter);
            if (check == 5 && array[leny][cpt] == 0) {
                array[leny][cpt] = MAP_GRAVEL2;
            }
        }
    }
}

static void env_replace(int **array)
{
    int check = 0;
    int limiter = 20;

    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            check = my_randomnb(1, limiter);
            if (check == 5 && array[leny][cpt] == 0)
                array[leny][cpt] = MAP_ENV_1;
        }
    }
    for (size_t leny = 0; array[leny][0] != -2; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            check = my_randomnb(1, limiter);
            if (check == 5 && array[leny][cpt] == 0)
                array[leny][cpt] = MAP_ENV_2;
        }
    }
}

int sprite_generator(game_t *gen, int **original)
{
    int **array = my_intarraycopy(original, -1, -2);
    int pastille = 0;

    if (!array)
        return ERROR;
    for (size_t leny = 0; pastille != 1; leny++) {
        for (size_t cpt = 0; array[leny][cpt] != -1; cpt++) {
            if (array[leny + 1][cpt] == 0) {
                array[leny][cpt] = 2;
                pastille = 1;
            }
        }
    }
    door_replace(gen, array);
    gravel_env_1(array);
    gravel_env_2(array);
    env_replace(array);
    gen->generator->actual->sprite = my_intarraycopy(array, -1, -2);
    my_freeintarray(array, -2);
    return NORMAL;
}