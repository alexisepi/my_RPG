/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

//Defines:
    //Game
        #define GAME_NAME   "Bloupinette"
        #define WINDOW_WIDTH    1280
        #define WINDOW_HEIGHT   720
        #define GAME_FRAMERATE  60

    //Player
        #define PLAYER_LENGTH   18
        #define PLAYER_HEIGHT   30

        #define DIR_UP          0
        #define DIR_DOWN        1
        #define DIR_RIGHT       2
        #define DIR_LEFT        3
        #define MOVE_OFFSET     10

    //Enemies
        #define ENEMY_SPEED     2

    //MainMenu
        //MainMenu
            #define NB_OBJECTS_MM       1
            #define NB_BUTTONS_MM       5
            #define NB_PARALLAXS_MM     5
        //Credits
            #define NB_OBJECTS_CR       1
            #define NB_BUTTONS_CR       1
        //How_To_Play
            #define NB_OBJECTS_HT       0
            #define NB_BUTTONS_HT       1
        //Option
            #define NB_OBJECTS_OP       0
            #define NB_BUTTONS_OP       7
            #define NB_TEXTS_OP         13
            #define AUDIO_TEXT_SIZE     50
        //Map_Selector
            #define NB_OBJECTS_MS       2
            #define NB_BUTTONS_MS       2
            #define NB_TEXTS_MS         1
            #define SEED_SELEC_SIZE     50
            #define USER_INPUT_SIZE     45
    //Game
        //MainGame
            #define NB_OBJECTS_MG       0
            #define NB_BUTTONS_MG       0
            #define PPOS_X              608
            #define PPOS_Y              296
            #define MOBPOS_X            658
            #define MOBPOS_Y            346
            //Maps
                #define MAP_HEIGHT          11
                #define MAP_WIDTH           20
                #define MAP_DEFROOMS        10
                #define MAP_DEFMONSTER      10
                #define MAP_GROUND          0
                #define MAP_VOID            1
                #define MAP_WALL            2
                #define MAP_DOOR_1          3
                #define MAP_DOOR_2          4
                #define MAP_GRAVEL1         11
                #define MAP_GRAVEL2         12
                #define MAP_GRAVEL3         13
                #define MAP_GRAVEL4         14
                #define MAP_ENV_1           8
                #define MAP_ENV_2           9
        //Pause
            #define NB_OBJECTS_PA       1
            #define NB_BUTTONS_PA       4
            #define NB_TEXTS_PA         11
            //OptionPause
                #define NB_OBJECTS_OPP      0
                #define NB_BUTTONS_OPP      1
                #define NB_TEXTS_OPP        1

    //Scenes
    #define SCENE_COUNT     4
    #define SCENE_EXIT      0
    #define SCENE_MAINMENU  1
    #define SCENE_MAP       2
    #define SCENE_GAME      3

    //Audio
    #define MAX_VOLUME      100   //Base : 100
    #define MIN_VOLUME      0

    #define SOUND_COUNT     1
    #define SOUND_BTN       0

    //Parallax
    #define MM_SPEED_BG0    1
    #define MM_SPEED_BG1    0.08
    #define MM_SPEED_BG2    0.3
    #define MM_SPEED_BG3    0.1
    #define MM_SPEED_BG4    0.05

    //Keys
    #define DEF_KEY_PAUSE   36
    #define DEF_KEY_UP      73
    #define DEF_KEY_DOWN    74
    #define DEF_KEY_RIGHT   72
    #define DEF_KEY_LEFT    71
    #define DEF_KEY_ATTACK  57

    //Error:
        #define NORMAL  0
        #define ERROR   84

        #define WINDOW_CREATE_ERROR     1
        #define MALLOC_ERROR            2
        #define WRONG_INIT_GEN          3
//Includes:
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "exielcsfml.h"
    #include <stdlib.h>
    //Temp:
        #include <unistd.h>
