/*
** EPITECH PROJECT, 2021
** btnmap_s
** File description:
** btnmap_s
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void map_s_bhh(button_t **map_s_button, game_t *game)
{
    for (int i = 0; i != 2; i++) {
        if (button_is_hover(map_s_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            if (i == 0)
                sfSprite_setTextureRect(map_s_button[i]->object->object,
                (sfIntRect){0, 0, 425, 40});
            else
                sfSprite_setTextureRect(map_s_button[i]->object->object,
                (sfIntRect){209, 0, 209, 40});
        }
        else
            sfSprite_setTextureRect(map_s_button[i]->object->object,
            map_s_button[i]->object->rect);
    }
}

void map_s_bhc(button_t **map_s_button, game_t *game, scenes_t **scenes)
{
    for (int i = 0; i != 2; i++) {
        if (button_is_hover(map_s_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            sfSprite_setPosition(map_s_button[i]->object->object,
            (sfVector2f) {map_s_button[i]->object->pos.x,
            (map_s_button[i]->object->pos.y + 10)});
            switch (i)  {
                case 1: game->current_scene = SCENE_GAME;
                    scenes[game->current_scene]->quit_scene = true;
                    break;
            }
            game->main_menu->other_menu = false;
        }
    }
}