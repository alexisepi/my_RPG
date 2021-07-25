##
## EPITECH PROJECT, 2020
## Exiel Makefile
## File description:
## The Makefile created by Exiel for his projects
##

SRC =	src/main.c				\
		src/errorhandler.c		\
		src/init_struct.c		\
		src/init_struct2.c		\
		src/init_option.c		\
		src/init_option2.c		\
		src/utils.c				\
		src/position_check.c	\
		src/destroyer.c			\
\
		src/generator/calc_data.c			\
		src/generator/default_maps.c		\
		src/generator/default_sprite.c		\
		src/generator/gen_manage.c			\
		src/generator/generator.c			\
		src/generator/seed_manage.c			\
		src/generator/init_generator.c		\
		src/generator/sprite_generator.c	\
		src/generator/free_generator.c		\
\
		src/enemys_handler/animation/enemy_moves.c		\
		src/enemys_handler/animation/handle_enemy.c		\
		src/enemys_handler/structs/enemy_destroy.c		\
		src/enemys_handler/structs/enemy_init.c 		\
		src/enemys_handler/utils/utils.c				\
\
		src/scenes/main_menu/main_menu/btnmainmenu.c	\
		src/scenes/main_menu/main_menu/evtmainmenu.c	\
		src/scenes/main_menu/main_menu/main_menu.c		\
\
		src/scenes/main_menu/credits/btncredits.c		\
		src/scenes/main_menu/credits/evtcredits.c		\
		src/scenes/main_menu/credits/credits.c			\
\
		src/scenes/main_menu/how_to_play/btnhtp.c		\
		src/scenes/main_menu/how_to_play/evthtp.c		\
		src/scenes/main_menu/how_to_play/how_to_play.c	\
\
		src/scenes/main_menu/option/btnoption.c			\
		src/scenes/main_menu/option/evtoption.c			\
		src/scenes/main_menu/option/option.c			\
		src/scenes/main_menu/option/sboption.c			\
		src/scenes/main_menu/option/option_keys.c		\
\
		src/scenes/main_menu/map_selector/btnmap_s.c	\
		src/scenes/main_menu/map_selector/evtmap_s.c	\
		src/scenes/main_menu/map_selector/map_s.c		\
\
		src/scenes/game/main_game/btnmaingame.c			\
		src/scenes/game/main_game/evtmaingame.c			\
		src/scenes/game/main_game/main_game.c			\
		src/scenes/game/main_game/init_main_game.c		\
		src/scenes/game/main_game/player.c				\
		src/scenes/game/main_game/render_map.c			\
		src/scenes/game/main_game/player2.c				\
\
		src/scenes/game/pause/btnpause.c				\
		src/scenes/game/pause/evtpause.c				\
		src/scenes/game/pause/pausegame.c				\
		src/scenes/game/pause/textspause.c				\
\
		src/scenes/game/pause/opt_pause/btnoptpause.c	\
		src/scenes/game/pause/opt_pause/evtoptpause.c	\
		src/scenes/game/pause/opt_pause/optpause.c

TESTS =

BUILD_DIR = build
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
CC = gcc
CFLAGS = -W -Wall -I includes/ -L./lib -lecl -L./lib -lmylibbox -lecsfml -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
EXEC = my_rpg

#Mandatory rules

all: lib head h_normal $(EXEC)

$(EXEC): $(OBJ)
			@gcc -o $(EXEC) $(OBJ) $(CFLAGS)
			@echo
			@echo -n "Compilation Finished"

clean:
			@rm -f $(OBJ)
			rm -f *.gcda
			rm -f *.gcno
			@echo

fclean: clean
			rm -f $(EXEC)
			rm -f unit_tests
			@echo

re: fclean lib head h_normal $(EXEC)

#Additional rules

$(BUILD_DIR)/%.o: %.c
					@mkdir -p $(@D)
					@echo -e "\x1b[32m  GCC       $<\x1b[0m"
					@$(CC) $(CFLAGS) -c $< -o $@

head:
			@echo "╔═══════════════════════════════╗"
			@echo "║  _____          _          _  ║"
			@echo "║ |  ___|        (_)        | | ║"
			@echo "║ | |__   __  __  _    ___  | | ║"
			@echo "║ |  __|  \ \/ / | |  / _ \ | | ║"
			@echo "║ | |___   >  <  | | |  __/ | | ║"
			@echo "║ \____/  /_/\_\ |_|  \___| |_| ║"
			@echo "║                               ║"

h_normal:
			@echo "║  Compiling a Common Project.  ║"
			@echo "╚═══════════════════════════════╝"
			@echo

h_debug:
			@echo "║   Debuging a Common Project.  ║"
			@echo "╚═══════════════════════════════╝"
			@echo

debug: CFLAGS += -g
debug: fclean $(OBJ)
			@gcc -o $(EXEC) $(OBJ) $(CFLAGS)
			@echo
			@echo "----------------------------------"
			@echo
			@echo -e "\x1b[31m  WARNING\x1b[0m"
			@echo -e "\x1b[31mDEBUG CALLED\x1b[0m"
			@echo
			@echo -n "PROGRAM ARGUMENTS(Enter for None): "; \
			read PROGRAM_ARGUMENTS; \
			valgrind --track-origins=yes --leak-check=full ./$(EXEC) $${PROGRAM_ARGUMENTS} 2> valgrind_trace

lib:
			make re -C lib/exielcl
			make re -C lib/exielcsfml
			make re -C lib/my_libbox

pushgit: fclean
			@echo
			@echo "----------------------------------"
			@echo
			@echo -e "\x1b[31m    WARNING\x1b[0m"
			@echo -e "\x1b[31mPUSHGIT  CALLED\x1b[0m"
			@echo
			@echo -n "Are you sure? [y/N] " && read ans && [ $${ans:-N} = y ]
			@git add -A
			@echo -n "NAME OF THE COMMIT: "; \
			read COMMIT_NAME; \
			git commit -m "$${COMMIT_NAME}"
			git push

.PHONY: lib clean fclean