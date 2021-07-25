/*
** EPITECH PROJECT, 2021
** test
** File description:
** default_sprite
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

int default_sprite(game_t *gen)
{
    int **array = init_files("./src/generator/maps/sprites/default");

    if (!array)
        return ERROR;
    gen->generator->mapdefault->sprite = my_intarraycopy(array, -1, -2);
    my_freeintarray(array, -2);
    array = init_files("./src/generator/maps/sprites/boss");
    if (!array)
        return ERROR;
    gen->generator->boss->sprite = my_intarraycopy(array, -1, -2);
    my_freeintarray(array, -2);
    array = init_files("./src/generator/maps/sprites/shop");
    if (!array)
        return ERROR;
    gen->generator->shop->sprite = my_intarraycopy(array, -1, -2);
    my_freeintarray(array, -2);
    return NORMAL;
}