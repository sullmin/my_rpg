##
## EPITECH PROJECT, 2020
## MUL_my_rpg_2019
## File description:
## Project makefile
##

DSRC	=	./src/

SRC_SOUND	=	$(DSRC)sound_manager/sound_manager_create_destroy.c		\
				$(DSRC)sound_manager/sound_manager_play_stop.c			\
				$(DSRC)sound_manager/sound_manager_show_list.c			\
				$(DSRC)sound_manager/sound_manager_config.c				\

SRC_CONFIG	=	$(DSRC)config_manager/config_manager_read.c				\
				$(DSRC)config_manager/config_manager_clean_lines.c		\
				$(DSRC)config_manager/config_manager_check_line.c		\
				$(DSRC)config_manager/config_manager_create_array.c		\
				$(DSRC)config_manager/config_manager.c					\

SRC_WINDOW	=	$(DSRC)window/window_create.c							\
				$(DSRC)window/window_destroy.c							\

SRC_GUI		=	$(DSRC)game/gui/widget/inputs/button/create_button.c	\
				$(DSRC)game/gui/widget/inputs/button/destroy_button.c	\
				$(DSRC)game/gui/widget/inputs/button/display_button.c	\
				$(DSRC)game/gui/widget/inputs/button/set_button.c		\
				$(DSRC)game/gui/widget/inputs/button/event_button.c		\
				$(DSRC)game/gui/widget/inputs/slider/create_slider.c	\
				$(DSRC)game/gui/widget/inputs/slider/destroy_slider.c	\
				$(DSRC)game/gui/widget/inputs/slider/display_slider.c	\
				$(DSRC)game/gui/widget/inputs/slider/set_slider.c		\
				$(DSRC)game/gui/widget/inputs/slider/event_slider.c		\
				$(DSRC)game/gui/widget/inputs/slider/get_value_slider.c	\

#SRC_FIGHT	=	$(DSRC)game/fight_mode/
#SRC_ISO	=	$(DSRC)game/iso_world/
#SRC_MWORLD =	$(DSRC)game/main_world/

SRC_QUEST 	=	$(DSRC)quest_system/array_quest.c					\
				$(DSRC)quest_system/quest_create_destroy.c			\
				$(DSRC)quest_system/quest_enable.c					\
				$(DSRC)quest_system/quest_finish.c					\
				$(DSRC)quest_system/quest_check_end.c				\
				$(DSRC)quest_system/dialogue/dialogue_load.c		\
				$(DSRC)quest_system/dialogue/dialogue_destroy.c		\
				$(DSRC)quest_system/dialogue/dialogue_display.c		\
				$(DSRC)quest_system/dialogue/dialogue_event_manager.c	\
				$(DSRC)quest_system/dialogue/dialogue_play.c		\

SRC_INVENT =	$(DSRC)inventory_system/chaine_list.c					\
				$(DSRC)inventory_system/get_inventory.c					\
				$(DSRC)inventory_system/destroy_item.c					\
				$(DSRC)inventory_system/dup_item.c						\
				$(DSRC)inventory_system/item_load.c						\
				$(DSRC)inventory_system/is_in_inv.c						\
				$(DSRC)inventory_system/add_item_in_player_inv.c		\

SRC_MENU 	=	$(DSRC)main_menu/create_main_menu.c						\
				$(DSRC)main_menu/destroy_main_menu.c					\
				$(DSRC)main_menu/display_main_menu.c					\
				$(DSRC)main_menu/event_main_menu.c						\

SRC_GAME	=	$(DSRC)game/game_create.c								\
				$(DSRC)game/game_destroy.c								\
				$(DSRC)game/game_loop.c									\
				$(DSRC)game/game_event.c								\
				$(DSRC)game/function_array.c							\

SRC_MAIN	=	$(DSRC)main.c											\
				$(DSRC)usage.c											\
				$(DSRC)master.c											\
				$(DSRC)my_math.c											\

SRC			= $(SRC_MAIN) $(SRC_GAME) $(SRC_WINDOW) $(SRC_SOUND) $(SRC_CONFIG) $(SRC_QUEST) $(SRC_INVENT) $(SRC_GUI) $(SRC_MENU)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

INCLUDE = -I./include -I./lib/my/include

CSFML_FLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

CFLAGS	+= -Wall -Wextra -W $(INCLUDE) -g #-Werror

all:  lib $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	@gcc -o $(NAME) $(OBJ) -L./lib/my -lmy $(CSFML_FLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

lib:
	make -C ./lib/my

lib_re:
	make re -C ./lib/my

lib_fclean:
	make fclean -C lib/my

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

reall:	fclean all lib_re

#tests_run:
#gcc -o $(NAME) $(SRC_UT) -I./include -L./lib/my -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LINE_RETURN	=	$(ECHO) ""
