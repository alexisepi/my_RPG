/*
** EPITECH PROJECT, 2021
** exielcsfml
** File description:
** An lib containing usefull functions and structures for the CSFML
*/

#ifndef EXIELCSFML_H_
#define EXIELCSFML_H_

//Defines:

//Includes:
    #include <stdbool.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
//Structures:

    /// \brief Structure to initialise an Object
    /// \param object The object sprite
    /// \param object_t The sprite texture
    /// \param pos The position of the sprite on the window
    /// \param rect The rect of the sprite on the texture file
    typedef struct object object_t;
    struct object{
        sfSprite *object;
        sfTexture *object_t;
        sfVector2f pos;
        sfIntRect rect;
    };

    /// \brief Structure to initialise an Rectangle
    /// \param rectangle The sfRectangleShape
    /// \param rectangle_t The rectangle texture
    /// \param pos The position of the sprite on the window
    /// \param rect The rect of the sprite on the texture file
    typedef struct rectangle rectangle_t;
    struct rectangle{
        sfRectangleShape *rectangle;
        sfTexture *rectangle_t;
        sfVector2f pos;
        sfIntRect rect;
    };

    /// \brief Structure to initialise an Circle
    /// \param circle The sfCircleShape
    /// \param circle_t The circle texture
    /// \param pos The position of the sprite on the window
    /// \param rect The rect of the sprite on the texture file
    typedef struct circle circle_t;
    struct circle{
        sfCircleShape *circle;
        sfTexture *circle_t;
        sfVector2f pos;
        sfIntRect rect;
    };

    /// \brief Structure to initialise a Button
    /// \param object An object structure containing sprite, texture,
    /// pos and rect
    typedef struct button button_t;
    struct button {
        object_t *object;
    };

    /// \brief Structure to initialise a Text
    /// \param text The sfText of the text
    /// \param font The text font
    /// \param pos The text position on the window
    /// \param string The sfText text
    /// \param char_size The size of the text
    typedef struct text text_t;
    struct text{
        sfText *text;
        sfFont *font;
        sfVector2f pos;
        char *string;
        int char_size;
    };

    /// \brief Structure to initialise a Music
    /// \param music The sfMusic of the music
    /// \param loop If the music is a loop or not
    /// \param volume The volume of the music
    typedef struct music music_t;
    struct music{
        sfMusic *music;
        sfBool loop;
        float volume;
    };

    /// \brief Structure to initialise a Music
    /// \param sound The sfSound of the sound
    /// \param buff The sfSoundBuffer of the sound
    /// \param loop If the music is a loop or not
    /// \param volume The volume of the music
    typedef struct sound sound_t;
    struct sound{
        sfSound *sound;
        sfSoundBuffer *buff;
        sfBool loop;
        float volume;
    };

    /// \brief Structure to initialise a Spinbox
    /// \param spinbox_text The text_t of the Spinbox
    /// \param spinbox The object_t of the Spinbox
    typedef struct spinbox spinbox_t;
    struct spinbox{
        text_t *spinbox_text;
        object_t *text_object;
        object_t *button_top;
        object_t *button_bottom;
        int min_value;
        int max_value;
        int current_value;
    };

    /// \brief Structure to initialise a Parallax
    /// \param parallax The object_t of the Parallax
    /// \param clock The clock to set the movement rate
    typedef struct parallax parallax_t;
    struct parallax{
        object_t *parallax;
        sfClock *clock;
    };

    typedef struct game game_t;

    /// \brief Structure to initialise a Scene
    /// \param scene_id The sid of the scene
    /// \param function The function attached to the scene
    /// \param quit_scene A boolean to quit the scene
    typedef struct scenes scenes_t;
    struct scenes {
        int scene_id;
        void (*function)(game_t *game, scenes_t **scenes);
        bool quit_scene;
    };

