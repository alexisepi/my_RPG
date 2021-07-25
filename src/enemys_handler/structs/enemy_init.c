/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enemy_init
*/

#include "exielcl.h"
#include "my.h"
#include "exielcsfml.h"

enemy_t *init_enemy(char *spritesheet, sfVector2f pos, sfIntRect rect)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->enemy = init_object(spritesheet, pos, rect);
    enemy->stats = (stats_t) {100, 10, 20, 15, 1, 55};
    enemy->anim_clock = sfClock_create();
    enemy->atk_clock = sfClock_create();
    enemy->name = "fire_wizard";
    return enemy;
}

enemy_t **init_enemy_arr(size_t size, sfVector2f *pos)
{
    enemy_t **enemies = malloc(sizeof(enemy_t) * (size + 1));

    if (enemies == NULL)
        my_putstr("malloc enemy_arr error!\n");
    enemies[size] = NULL;
    for (size_t i = 0; enemies[i]; i++) {
        enemies[i] =  init_enemy("res/Scenes/Game/wizard.png", pos[i],
        (sfIntRect) {0, 300, 150, 150});
        sfSprite_setScale(enemies[i]->enemy->object, (sfVector2f) {1.5, 1.5});
    }
    return enemies;
}