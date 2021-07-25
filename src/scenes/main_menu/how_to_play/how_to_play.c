/*
** EPITECH PROJECT, 2021
** htp
** File description:
** htp
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_htp(game_t *game, object_t **htp,
button_t **htp_btn)
{
    for (int i = 0; i != NB_PARALLAXS_MM; i++)
        sfRenderWindow_drawSprite(game->window,
        game->main_menu->mm_parallax[i]->parallax->object, NULL);
    for (int i = 0; i != 0; i++)
        sfRenderWindow_drawSprite(game->window, htp[i]->object, NULL);
    for (int i = 0; i != 1; i++)
        sfRenderWindow_drawSprite(game->window, htp_btn[i]->object->object,
        NULL);
}

static object_t **init_htp(game_t *game)
{
    object_t **htp = malloc(sizeof(object_t) * (NB_OBJECTS_HT + 1));

    (htp == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    htp[NB_OBJECTS_HT] = NULL;
    return (htp);
}

static button_t **init_htp_button(game_t *game)
{
    button_t **htp_btn = malloc(sizeof(button_t) * (NB_BUTTONS_HT + 1));

    (htp_btn == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    htp_btn[NB_BUTTONS_HT] = NULL;
    htp_btn[0] = init_button("res/common/btn/bb.png",
    (sfVector2f) {0, 655}, (sfIntRect) {0, 0, 350, 40});
    return (htp_btn);
}

void htp(game_t *game, scenes_t **scenes)
{
    object_t **htp = init_htp(game);
    button_t **htp_btn = init_htp_button(game);

    game->main_menu->other_menu = true;
    game->errorh->is_error ? scenes[game->current_scene]->quit_scene = true,
    game->main_menu->other_menu = false : 0;
    while (game->main_menu->other_menu) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            htp_evt(game, scenes, htp_btn);
        render_htp(game, htp, htp_btn);
        parallax_menu(game->main_menu->mm_parallax);
        sfRenderWindow_display(game->window);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_project_scene(htp, NB_OBJECTS_HT, htp_btn, NB_BUTTONS_HT);
}