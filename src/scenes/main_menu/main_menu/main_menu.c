/*
** EPITECH PROJECT, 2021
** mainmenu
** File description:
** mainmenu
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_menu(game_t *game, object_t **menu, button_t **m_button)
{
    for (int i = 0; i != NB_PARALLAXS_MM; i++)
        sfRenderWindow_drawSprite(game->window,
        game->main_menu->mm_parallax[i]->parallax->object, NULL);
    if (!game->main_menu->other_menu) {
        for (int i = 0; i != NB_OBJECTS_MM; i++)
            sfRenderWindow_drawSprite(game->window, menu[i]->object, NULL);
        for (int i = 0; i != NB_BUTTONS_MM; i++)
            sfRenderWindow_drawSprite(game->window,
            m_button[i]->object->object, NULL);
    }
}

static object_t **init_menu(game_t *game)
{
    object_t **menu = malloc(sizeof(object_t) * (NB_OBJECTS_MM + 1));

    (menu == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    menu[NB_OBJECTS_MM] = NULL;
    menu[0] = init_object("res/Scenes/MainMenu/title_bla.png",
    (sfVector2f) {38, 38}, (sfIntRect) {0, 0, 490, 110});
    return (menu);
}

static parallax_t **init_background(game_t *game)
{
    parallax_t **bg = malloc(sizeof(parallax_t) * (NB_PARALLAXS_MM + 1));

    (bg == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    bg[NB_PARALLAXS_MM] = NULL;
    bg[0] = init_parallax("res/Scenes/MainMenu/bg0.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 2560, 409});
    bg[1] = init_parallax("res/Scenes/MainMenu/bg1.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 2560, 206});
    bg[2] = init_parallax("res/Scenes/MainMenu/bg2.png",
    (sfVector2f){0, 190}, (sfIntRect){0, 0, 2560, 231});
    bg[3] = init_parallax("res/Scenes/MainMenu/bg3.png",
    (sfVector2f){0, 291}, (sfIntRect){0, 0, 2560, 221});
    bg[4] = init_parallax("res/Scenes/MainMenu/bg4.png",
    (sfVector2f){0, 349}, (sfIntRect){0, 0, 2560, 371});
    return (bg);
}

static button_t **init_main_button(game_t *game)
{
    button_t **m_button = malloc(sizeof(button_t) * (NB_BUTTONS_MM + 1));

    (m_button == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    m_button[NB_BUTTONS_MM] = NULL;
    m_button[0] = init_button("res/Scenes/MainMenu/pb.png",
    (sfVector2f) {0, 245}, (sfIntRect) {0, 0, 350, 40});
    m_button[1] = init_button("res/Scenes/MainMenu/htpb.png",
    (sfVector2f) {0, 316}, (sfIntRect) {0, 0, 350, 40});
    m_button[2] = init_button("res/common/btn/ob.png",
    (sfVector2f) {0, 386}, (sfIntRect) {0, 0, 350, 40});
    m_button[3] = init_button("res/Scenes/MainMenu/cb.png",
    (sfVector2f) {0, 455}, (sfIntRect) {0, 0, 350, 40});
    m_button[4] = init_button("res/common/btn/eb.png",
    (sfVector2f) {0, 526}, (sfIntRect) {0, 0, 350, 40});
    return (m_button);
}

void mainmenu(game_t *game, scenes_t **scenes)
{
    object_t **menu = init_menu(game);
    button_t **menu_btn = init_main_button(game);

    game->main_menu->mm_parallax = init_background(game);
    game->errorh->is_error ?
    scenes[game->current_scene]->quit_scene = true : 0;
    while (!scenes[game->current_scene]->quit_scene) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            main_menu_evt(game, scenes, menu_btn);
        render_menu(game, menu, menu_btn);
        parallax_menu(game->main_menu->mm_parallax);
        sfRenderWindow_display(game->window);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_project_scene(menu, NB_OBJECTS_MM, menu_btn, NB_BUTTONS_MM);
    destroy_parallax_array(game->main_menu->mm_parallax, NB_PARALLAXS_MM);
}