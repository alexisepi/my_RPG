/*
** EPITECH PROJECT, 2021
** evtcredits
** File description:
** evtcredits
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void credits_evt(game_t *game, scenes_t **scenes, button_t **credits_btn)
{
    switch (game->event.type) {
        case sfEvtClosed: game->main_menu->other_menu = false;
            game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            break;
        case sfEvtMouseButtonPressed:
            credits_bhc(credits_btn, game);
            break;
        case sfEvtMouseMoved:
            credits_bhh(credits_btn, game);
            break;
        default:
            break;
    }
}