/*
** EPITECH PROJECT, 2021
** evtpause_game
** File description:
** evtpause_game
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void user_keyboard_input(game_t *game)
{
    if (game->event.key.code == game->option->key_pause) {
        game->main_game->game_paused = false;
        game->main_game->game_paused_paused = false;
    }
}

void optpause_evt(game_t *game, scenes_t **scenes,
button_t **optpause_btn)
{
    switch (game->event.type) {
        case sfEvtClosed: game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            game->main_game->game_paused = false;
            game->main_game->game_paused_paused = false;
            break;
        case sfEvtMouseButtonPressed:
            option_sbhc(game->audio->bgm_spinbox, game);
            optpause_bhc(optpause_btn, game);
            break;
        case sfEvtMouseMoved:
            option_sbh(game->audio->bgm_spinbox, game);
            optpause_bhh(optpause_btn, game);
            break;
        case sfEvtKeyPressed:
            user_keyboard_input(game);
            break;
        default:
            break;
    }
}