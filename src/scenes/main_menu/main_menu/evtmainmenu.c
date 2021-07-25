/*
** EPITECH PROJECT, 2021
** evtmainmenu
** File description:
** evtmainmenu
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void main_menu_evt(game_t *game, scenes_t **scenes, button_t **m_button)
{
    switch (game->event.type) {
        case sfEvtClosed: game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            break;
        case sfEvtMouseButtonPressed:
            main_menu_bhc(m_button, game, scenes);
            break;
        case sfEvtMouseMoved:
            main_menu_bhh(m_button, game);
            break;
        default:
            break;
    }
}