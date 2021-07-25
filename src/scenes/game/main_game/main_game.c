/*
** EPITECH PROJECT, 2021
** maingame
** File description:
** maingame
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_game(game_t *game, object_t **game_map,
object_t **game_obj, button_t **m_button)
{
    for (int i = 0; i != (MAP_WIDTH * MAP_HEIGHT); i++)
        sfRenderWindow_drawSprite(game->window, game_map[i]->object, NULL);
    for (int i = 0; i != NB_OBJECTS_MG; i++)
        sfRenderWindow_drawSprite(game->window, game_obj[i]->object, NULL);
    for (int i = 0; i != NB_BUTTONS_MG; i++)
        sfRenderWindow_drawSprite(game->window,
        m_button[i]->object->object, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->player->player->object, NULL);
    if (game->mob->stats.life <= 0 && game->mob->death_cnt != 1) {
        dies(game->mob);
        sfRenderWindow_drawSprite(game->window,
        game->mob->enemy->object, NULL);
    }
    if (game->mob->stats.life > 0)
        sfRenderWindow_drawSprite(game->window,
        game->mob->enemy->object, NULL);
}

static object_t **init_menu(game_t *game)
{
    object_t **game_obj = malloc(sizeof(object_t) * (NB_OBJECTS_MG + 1));

    (game_obj == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    game_obj[NB_OBJECTS_MG] = NULL;
    game_obj[0] = init_object("res/Scenes/Game/MainGame/map_test.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1280, 720});
    return (game_obj);
}

static button_t **init_main_button(game_t *game)
{
    button_t **m_button = malloc(sizeof(button_t) * (NB_BUTTONS_MG + 1));

    (m_button == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    m_button[NB_BUTTONS_MG] = NULL;
    return (m_button);
}

static void check_pause(game_t *game, scenes_t **scenes)
{
    if (game->main_game->game_paused_paused)
        optpause(game, scenes);
    else if (game->main_game->game_paused)
        pause_game(game, scenes);
}

void maingame(game_t *game, scenes_t **scenes)
{
    object_t **game_map = init_game_map(game);
    object_t **game_obj = init_menu(game);
    button_t **game_btn = init_main_button(game);

    game->errorh->is_error ?
    scenes[game->current_scene]->quit_scene = true : 0;
    sfRenderWindow_clear(game->window, sfBlack);
    while (!scenes[game->current_scene]->quit_scene) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            main_game_evt(game, scenes, game_btn);
        handle_enemy(game->player, game->mob);
        game_map = check_door(game, game_map);
        render_game(game, game_map, game_obj, game_btn);
        check_attack(game, scenes);
        check_pause(game, scenes);
        sfRenderWindow_display(game->window);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_project_scene(game_obj, NB_OBJECTS_MG, game_btn, NB_BUTTONS_MG);
}