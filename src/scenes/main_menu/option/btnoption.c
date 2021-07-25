/*
** EPITECH PROJECT, 2021
** btnoption
** File description:
** btnoption
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void option_bhh(button_t **option_button, game_t *game)
{
    for (int i = 0; i != NB_BUTTONS_OP; i++) {
        if (button_is_hover(option_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            if (i == 0)
                sfSprite_setTextureRect(option_button[i]->object->object,
                (sfIntRect){0, 0, 425, 40});
            else
                sfSprite_setTextureRect(option_button[i]->object->object,
                (sfIntRect){300, 0, 300, 50});
        }
        else
            sfSprite_setTextureRect(option_button[i]->object->object,
            option_button[i]->object->rect);
    }
}

void option_btn_handler(game_t *game, int btn)
{
    switch (btn)  {
        case 0: game->main_menu->other_menu = false;
            break;
        case 1: game->option->key_to_upd = 0;
            break;
        case 2: game->option->key_to_upd = 1;
            break;
        case 3: game->option->key_to_upd = 2;
            break;
        case 4: game->option->key_to_upd = 3;
            break;
        case 5: game->option->key_to_upd = 4;
            break;
        case 6: game->option->key_to_upd = 5;
            break;
    }
    if (btn != 0)
        game->option->upd_key = true;
}

void option_bhc(button_t **option_button, game_t *game)
{
    for (int i = 0; i != NB_BUTTONS_OP; i++) {
        if (button_is_hover(option_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            option_btn_handler(game, i);
        }
    }
}