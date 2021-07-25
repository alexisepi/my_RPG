/*
** EPITECH PROJECT, 2021
** btnpause_game
** File description:
** btnpause_game
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void pause_bhh(button_t **pause_button, game_t *game)
{
    for (int i = 0; i != NB_BUTTONS_PA; i++) {
        if (button_is_hover(pause_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSprite_setTextureRect(pause_button[i]->object->object,
            (sfIntRect){0, 0, 425, 40});
        }
        else
            sfSprite_setTextureRect(pause_button[i]->object->object,
            pause_button[i]->object->rect);
    }
}

void pause_bhc(button_t **pause_button, game_t *game, scenes_t **scenes)
{
    for (int i = 0; i != NB_BUTTONS_PA; i++) {
        if (button_is_hover(pause_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            sfSprite_setPosition(pause_button[i]->object->object,
            (sfVector2f) {pause_button[i]->object->pos.x,
            (pause_button[i]->object->pos.y + 10)});
            switch (i)  {
                case 1: reset(game, scenes);
                    break;
                case 2: game->main_game->game_paused_paused = true;
                    break;
                case 3: game->current_scene = SCENE_EXIT;
                    scenes[game->current_scene]->quit_scene = true;
                    break;
            }
            game->main_game->game_paused = false;
        }
    }
}