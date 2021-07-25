/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils
*/

#include "my.h"
#include "exielcsfml.h"

void mod_stats(stats_t *car_stats, stats_t income)
{
    car_stats->life += income.life;
    car_stats->defense += income.defense;
    car_stats->damage += income.damage;
    car_stats->speed += income.speed;
    car_stats->atkspeed += income.atkspeed;
    car_stats->range += income.range;
}

static int pos_x(float x, int range)
{
    if (x > 0) {
        if (x < range)
            return 1;
    } else if (!(x > 0)) {
        if (x > -range)
            return 1;
    }
    return 0;
}

static int pos_y(float y, int range)
{
    if (y > 0) {
        if (y < range)
            return 1;
    } else if (!(y > 0)) {
        if (y > -range)
            return 1;
    }
    return 0;
}

int in_range(player_t *player, enemy_t *enemy)
{
    float x = player->player->pos.x - (enemy->enemy->pos.x + 70);
    float y = (player->player->pos.y - 75) - enemy->enemy->pos.y;
    int count = 0;

    count += pos_x(x, enemy->stats.range);
    count += pos_y(y, enemy->stats.range);
    if (count == 2)
        return 1;
    else
        return 0;
}