//Prototypes:
    //buttonhandler

        /// \brief Detect if the mouse is hover the button
        /// \param button The button structure
        /// \param mouse_pos The mouse cursor position
        /// \return [1] if hover, [0] if not
        int button_is_hover(button_t *button, sfVector2i mouse_pos);

    //my_utils

        /// \brief Calc the time elipsed from clock
        /// \param clock The sfClock
        /// \return Return the time elipsed from clock
        float timer(sfClock *clock);

        /// \brief Move a sfIntRect
        /// \param rect The sfIntRect to move
        /// \param offset The number of pixel to move
        /// \param max_value The max value of pixel of the texture
        void move(sfIntRect *rect, int offset, int max_value);

        /// \brief To check if a parallax need to move
        /// \param parallax The parallax to be check
        /// \param speed The speed of the parallax
        /// \param pixel Thenumber of pixels to move
        /// \param max_value The max value of pixel of the parallax texture
        void check_parallax(parallax_t *parallax, int pixels,
        float speed, int max_value);

        /// \brief Detect if the mouse is hover one of the spinbox button
        /// \param spinbox The sprinbox structure
        /// \param mouse_pos The mouse cursor position
        /// \return [1] if top, [2] is bottom, [0] if not
        int spinbox_is_hover(spinbox_t *spinbox, sfVector2i mouse_pos);

        /// \brief Detect if the mouse is hover one of the object
        /// \param object The object structure
        /// \param mouse_pos The mouse cursor position
        /// \return [1] if top, [2] is bottom, [0] if not
        int object_is_hover(object_t *object, sfVector2i mouse_pos);

    //init_struct

        /// \brief Initialise an object structure
        /// \param spritesheet_path The sprite sheet filepath
        /// \param pos The position of the sprite on the window
        /// \param rect The rect of the sprite on the texture file
        /// \return Return the object structure initalized
        object_t *init_object(const char *spritesheet_path, sfVector2f pos,
        sfIntRect rect);

        /// \brief Initialise an object structure
        /// \param spritesheet_path The sprite sheet filepath
        /// \param pos The position of the sprite on the window
        /// \param rect The rect of the sprite on the texture file
        /// \return Return the button structure initalized
        button_t *init_button(const char *spritesheet_path, sfVector2f pos,
        sfIntRect rect);

        /// \brief Initialise an object structure
        /// \param string The text string
        /// \param font_path The filepath to the font
        /// \param char_size The char size of the text
        /// \param pos The position of the text on the window
        /// \return Return the text structure initalized
        text_t *init_text(char *string, char *font_path, int char_size,
        sfVector2f pos);

        /// \brief Initialise an music structure
        /// \param is_loop To set if the music is a loop or not
        /// \param volume The music volume. Between 0 and 100
        /// \param music_filepath The music filepath
        /// \return Return the music structure initalized
        music_t *init_music(sfBool is_loop, float volume,
        char *music_filepath);

        /// \brief Initialise an sound structure
        /// \param is_loop To set if the music is a loop or not
        /// \param volume The music volume. Between 0 and 100
        /// \param music_filepath The music filepath
        /// \return Return the sound structure initalized
        sound_t *init_sound(sfBool is_loop, float volume,
        char *sound_filepath);

        /// \brief Initialise an rectangle structure
        /// \param rectsheet_path The rectangle sheet filepath
        /// \param pos The position of the sprite on the window
        /// \param rect The rect of the sprite on the texture file
        /// \return Return the rectangle structure initalized
        rectangle_t *init_rectangle(const char *rectsheet_path, sfVector2f pos,
        sfIntRect rect);

        /// \brief Initialise an circle structure
        /// \param circlesheet_path The circle sheet filepath
        /// \param pos The position of the sprite on the window
        /// \param rect The rect of the sprite on the texture file
        /// \return Return the circle structure initalized
        circle_t *init_circle(const char *circlesheet_path, sfVector2f pos,
        sfIntRect rect);

        /// \brief Initialise an Scene structure
        /// \param scene_id The sid of the scene
        /// \param function The function attached to the scene
        /// \return Return the Scene structure initalized
        scenes_t *init_scene(int scene_id, void (*function)(game_t *game,
        scenes_t **scenes));

        /// \brief Initialise an Scene structure
        /// \param spritesheet_path The sprite sheet filepath
        /// \param pos The position of the sprite on the window
        /// \param rect The rect of the sprite on the texture file
        /// \return Return the object structure initalized
        parallax_t *init_parallax(const char *spritesheet_path, sfVector2f pos,
        sfIntRect rect);

        /// \brief Initialise an Spinbox structure
        /// \param max_value The minimal value of the spinbox
        /// \param min_value The max value of the spinbox
        /// \param pos The position of the spinbox on the window
        /// \param spinbox_text The text_t structure of the Spinbox Text
        /// \return Return the object structure initalized
        spinbox_t *init_spinbox(int max_value, int min_value, sfVector2f pos,
        text_t *spinbox_text);

    //destroy_struct

        /// \brief Free a malloc'ed button structure
        /// \param button The button structure to be freed
        void destroy_button(button_t *button);

        /// \brief Free a malloc'ed button structure array
        /// \param buttons The button structure array to be freed
        /// \param nb_buttons The number of buttons inside the array
        void destroy_button_array(button_t **buttons, int nb_buttons);

        /// \brief Free a malloc'ed circle structure
        /// \param circle The circle structure to be freed
        void destroy_circle(circle_t *circle);

        /// \brief Free a malloc'ed circle structure array
        /// \param circles The circle structure array to be freed
        /// \param nb_circles The number of circles inside the array
        void destroy_circle_array(circle_t **circles, int nb_circles);

        /// \brief Free a malloc'ed music structure
        /// \param music The music structure to be freed
        void destroy_music(music_t *music);

        /// \brief Free a malloc'ed music structure array
        /// \param musics The music structure array to be freed
        /// \param nb_musics The number of musics inside the array
        void destroy_music_array(music_t **musics, int nb_musics);

        /// \brief Free a malloc'ed object structure
        /// \param object The object structure to be freed
        void destroy_object(object_t *object);

        /// \brief Free a malloc'ed object structure array
        /// \param objects The object structure array to be freed
        /// \param nb_objects The number of objects inside the array
        void destroy_object_array(object_t **objects, int nb_objects);

        /// \brief Free a malloc'ed parallax structure
        /// \param parallax The parallax structure to be freed
        void destroy_parallax(parallax_t *parallax);

        /// \brief Free a malloc'ed parallax structure array
        /// \param parallaxs The parallax structure array to be freed
        /// \param nb_parallaxs The number of parallaxs inside the array
        void destroy_parallax_array(parallax_t **parallaxs, int nb_parallaxs);

        /// \brief Free a malloc'ed rectangle structure
        /// \param rectangle The rectangle structure to be freed
        void destroy_rectangle(rectangle_t *rectangle);

        /// \brief Free a malloc'ed rectangle structure array
        /// \param rectangles The rectangle structure array to be freed
        /// \param nb_rectangles The number of rectangles inside the array
        void destroy_rectangle_array(rectangle_t **rectangles,
        int nb_rectangles);

        /// \brief Free a malloc'ed scene structure
        /// \param scene The rectangle scene to be freed
        void destroy_scene(scenes_t *scene);

        /// \brief Free a malloc'ed scene structure array
        /// \param scenes The scene structure array to be freed
        /// \param nb_scenes The number of scenes inside the array
        void destroy_scene_array(scenes_t **scenes, int nb_scenes);

        /// \brief Free a malloc'ed sound structure
        /// \param sound The rectangle sound to be freed
        void destroy_sound(sound_t *sound);

        /// \brief Free a malloc'ed sound structure array
        /// \param sounds The sound structure array to be freed
        /// \param nb_sounds The number of sounds inside the array
        void destroy_sound_array(sound_t **sounds, int nb_sounds);

        /// \brief Free a malloc'ed text structure
        /// \param text The rectangle text to be freed
        void destroy_text(text_t *text);

        /// \brief Free a malloc'ed text structure array
        /// \param sounds The text structure array to be freed
        /// \param nb_texts The number of texts inside the array
        void destroy_text_array(text_t **texts, int nb_texts);

        /// \brief Free a malloc'ed spinbox structure
        /// \param spinbox The rectangle text to be freed
        void destroy_spinbox(spinbox_t *text);

        /// \brief Free a malloc'ed spinbox structure array
        /// \param spinbox The spinbox structure array to be freed
        /// \param nb_spinboxs The number of spinboxs inside the array
        void destroy_spinbox_array(spinbox_t **spinboxs, int nb_spinboxs);

    //Others

        /// \brief Draw a spinbox on the window
        /// \param window The window to draw the spinbox
        /// \param spinbox The spinbox structure
        void draw_spinbox(sfRenderWindow *window, spinbox_t *spinbox);
#endif /* !EXIELCSFML_H_ */