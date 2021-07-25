/*
** EPITECH PROJECT, 2021
** pause_gamemenu
** File description:
** pause_gamemenu
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_optpause(game_t *game, object_t **optpause_obj,
button_t **optpause_btn, text_t **optp_texts)
{
    if (!game->main_game->is_faded)
        sfRenderWindow_drawRectangleShape(game->window,
        game->main_game->fade, NULL);
    for (int i = 0; i != NB_OBJECTS_OPP; i++)
        sfRenderWindow_drawSprite(game->window, optpause_obj[i]->object, NULL);
    for (int i = 0; i != NB_BUTTONS_OPP; i++)
        sfRenderWindow_drawSprite(game->window,
        optpause_btn[i]->object->object, NULL);
    for (int i = 0; i != 1; i++)
        sfRenderWindow_drawText(game->window, optp_texts[i]->text, NULL);
    draw_spinbox(game->window, game->audio->bgm_spinbox);
}

static text_t **init_optpause_text(game_t *game)
{
    text_t **option_texts = malloc(sizeof(text_t) * (NB_TEXTS_OP + 1));

    (option_texts == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    option_texts[NB_TEXTS_OP] = NULL;
    option_texts[0] = init_text("Volume", "res/font/abang.otf",
    50, (sfVector2f) {100, 100});
    return (option_texts);
}

static object_t **init_optpause(game_t *game)
{
    object_t **optpause_obj = malloc(sizeof(object_t) * (NB_OBJECTS_OPP + 1));

    (optpause_obj == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    optpause_obj[NB_OBJECTS_OPP] = NULL;
    return (optpause_obj);
}

static button_t **init_optpause_btn(game_t *game)
{
    button_t **optpause_btn = malloc(sizeof(button_t) * (NB_BUTTONS_OPP + 1));

    (optpause_btn == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    optpause_btn[NB_BUTTONS_OPP] = NULL;
    optpause_btn[0] = init_button("res/common/btn/bb.png",
    (sfVector2f) {0, 655}, (sfIntRect) {0, 0, 350, 40});
    return (optpause_btn);
}

void optpause(game_t *game, scenes_t **scenes)
{
    object_t **optpause_obj = init_optpause(game);
    button_t **optpause_btn = init_optpause_btn(game);
    text_t **opt_text = init_optpause_text(game);

    game->main_game->game_paused = true;
    game->errorh->is_error ? scenes[game->current_scene]->quit_scene = true,
    game->main_menu->other_menu = false : 0;
    while (game->main_game->game_paused_paused) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            optpause_evt(game, scenes, optpause_btn);
        render_optpause(game, optpause_obj, optpause_btn, opt_text);
        game->main_game->is_faded = true;
        sfRenderWindow_display(game->window);
    }
    game->main_game->is_faded = false;
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_text_array(opt_text, NB_TEXTS_OPP);
    destroy_project_scene(optpause_obj, NB_OBJECTS_OPP,
    optpause_btn, NB_BUTTONS_OPP);
}