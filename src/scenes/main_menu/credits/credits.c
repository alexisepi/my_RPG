/*
** EPITECH PROJECT, 2021
** credits
** File description:
** credits
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_credits(game_t *game, object_t **credits,
button_t **credits_btn)
{
    for (int i = 0; i != NB_PARALLAXS_MM; i++)
        sfRenderWindow_drawSprite(game->window,
        game->main_menu->mm_parallax[i]->parallax->object, NULL);
    for (int i = 0; i != NB_OBJECTS_CR; i++)
        sfRenderWindow_drawSprite(game->window, credits[i]->object, NULL);
    for (int i = 0; i != 1; i++)
        sfRenderWindow_drawSprite(game->window, credits_btn[i]->object->object,
        NULL);
}

static object_t **init_credits(game_t *game)
{
    object_t **credits = malloc(sizeof(object_t) * (NB_OBJECTS_CR + 1));

    (credits == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    credits[NB_OBJECTS_CR] = NULL;
    credits[0] = init_object("res/Scenes/MainMenu/credits.png",
    (sfVector2f) {198, 85}, (sfIntRect) {0, 0, 883, 552});
    return (credits);
}

static button_t **init_credits_button(game_t *game)
{
    button_t **credits_btn = malloc(sizeof(button_t) * (NB_BUTTONS_CR + 1));

    (credits_btn == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    credits_btn[NB_BUTTONS_CR] = NULL;
    credits_btn[0] = init_button("res/common/btn/bb.png",
    (sfVector2f) {0, 655}, (sfIntRect) {0, 0, 350, 40});
    return (credits_btn);
}

void credits(game_t *game, scenes_t **scenes)
{
    object_t **credits = init_credits(game);
    button_t **credits_btn = init_credits_button(game);

    game->main_menu->other_menu = true;
    game->errorh->is_error ? scenes[game->current_scene]->quit_scene = true,
    game->main_menu->other_menu = false : 0;
    while (game->main_menu->other_menu) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            credits_evt(game, scenes, credits_btn);
        render_credits(game, credits, credits_btn);
        parallax_menu(game->main_menu->mm_parallax);
        sfRenderWindow_display(game->window);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_project_scene(credits, NB_OBJECTS_CR, credits_btn, NB_BUTTONS_CR);
}