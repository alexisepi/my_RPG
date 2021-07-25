/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** default_maps
*/

#include "my.h"
#include "my_libbox.h"

static int **init_files(char *filepath)
{
    char *str;
    char **array;
    int **tab;

    str = my_openread(filepath);
    if (!str)
        return NULL;
    array = my_strarray(str, '\n');
    if (!array)
        return NULL;
    tab = my_arrintarray(array, -1, -2);
    if (!tab)
        return NULL;
    my_fillintarray(tab, array);
    free(str);
    my_freearray(array);
    return tab;
}

int default_maps(game_t *gen)
{
    int **array = init_files("./src/generator/maps/default");

    if (!array)
        return ERROR;
    gen->generator->mapdefault->map = my_intarraycopy(array, -1, -2);
    my_freeintarray(array, -2);
    array = init_files("./src/generator/maps/boss");
    if (!array)
        return ERROR;
    gen->generator->boss->map = my_intarraycopy(array, -1, -2);
    my_freeintarray(array, -2);
    array = init_files("./src/generator/maps/shop");
    if (!array)
        return ERROR;
    gen->generator->shop->map = my_intarraycopy(array, -1, -2);
    my_freeintarray(array, -2);
    return NORMAL;
}