/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enemy_moves
*/

#include "my.h"
#include "exielcsfml.h"

static void moving_sprite(enemy_t *enemy, player_t *user)
{
    float x = ENEMY_SPEED;
    float y = ENEMY_SPEED;

    if (user->player->pos.x < enemy->enemy->pos.x + 80)
        x = -ENEMY_SPEED;
    if ((user->player->pos.y - 75) < enemy->enemy->pos.y)
        y = -ENEMY_SPEED;
    sfSprite_move(enemy->enemy->object, (sfVector2f) {x, y});
    enemy->enemy->pos = sfSprite_getPosition(enemy->enemy->object);
}

static void walk(enemy_t *enemy, int lr, player_t *user)
{
    if (lr == 1 && enemy->enemy->rect.top != 300)
        enemy->enemy->rect.top = 300;
    else if (lr == 2 && enemy->enemy->rect.top != 450)
        enemy->enemy->rect.top = 450;
    if (timer(enemy->anim_clock) > 0.055f) {
        move(&enemy->enemy->rect, 150, 1050);
        sfSprite_setTextureRect(enemy->enemy->object, enemy->enemy->rect);
        moving_sprite(enemy, user);
        sfClock_restart(enemy->anim_clock);
    }
}

static void attack(enemy_t *enemy, player_t *user, int lr)
{
    if (lr == 1 && enemy->enemy->rect.top != 0)
        enemy->enemy->rect.top = 0;
    else if (lr == 2 && enemy->enemy->rect.top != 150)
        enemy->enemy->rect.top = 150;
    if (timer(enemy->anim_clock) > 0.055f) {
        move(&enemy->enemy->rect, 150, 1050);
        sfSprite_setTextureRect(enemy->enemy->object, enemy->enemy->rect);
        sfClock_restart(enemy->anim_clock);
    }
    if (timer(enemy->atk_clock) > 1) {
        user->stats.life -= (enemy->stats.damage - (user->stats.defense / 10));
        sfClock_restart(enemy->atk_clock);
    }
}

void mob_animate(int posture, enemy_t *mob, player_t *user, int lr)
{
    if (posture == 1) {
        walk(mob, lr, user);
    }
    else if (posture == 2) {
        attack(mob, user, lr);
    }
}