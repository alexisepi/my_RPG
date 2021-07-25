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
    if (game->event.key.code == game->option->key_pause)
        game->main_game->game_paused = false;
}

void pause_game_evt(game_t *game, scenes_t **scenes,
button_t **pause_game_button)
{
    switch (game->event.type) {
        case sfEvtClosed: game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            game->main_game->game_paused = false;
            break;
        case sfEvtMouseButtonPressed:
            pause_bhc(pause_game_button, game, scenes);
            break;
        case sfEvtMouseMoved:
            pause_bhh(pause_game_button, game);
            break;
        case sfEvtKeyPressed:
            user_keyboard_input(game);
            break;
        default:
            break;
    }
}