//Structures:
    //---------MapSystem---------
        typedef struct shop {
            int **map;
            int **sprite;
            int nbrooms;
        } shop_t;

        typedef struct boss {
            int **map;
            int **sprite;
            int nbrooms;
            int nbmonster;
        } boss_t;

        typedef struct mapdefault {
            int **map;
            int **sprite;
        } mapdefault_t;

        typedef struct actual {
            int **map;
            int **sprite;
            int nbmonster;
        } actual_t;

        typedef struct generator {
            shop_t *shop;
            boss_t *boss;
            mapdefault_t *mapdefault;
            actual_t *actual;
            int *seed;
            int nbrooms;
            int nbmonster;
            int pastille;
        } generator_t;

    //---------------------------

    typedef struct errorh errorh_t;
    struct errorh {
        bool is_error;
        int error_id;
    };

    typedef struct main_menu main_menu_t;
    struct main_menu {
        parallax_t **mm_parallax;
        bool other_menu;
    };

    typedef struct main_game main_game_t;
    struct main_game {
        sfRectangleShape *fade;
        bool is_faded;
        bool game_paused;
        bool game_paused_paused;
    };

    typedef struct audio audio_t;
    struct audio {
        music_t *bg_music;
        sound_t **sounds;
        spinbox_t *bgm_spinbox;
    };

    typedef struct stats_s stats_t;
    struct stats_s {
        int life;
        int defense;
        int damage;
        int speed;
        int atkspeed;
        int range;
    };

    typedef struct player player_t;
    struct player {
        object_t *player;
        int dir;
        int mov_cnt;
        bool attack;
        int attack_cnt;
        stats_t stats;
        int posx;
        int posy;
    };

    typedef struct option option_t;
    struct option {
        char **keys;
        bool upd_key;
        int key_to_upd;
        int key_up;
        int key_down;
        int key_right;
        int key_left;
        int key_pause;
        int key_attack;
    };

    typedef struct enemy_s enemy_t;
    struct enemy_s {
        stats_t stats;
        object_t *enemy;
        char *name;
        sfClock *anim_clock;
        sfClock *atk_clock;
        int death_cnt;
    };

    typedef struct game game_t;
    struct game{
        audio_t *audio;
        main_menu_t *main_menu;
        main_game_t *main_game;
        errorh_t *errorh;
        option_t *option;
        player_t *player;
        enemy_t *mob;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        generator_t *generator;
        int seed;
        int nb_input;
        int current_scene;
    };

