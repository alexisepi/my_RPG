/*
** EPITECH PROJECT, 2021
** player
** File description:
** player
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void move_player_rect(game_t *game, int offset, int max_value)
{
    if ((game->player->player->rect.left + offset) >= max_value)
        game->player->player->rect.left = 0;
    else
        game->player->player->rect.left += offset;
    sfSprite_setTextureRect(game->player->player->object,
    game->player->player->rect);
}

void manage_key_up(game_t *game)
{
    if (game->player->dir != DIR_UP) {
        game->player->dir = DIR_UP;
        game->player->player->rect = (sfIntRect) {0, 203, 50, 50};
        sfSprite_setTextureRect(game->player->player->object,
        game->player->player->rect);
        game->player->mov_cnt = 0;
    } else if (game->player->dir == DIR_UP && game->player->mov_cnt == 2)
        game->player->mov_cnt = 0;
    move_player_rect(game, 50, 98);
    move_player(game, DIR_UP);
    return;
}

void manage_key_down(game_t *game)
{
    if (game->player->dir != DIR_DOWN) {
        game->player->dir = DIR_DOWN;
        game->player->player->rect = (sfIntRect) {0, 0, 50, 50};
        sfSprite_setTextureRect(game->player->player->object,
        game->player->player->rect);
        game->player->mov_cnt = 0;
    } else if (game->player->dir == DIR_DOWN && game->player->mov_cnt == 4)
        game->player->mov_cnt = 0;
    move_player_rect(game, 50, 196);
    move_player(game, DIR_DOWN);
    return;
}

void manage_key_right(game_t *game)
{
    if (game->player->dir != DIR_RIGHT) {
        game->player->dir = DIR_RIGHT;
        game->player->player->rect = (sfIntRect) {0, 0, 50, 50};
        sfSprite_setTextureRect(game->player->player->object,
        game->player->player->rect);
        game->player->mov_cnt = 0;
    } else if (game->player->dir == DIR_RIGHT && game->player->mov_cnt == 4)
        game->player->mov_cnt = 0;
    move_player_rect(game, 50, 196);
    move_player(game, DIR_RIGHT);
    return;
}

void manage_key_left(game_t *game)
{
    if (game->player->dir != DIR_LEFT) {
        game->player->dir = DIR_LEFT;
        game->player->player->rect = (sfIntRect) {0, 102, 50, 50};
        sfSprite_setTextureRect(game->player->player->object,
        game->player->player->rect);
        game->player->mov_cnt = 0;
    } else if (game->player->dir == DIR_LEFT && game->player->mov_cnt == 4)
        game->player->mov_cnt = 0;
    move_player_rect(game, 50, 196);
    move_player(game, DIR_LEFT);
    return;
}