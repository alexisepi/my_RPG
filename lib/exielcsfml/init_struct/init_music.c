/*
** EPITECH PROJECT, 2021
** init_music
** File description:
** init_music
*/

#include "exielcsfml.h"

music_t *init_music(sfBool is_loop, float volume, char *music_filepath)
{
    music_t *music = malloc (sizeof(music_t));

    music->music = sfMusic_createFromFile(music_filepath);
    music->loop = is_loop;
    sfMusic_setLoop(music->music, sfFalse);
    music->volume = volume;
    sfMusic_setVolume(music->music, music->volume);
    return (music);
}

void destroy_music(music_t *music)
{
    sfMusic_destroy(music->music);
    free(music);
}

void destroy_music_array(music_t **musics, int nb_musics)
{
    for (int i = 0; i != nb_musics; i++)
        destroy_music(musics[i]);
    free(musics);
}