//Prototypes:
    //errorhandler.c
        int error_handler(int error_id);
    //init_struct.c
        game_t *init_game(void);
    //init_struct2.c
        spinbox_t *init_option_spinbox(float volume);
        main_game_t *init_main_game(void);
        option_t *init_game_option(void);
        player_t *init_player(void);
        scenes_t **init_scenes_array(game_t *game);
    //init_option.c
        void init_option_key(char **keys);
        void init_option_key6(char **keys);
    //utils.c
        void set_error(game_t *game, int error_id);
        void update_volume(game_t *game);
        void parallax_menu(parallax_t **background);
        void reset(game_t *game, scenes_t **scenes);
        void move_player(game_t *game, int dir);
        void position_check(game_t *game, int dir);
        object_t **check_door(game_t *game, object_t **game_map);
    //destroyer.c
        void destroy_project_scene(object_t **objects, int nb_objects,
        button_t **buttons, int nb_buttons);
        int destroy_error(game_t *game, scenes_t **scenes, int error_id);

    //Generator
        //calc_data.c
            int calc_monster(game_t *gen);
            int calc_room(game_t *gen);
        //default_maps.c
            int default_maps(game_t *gen);
        //default_sprite.c
            int default_sprite(game_t *gen);
        //gen_manage.c
            int gen_manage(game_t *gen);
        //generator.c
            int generator(game_t *gen, int size);
        //sprite_generator.c
            int sprite_generator(game_t *gen, int **original);
        //init_generator.c
            generator_t *init_generator(void);
        //seed_manage.c
            int seed_manage(game_t *gen);
        //free_generator.c
            void free_generator(game_t *gen);

    //Scenes
        //MainMenu
            //mainmenu.c
                void mainmenu(game_t *game, scenes_t **scenes);
            //credits.c
                void credits(game_t *game, scenes_t **scenes);
            //credits.c
                void htp(game_t *game, scenes_t **scenes);
            //option.c
                void option(game_t *game, scenes_t **scenes);
                //option_keys.c
                    text_t **init_option_text(game_t *game);
            //map_s.c
                void map_s(game_t *game, scenes_t **scenes);
        //Game
            //init_main_game.c
                object_t **init_game_map(game_t *game);
            //maingame.c
                void maingame(game_t *game, scenes_t **scenes);
                object_t *render_map(game_t *game, int height, int width);
                object_t **init_game_map(game_t *game);
            //player.c
                void move_player_rect(game_t *game, int offset, int max_value);
                void manage_key_up(game_t *game);
                void manage_key_down(game_t *game);
                void manage_key_right(game_t *game);
                void manage_key_left(game_t *game);
            //player2.c
                void manage_key_attack(game_t *game);
                void check_attack(game_t *game, scenes_t **scenes);
            //pause.c
                void pause_game(game_t *game, scenes_t **scenes);
                //textspause.c
                    text_t **init_pause_texts(game_t *game);
                //pause.c
                    void optpause(game_t *game, scenes_t **scenes);

    //EventHandler
        //Game
            //evtmaingame.c
                void main_game_evt(game_t *game, scenes_t **scenes,
                button_t **game_btn);
            //evtpause.c
                void pause_game_evt(game_t *game, scenes_t **scenes,
                button_t **pause_btn);
                //evtoptpause.c
                    void optpause_evt(game_t *game, scenes_t **scenes,
                    button_t **optpause_btn);
        //MainMenu
            //evtmainmenu.c
                void main_menu_evt(game_t *game, scenes_t **scenes,
                button_t **m_button);
            //evtcredits.c
                void credits_evt(game_t *game, scenes_t **scenes,
                button_t **credits_button);
            //evthtp.c
                void htp_evt(game_t *game, scenes_t **scenes,
                button_t **htp_button);
            //evtoption.c
                void option_evt(game_t *game, scenes_t **scenes,
                button_t **option_button, text_t **option_texts);
            //evtmap_s.c
                void map_s_evt(game_t *game, scenes_t **scenes,
                button_t **map_s_button);

    //BtnHandler
        //Game
            //btnmaingame.c
                void main_game_bhc(button_t **m_button, game_t *game);
                void main_game_bhh(button_t **m_button, game_t *game);
            //btnpause.c
                void pause_bhc(button_t **pause_button, game_t *game,
                scenes_t **scenes);
                void pause_bhh(button_t **pause_button, game_t *game);
                //btnpause.c
                    void optpause_bhc(button_t **optpause_btn, game_t *game);
                    void optpause_bhh(button_t **optpause_btn, game_t *game);
        //MainMenu
            //btnmainmenu.c
                void main_menu_bhc(button_t **m_button, game_t *game,
                scenes_t **scenes);
                void main_menu_bhh(button_t **m_button, game_t *game);
            //btncredits.c
                void credits_bhc(button_t **credits_button, game_t *game);
                void credits_bhh(button_t **credits_button, game_t *game);
            //btnhtp.c
                void htp_bhc(button_t **htp_button, game_t *game);
                void htp_bhh(button_t **htp_button, game_t *game);
            //btnoption.c
                void option_bhc(button_t **option_button, game_t *game);
                void option_bhh(button_t **option_button, game_t *game);
            //sboption.c
                void option_sbh(spinbox_t *spinbox, game_t *game);
                void option_sbhc(spinbox_t *spinbox, game_t *game);
            //btnoption.c
                void map_s_bhc(button_t **map_s_button, game_t *game,
                scenes_t **scenes);
                void map_s_bhh(button_t **map_s_button, game_t *game);
    //enemys_handler
        //structs
            //enemy_init.c
                enemy_t *init_enemy(char *spritesheet,
                    sfVector2f pos, sfIntRect rect);
                enemy_t **init_enemy_arr(size_t size, sfVector2f *pos);
            //enemy_destroy.c
                void destroy_enemy(enemy_t *mob);
                void destroy_enemy_arr(enemy_t **arr);
        //animation
            //handle_enemy.c
                void handle_enemy(player_t *player, enemy_t *enemy);
                void dies(enemy_t *enemy);
                int move_die(sfIntRect *rect, int offset, int max_value);
            //enemy_moves.c
                void mob_animate(int posture, enemy_t *mob, player_t *user,
                    int lr);
        //utils
            //utils.c
                int in_range(player_t *player, enemy_t *enemy);
                void mod_stats(stats_t *car_stats, stats_t income);
#endif /* !MY_H_ */
