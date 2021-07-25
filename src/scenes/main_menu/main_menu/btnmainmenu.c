/*
** EPITECH PROJECT, 2021
** btnmainmenu
** File description:
** btnmainmenu
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void main_menu_bhh(button_t **m_button, game_t *game)
{
    for (int i = 0; i != 5; i++) {
        if (button_is_hover(m_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSprite_setTextureRect(m_button[i]->object->object,
            (sfIntRect){0, 0, 425, 40});
        }
        else
            sfSprite_setTextureRect(m_button[i]->object->object,
            m_button[i]->object->rect);
    }
}

static void change_scene(game_t *game, button_t **m_button, int i,
scenes_t **scenes)
{
    switch (i) {
        case 0: map_s(game, scenes);
            break;
        case 1: htp(game, scenes);
            break;
        case 2: option(game, scenes);
            break;
        case 3: credits(game, scenes);
            break;
        case 4: game->current_scene = SCENE_EXIT;
            break;
    }
    sfSprite_setPosition(m_button[i]->object->object, (sfVector2f)
            {m_button[i]->object->pos.x, (m_button[i]->object->pos.y -= 10)});
    if (i == 4)
        scenes[game->current_scene]->quit_scene = true;
}

void main_menu_bhc(button_t **m_button, game_t *game, scenes_t **scenes)
{
    for (int i = 0; i != 5; i++) {
        if (button_is_hover(m_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            sfSprite_setPosition(m_button[i]->object->object, (sfVector2f)
            {m_button[i]->object->pos.x, (m_button[i]->object->pos.y += 10)});
            change_scene(game, m_button, i, scenes);
        }
    }
}