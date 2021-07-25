/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enemy_destroy
*/

#include "my.h"
#include "exielcsfml.h"

void destroy_enemy(enemy_t *enemy)
{
    destroy_object(enemy->enemy);
    sfClock_destroy(enemy->anim_clock);
    sfClock_destroy(enemy->atk_clock);
    free(enemy);
}

void destroy_enemy_arr(enemy_t **enemies)
{
    for (size_t i = 0; enemies[i] != NULL; i++)
        destroy_enemy(enemies[i]);
    free(enemies);
}