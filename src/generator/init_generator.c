/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** init_generator
*/

#include "my.h"
#include "my_libbox.h"

static boss_t *init_boss(void)
{
    boss_t *rmboss = malloc(sizeof(boss_t));

    if (!rmboss)
        return NULL;
    rmboss->map = NULL;
    rmboss->sprite = NULL;
    rmboss->nbrooms = 0;
    rmboss->nbmonster = 0;
    return rmboss;
}

static shop_t *init_shop(void)
{
    shop_t *rmshop = malloc(sizeof(shop_t));

    if (!rmshop)
        return NULL;
    rmshop->map = NULL;
    rmshop->sprite = NULL;
    rmshop->nbrooms = 0;
    return rmshop;
}

static mapdefault_t *init_mapdefault(void)
{
    mapdefault_t *mapdefault = malloc(sizeof(mapdefault_t));

    if (!mapdefault)
        return NULL;
    mapdefault->map = NULL;
    mapdefault->sprite = NULL;
    return mapdefault;
}

static actual_t *init_actual(void)
{
    actual_t *actual = malloc(sizeof(actual_t));

    if (!actual)
        return NULL;
    actual->map = NULL;
    actual->sprite = NULL;
    return actual;
}

generator_t *init_generator(void)
{
    generator_t *generator = malloc(sizeof(generator_t));

    if (!generator)
        return NULL;
    generator->boss = init_boss();
    generator->shop = init_shop();
    generator->actual = init_actual();
    generator->mapdefault = init_mapdefault();
    generator->nbrooms = MAP_DEFROOMS;
    generator->nbmonster = MAP_DEFMONSTER;
    generator->seed = NULL;
    generator->pastille = 0;
    return generator;
}