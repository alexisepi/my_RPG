/*
** EPITECH PROJECT, 2021
** evtmainmenu
** File description:
** evtmainmenu
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void user_keyboard_input(game_t *game, scenes_t **scenes)
{
    if (game->event.key.code == game->option->key_pause)
        game->main_game->game_paused = true;
    if (!game->player->attack) {
        if (game->event.key.code == game->option->key_up)
            manage_key_up(game);
        else if (game->event.key.code == game->option->key_down)
            manage_key_down(game);
        if (game->event.key.code == game->option->key_right)
            manage_key_right(game);
        else if (game->event.key.code == game->option->key_left)
            manage_key_left(game);
        else if (game->event.key.code == game->option->key_attack)
            manage_key_attack(game);
    }
}

void main_game_evt(game_t *game, scenes_t **scenes, button_t **game_btn)
{
    switch (game->event.type) {
        case sfEvtClosed: game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            break;
        case sfEvtMouseButtonPressed:
            main_game_bhc(game_btn, game);
            break;
        case sfEvtMouseMoved:
            main_game_bhh(game_btn, game);
            break;
        case sfEvtKeyPressed:
            user_keyboard_input(game, scenes);
            break;
        default:
            break;
    }
}