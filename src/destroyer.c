/*
** EPITECH PROJECT, 2021
** destroyer
** File description:
** File containing functions to free malloc'ed functions
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

int destroy_error(game_t *game, scenes_t **scenes, int error_id)
{
    int n_error_id = error_id;

    destroy_spinbox(game->audio->bgm_spinbox);
    sfMusic_stop(game->audio->bg_music->music);
    destroy_scene_array(scenes, SCENE_COUNT);
    destroy_music(game->audio->bg_music);
    destroy_sound_array(game->audio->sounds, SOUND_COUNT);
    sfClock_destroy(game->clock);
    destroy_enemy(game->mob);
    sfRenderWindow_destroy(game->window);
    sfRectangleShape_destroy(game->main_game->fade);
    free(game->audio);
    free(game->main_game);
    free(game->errorh);
    free(game->main_menu);
    free(game);
    return (error_handler(n_error_id));
}

void destroy_project_scene(object_t **objects, int nb_objects,
button_t **buttons, int nb_buttons)
{
    destroy_object_array(objects, nb_objects);
    destroy_button_array(buttons, nb_buttons);
}