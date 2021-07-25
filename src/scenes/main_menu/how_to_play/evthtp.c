/*
** EPITECH PROJECT, 2021
** evthtp
** File description:
** evthtp
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void htp_evt(game_t *game, scenes_t **scenes, button_t **htp_btn)
{
    switch (game->event.type) {
        case sfEvtClosed: game->main_menu->other_menu = false;
            game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            break;
        case sfEvtMouseButtonPressed:
            htp_bhc(htp_btn, game);
            break;
        case sfEvtMouseMoved:
            htp_bhh(htp_btn, game);
            break;
        default:
            break;
    }
}