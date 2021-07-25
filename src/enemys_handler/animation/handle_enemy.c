/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** handle_enemy
*/

#include "my.h"
#include "exielcsfml.h"

int move_die(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left > max_value)
        return 1;
    return 0;
}

void dies(enemy_t *enemy)
{
    if (enemy->enemy->rect.left != 1200 && enemy->enemy->rect.top != 150) {
        enemy->enemy->rect.left = 1200;
        enemy->enemy->rect.top = 150;
    }
    if (timer(enemy->anim_clock) > 0.05f) {
        enemy->death_cnt = move_die(&enemy->enemy->rect, 150, 1800);
        sfSprite_setTextureRect(enemy->enemy->object, enemy->enemy->rect);
        sfClock_restart(enemy->anim_clock);
    }
}

void handle_enemy(player_t *player, enemy_t *enemy)
{
    int posture = 0;
    int lr = 0;

    if (enemy->stats.life <= 0)
        return;
    if (player->player->pos.x < enemy->enemy->pos.x)
        lr = 1;
    else if (player->player->pos.x > enemy->enemy->pos.x)
        lr = 2;
    if (!(in_range(player, enemy)))
        posture = 1;
    else if (in_range(player, enemy))
        posture = 2;
    mob_animate(posture, enemy, player, lr);
}