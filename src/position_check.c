/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** position_check
*/

#include "my.h"

static int is_position(game_t *game)
{
    float posy = ((game->player->player->pos.y + 64) / 64);
    float posx = ((game->player->player->pos.x + 64) / 64);

    if (game->generator->actual->map[(int)posy][(int)posx] == 1)
        return ERROR;
    if (game->generator->actual->map[(int)posy][(int)posx] == 2)
        return 1;
    return NORMAL;
}

void position_check(game_t *game, int dir)
{
    int check = is_position(game);

    if (check == 84) {
        switch (dir) {
            case DIR_UP: game->player->player->pos.y += MOVE_OFFSET;
                break;
            case DIR_DOWN: game->player->player->pos.y -= MOVE_OFFSET;
                break;
            case DIR_RIGHT: game->player->player->pos.x -= MOVE_OFFSET;
                break;
            case DIR_LEFT: game->player->player->pos.x += MOVE_OFFSET;
                break;
            default:
                break;
        }
    }
}

object_t **check_door(game_t *game, object_t **game_map)
{
    if (is_position(game) == 1) {
        gen_manage(game);
        free(game_map);
        free(game->player);
        free(game->mob);
        game->player = init_player();
        game->mob = init_enemy("res/Scenes/Game/wizard.png",
        (sfVector2f) {MOBPOS_X, MOBPOS_Y}, (sfIntRect) {0, 300, 150, 150});
        sfSprite_setScale(game->mob->enemy->object, (sfVector2f) {1.5, 1.5});
        game_map = init_game_map(game);
        return game_map;
    }
    return game_map;
}