/*
** EPITECH PROJECT, 2021
** init_sound
** File description:
** init_sound
*/

#include "exielcsfml.h"

sound_t *init_sound(sfBool is_loop, float volume, char *sound_filepath)
{
    sound_t *sound = malloc (sizeof(sound_t));

    sound->sound = sfSound_create();
    sound->buff = sfSoundBuffer_createFromFile(sound_filepath);
    sfSound_setBuffer(sound->sound, sound->buff);
    sound->loop = is_loop;
    sfSound_setLoop(sound->sound, sound->loop);
    sound->volume = volume;
    sfSound_setVolume(sound->sound, sound->volume);
    return (sound);
}

void destroy_sound(sound_t *sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buff);
    free(sound);
}

void destroy_sound_array(sound_t **sounds, int nb_sounds)
{
    for (int i = 0; i != nb_sounds; i++)
        destroy_sound(sounds[i]);
    free(sounds);
}