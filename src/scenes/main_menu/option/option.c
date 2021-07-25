/*
** EPITECH PROJECT, 2021
** option
** File description:
** option
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_option(game_t *game, object_t **option,
button_t **option_btn, text_t **option_text)
{
    for (int i = 0; i != NB_PARALLAXS_MM; i++)
        sfRenderWindow_drawSprite(game->window,
        game->main_menu->mm_parallax[i]->parallax->object, NULL);
    for (int i = 0; i != 0; i++)
        sfRenderWindow_drawSprite(game->window, option[i]->object, NULL);
    for (int i = 0; i != NB_BUTTONS_OP; i++)
        sfRenderWindow_drawSprite(game->window, option_btn[i]->object->object,
        NULL);
    for (int i = 0; i != NB_TEXTS_OP; i++)
        sfRenderWindow_drawText(game->window, option_text[i]->text, NULL);
    draw_spinbox(game->window, game->audio->bgm_spinbox);
}

static object_t **init_option(game_t *game)
{
    object_t **option = malloc(sizeof(object_t) * (NB_OBJECTS_OP + 1));

    (option == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    option[NB_OBJECTS_OP] = NULL;
    return (option);
}

static button_t **init_option_button(game_t *game)
{
    button_t **option_btn = malloc(sizeof(button_t) * (NB_BUTTONS_OP + 1));

    (option_btn == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    option_btn[NB_BUTTONS_OP] = NULL;
    option_btn[0] = init_button("res/common/btn/bb.png",
    (sfVector2f) {0, 655}, (sfIntRect) {0, 0, 350, 40});
    option_btn[1] = init_button("res/common/btn/b_btn.png",
    (sfVector2f) {590, 150}, (sfIntRect) {0, 0, 300, 50});
    option_btn[2] = init_button("res/common/btn/b_btn.png",
    (sfVector2f) {590, 250}, (sfIntRect) {0, 0, 300, 50});
    option_btn[3] = init_button("res/common/btn/b_btn.png",
    (sfVector2f) {590, 350}, (sfIntRect) {0, 0, 300, 50});
    option_btn[4] = init_button("res/common/btn/b_btn.png",
    (sfVector2f) {590, 450}, (sfIntRect) {0, 0, 300, 50});
    option_btn[5] = init_button("res/common/btn/b_btn.png",
    (sfVector2f) {590, 550}, (sfIntRect) {0, 0, 300, 50});
    option_btn[6] = init_button("res/common/btn/b_btn.png",
    (sfVector2f) {590, 650}, (sfIntRect) {0, 0, 300, 50});
    return (option_btn);
}

void option(game_t *game, scenes_t **scenes)
{
    object_t **option = init_option(game);
    button_t **option_btn = init_option_button(game);
    text_t **option_text = init_option_text(game);

    game->main_menu->other_menu = true;
    game->errorh->is_error ? scenes[game->current_scene]->quit_scene = true,
    game->main_menu->other_menu = false : 0;
    while (game->main_menu->other_menu) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            option_evt(game, scenes, option_btn, option_text);
        render_option(game, option, option_btn, option_text);
        parallax_menu(game->main_menu->mm_parallax);
        sfRenderWindow_display(game->window);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_text_array(option_text, NB_TEXTS_OP);
    destroy_project_scene(option, NB_OBJECTS_OP, option_btn, NB_BUTTONS_OP);
}