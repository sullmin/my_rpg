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

SRC_GUI		=	$(DSRC)gui/widget/inputs/button/create_button.c	\
				$(DSRC)gui/widget/inputs/button/destroy_button.c	\
				$(DSRC)gui/widget/inputs/button/display_button.c	\
				$(DSRC)gui/widget/inputs/button/set_button.c		\
				$(DSRC)gui/widget/inputs/button/event_button.c		\
				$(DSRC)gui/widget/inputs/slider/create_slider.c	\
				$(DSRC)gui/widget/inputs/slider/destroy_slider.c	\
				$(DSRC)gui/widget/inputs/slider/display_slider.c	\
				$(DSRC)gui/widget/inputs/slider/set_slider.c		\
				$(DSRC)gui/widget/inputs/slider/event_slider.c		\
				$(DSRC)gui/widget/inputs/slider/get_value_slider.c	\
				$(DSRC)gui/widget/inputs/text_input/text_input_config_char.c	\
				$(DSRC)gui/widget/inputs/text_input/text_input_config.c			\
				$(DSRC)gui/widget/inputs/text_input/text_input_create_destroy.c	\
				$(DSRC)gui/widget/inputs/text_input/text_input_buffer.c			\
				$(DSRC)gui/widget/inputs/text_input/text_input_run.c			\
				$(DSRC)gui/widget/inputs/text_input/text_input_status.c			\
				$(DSRC)gui/widget/outputs/image_viewer/image_viewer_create_destroy.c	\
				$(DSRC)gui/widget/outputs/image_viewer/image_viewer_display.c			\
				$(DSRC)gui/widget/outputs/image_viewer/image_viewer_update_status.c		\
				$(DSRC)gui/widget/outputs/progress_bar/progress_create_destroy.c		\
				$(DSRC)gui/widget/outputs/progress_bar/progress_config.c				\
				$(DSRC)gui/widget/outputs/progress_bar/progress_display.c				\
				$(DSRC)gui/widget/outputs/progress_bar/progress_set_percentage.c		\

#SRC_FIGHT	=	$(DSRC)game/fight_mode/
#SRC_MWORLD =	$(DSRC)game/main_world/

SRC_ISO	=	$(DSRC)game/iso_world/iso_world_create.c						\
			$(DSRC)game/iso_world/iso_world_destroy.c						\
			$(DSRC)game/iso_world/iso_world_run.c							\
			$(DSRC)game/iso_world/iso_world_event_manager.c					\
			$(DSRC)game/iso_world/constant.c								\
			$(DSRC)game/iso_world/object/object_create.c					\
			$(DSRC)game/iso_world/object/object_lines_create.c				\
			$(DSRC)game/iso_world/object/object_2d_matrix_create.c			\
			$(DSRC)game/iso_world/object/object_destroy.c					\
			$(DSRC)game/iso_world/object/object_display.c					\
			$(DSRC)game/iso_world/object/object_project_iso_point.c			\
			$(DSRC)game/iso_world/object/object_texture_create.c			\
			$(DSRC)game/iso_world/object/object_reload.c					\
			$(DSRC)game/iso_world/object/object_tools_view.c				\
			$(DSRC)game/iso_world/object/object_on_map.c					\
			$(DSRC)game/iso_world/object/object_config.c					\
			$(DSRC)game/iso_world/map/filemap/load_map.c					\
			$(DSRC)game/iso_world/map/filemap/fill_map.c					\
			$(DSRC)game/iso_world/map/map_scale.c							\
			$(DSRC)game/iso_world/map/map_tools_view.c						\
			$(DSRC)game/iso_world/map/map_vertex_create_destroy.c			\
			$(DSRC)game/iso_world/map/map_texture_vertex_create_destroy.c	\
			$(DSRC)game/iso_world/map/map_texture_create_destroy.c			\
			$(DSRC)game/iso_world/map/map_create_destroy.c					\
			$(DSRC)game/iso_world/map/map_3d_create_destroy.c				\
			$(DSRC)game/iso_world/map/map_2d_create_destroy.c				\
			$(DSRC)game/iso_world/map/map_display.c							\
			$(DSRC)game/iso_world/map/map_display_water.c					\
			$(DSRC)game/iso_world/map/project_iso_point.c					\
			$(DSRC)game/iso_world/map/map_update.c							\
			$(DSRC)game/iso_world/map/map_resize.c							\
			# $(DSRC)game/iso_world/event/event_manager.c						\
			# $(DSRC)game/iso_world/event/event_init.c						\
			# $(DSRC)game/iso_world/event/event_mouse.c						\
			# $(DSRC)game/iso_world/event/event_keyboard.c					\
			# $(DSRC)game/iso_world/event/event_window.c						\
			# $(DSRC)game/iso_world/event_action/action_mouse_gui_button.c	\
			# $(DSRC)game/iso_world/event_action/action_gui_button_left.c		\
			# $(DSRC)game/iso_world/event_action/action_gui_button_top.c		\
			# $(DSRC)game/iso_world/event_action/action_resize_shortcut.c		\
			# $(DSRC)game/iso_world/event_action/action_mouse_clicked.c		\
			# $(DSRC)game/iso_world/event_action/action_show_click.c			\
			# $(DSRC)game/iso_world/event_action/action_texture.c				\
			# $(DSRC)game/iso_world/event_action/action_manager.c				\
			# $(DSRC)game/iso_world/event_action/action_map_file.c			\
			# $(DSRC)game/iso_world/event_action/action_update_text_gui.c		\
			# $(DSRC)game/iso_world/event_action/action_object_move.c			\
			# $(DSRC)game/iso_world/event_action/action_ui_button_tool.c 		\

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

SRC_MENU 	=	$(DSRC)menu/main/create_main_menu.c						\
				$(DSRC)menu/main/destroy_main_menu.c					\
				$(DSRC)menu/main/display_main_menu.c					\
				$(DSRC)menu/main/event_main_menu.c						\

SRC_OPTION_MENU =	$(DSRC)menu/option/create_option_menu.c				\
					$(DSRC)menu/option/destroy_option_menu.c			\
					$(DSRC)menu/option/display_option_menu.c			\
					$(DSRC)menu/option/event_option_menu.c				\
					$(DSRC)menu/option/set_keyboard_config.c			\

SRC_PAUSE_MENU	=	$(DSRC)menu/pause/create_pause_menu.c				\
					$(DSRC)menu/pause/destroy_pause_menu.c				\
					$(DSRC)menu/pause/display_pause_menu.c				\
					$(DSRC)menu/pause/event_pause_menu.c				\

SRC_GAME	=	$(DSRC)game/game_create.c								\
				$(DSRC)game/game_destroy.c								\
				$(DSRC)game/game_loop.c									\
				$(DSRC)game/game_event.c								\
				$(DSRC)game/function_array.c							\

SRC_TOOLS	=	$(DSRC)tools/my_math.c									\

SRC_MAIN	=	$(DSRC)main.c											\
				$(DSRC)usage.c											\
				$(DSRC)master.c											\

SRC			= $(SRC_MAIN) $(SRC_TOOLS) $(SRC_GAME) $(SRC_WINDOW) $(SRC_SOUND) $(SRC_CONFIG) $(SRC_QUEST) $(SRC_INVENT) $(SRC_GUI) $(SRC_MENU) $(SRC_OPTION_MENU) $(SRC_PAUSE_MENU) $(SRC_ISO)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

INCLUDE = -I./include -I./lib/my/include  -I./include/iso_world

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
