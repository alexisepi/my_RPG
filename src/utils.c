/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void parallax_menu(parallax_t **background)
{
    check_parallax(background[0], 1, MM_SPEED_BG0, 1280);
    check_parallax(background[1], 1, MM_SPEED_BG1, 1280);
    check_parallax(background[2], 1, MM_SPEED_BG2, 1280);
    check_parallax(background[3], 2, MM_SPEED_BG3, 1280);
    check_parallax(background[4], 5, MM_SPEED_BG4, 1280);
    for (int i = 0; i != NB_PARALLAXS_MM; i++)
        sfSprite_setTextureRect(background[i]->parallax->object,
        background[i]->parallax->rect);
}

void update_volume(game_t *game)
{
    game->audio->bg_music->volume = game->audio->bgm_spinbox->current_value;
    game->audio->sounds[0]->volume = game->audio->bgm_spinbox->current_value;
    sfMusic_setVolume(game->audio->bg_music->music,
    game->audio->bg_music->volume);
    sfSound_setVolume(game->audio->sounds[0]->sound,
    game->audio->sounds[0]->volume);
}

void set_error(game_t *game, int error_id)
{
    game->errorh->is_error = true;
    game->errorh->error_id = error_id;
}

void reset(game_t *game, scenes_t **scenes)
{
    game->main_game->game_paused = false;
    game->current_scene = SCENE_MAINMENU;
    free(game->player);
    free(game->mob);
    game->mob = init_enemy("res/Scenes/Game/wizard.png",
    (sfVector2f) {150, 200}, (sfIntRect) {0, 300, 150, 150});
    sfSprite_setScale(game->mob->enemy->object, (sfVector2f) {1.5, 1.5});
    game->player = init_player();
    scenes[game->current_scene]->quit_scene = true;
}

void move_player(game_t *game, int dir)
{
    switch (dir) {
        case DIR_UP: game->player->player->pos.y -= MOVE_OFFSET;
            break;
        case DIR_DOWN: game->player->player->pos.y += MOVE_OFFSET;
            break;
        case DIR_RIGHT: game->player->player->pos.x += MOVE_OFFSET;
            break;
        case DIR_LEFT: game->player->player->pos.x -= MOVE_OFFSET;
            break;
        default:
            break;
    }
    position_check(game, dir);
    sfSprite_setPosition(game->player->player->object,
    game->player->player->pos);
}