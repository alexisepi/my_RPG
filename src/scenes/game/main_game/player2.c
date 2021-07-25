/*
** EPITECH PROJECT, 2021
** player2
** File description:
** player2
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void reset_player(game_t *game)
{
    switch (game->player->dir) {
        case DIR_UP: game->player->player->rect = (sfIntRect) {0, 203, 50, 50};
            break;
        case DIR_DOWN: game->player->player->rect = (sfIntRect) {0, 0, 50, 50};
            break;
        case DIR_RIGHT: game->player->player->rect =
        (sfIntRect) {0, 0, 50, 50};
            break;
        case DIR_LEFT: game->player->player->rect =
        (sfIntRect) {0, 102, 50, 50};
            break;
    }
}

static void check_attack_mob(game_t *game)
{
    if (in_range(game->player, game->mob))
        game->mob->stats.life -= (game->player->stats.damage -
        (game->mob->stats.defense / 10));
    return;
}

static void attack(game_t *game)
{
    sfClock *clock = sfClock_create();

    move_player_rect(game, 50, 550);
    sfClock_restart(clock);
    game->player->attack_cnt++;
    if (game->player->attack_cnt >= 11) {
        game->player->attack = false;
        game->player->attack_cnt = 0;
        check_attack_mob(game);
        reset_player(game);
    }
}

void check_attack(game_t *game, scenes_t **scenes)
{
    if (game->player->stats.life <= 0)
        reset(game, scenes);
    if (game->player->attack == true && game->player->attack_cnt != 11)
        attack(game);
}

void manage_key_attack(game_t *game)
{
    if (game->player->attack == false) {
        switch (game->player->dir) {
            case DIR_UP: game->player->player->rect =
            (sfIntRect) {0, 250, 50, 50};
                break;
            case DIR_DOWN: game->player->player->rect =
            (sfIntRect) {0, 152, 50, 50};
                break;
            case DIR_RIGHT: game->player->player->rect =
            (sfIntRect) {0, 53, 50, 50};
                break;
            case DIR_LEFT: game->player->player->rect =
            (sfIntRect) {0, 152, 50, 50};
                break;
        }
        game->player->attack = true;
    }
}