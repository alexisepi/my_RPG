/*
** EPITECH PROJECT, 2021
** evtmap_s
** File description:
** evtmap_s
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void put_user_input(game_t *game, int nb)
{
    if (game->nb_input < 10) {
        game->seed = game->seed * 10 + nb;
        game->nb_input++;
    }
}

static void rem_user_input(game_t *game)
{
    if (game->nb_input > 0) {
        game->seed = game->seed / 10 ;
        game->nb_input--;
    }
}

static void get_user_input(game_t *game)
{
    if ((game->event.key.code >= 48 &&
    game->event.key.code <= 59))
        put_user_input(game, game->event.key.code - 48);
    else if (game->event.key.code == 8)
        rem_user_input(game);
}

void map_s_evt(game_t *game, scenes_t **scenes, button_t **map_s_btn)
{
    switch (game->event.type) {
        case sfEvtClosed: game->main_menu->other_menu = false;
            game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            break;
        case sfEvtMouseButtonPressed: map_s_bhc(map_s_btn, game, scenes);
            break;
        case sfEvtMouseMoved: map_s_bhh(map_s_btn, game);
            break;
        case sfEvtTextEntered: get_user_input(game);
            break;
        default:
            break;
    }
}