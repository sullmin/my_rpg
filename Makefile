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

SRC_FIGHT	=	$(DSRC)game/fight_mode/create_events.c 					\
				$(DSRC)game/fight_mode/fight.c 							\
				$(DSRC)game/fight_mode/run.c 							\
				$(DSRC)game/fight_mode/fight_post_end_action.c			\
				$(DSRC)game/fight_mode/fight_config.c					\

SRC_MWORLD 	=	$(DSRC)game/main_world/create_main_world.c							\
				$(DSRC)game/main_world/destroy_main_world.c							\
				$(DSRC)game/main_world/display_main_world.c							\
				$(DSRC)game/main_world/box/display_box.c							\
				$(DSRC)game/main_world/box/move_box.c								\
				$(DSRC)game/main_world/box/check_box_on_pos.c						\
				$(DSRC)game/main_world/event_main_world.c							\
				$(DSRC)game/main_world/event_player.c								\
				$(DSRC)game/main_world/player_move.c								\
				$(DSRC)game/main_world/update_map_position.c						\
				$(DSRC)game/main_world/player_position_on_map.c						\
				$(DSRC)game/main_world/is_right_position.c							\
				$(DSRC)game/main_world/player_show_hitbox.c							\
				$(DSRC)game/main_world/player_animation/player_animation_player.c	\
				$(DSRC)game/main_world/player_animation/player_animation_manage.c	\
				$(DSRC)game/main_world/player_animation/input_manage.c				\
				$(DSRC)game/main_world/player_animation/sound.c						\
				$(DSRC)game/main_world/pnj/init_pnj.c								\
				$(DSRC)game/main_world/pnj/pnj_move.c								\
				$(DSRC)game/main_world/pnj/pnj_col.c								\
				$(DSRC)game/main_world/pnj/pnj_evolution.c							\
				$(DSRC)game/main_world/pnj/pnj_act.c								\
				$(DSRC)game/main_world/xp_bar/create_xp_bar.c						\
				$(DSRC)game/main_world/xp_bar/display_xp_bar.c						\
				$(DSRC)game/main_world/xp_bar/update_xp_bar.c						\
				$(DSRC)game/main_world/xp_bar/add_xp.c								\

SRC_ISO	=	$(DSRC)game/iso_world/iso_world_create.c						\
			$(DSRC)game/iso_world/iso_world_destroy.c						\
			$(DSRC)game/iso_world/iso_world_run.c							\
			$(DSRC)game/iso_world/iso_world_event_manager.c					\
			$(DSRC)game/iso_world/player_movement.c							\
			$(DSRC)game/iso_world/tp_point.c								\
			$(DSRC)game/iso_world/camera_move.c								\
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
			$(DSRC)game/iso_world/object/object_on_map_move.c				\
			$(DSRC)game/iso_world/object/object_config.c					\
			$(DSRC)game/iso_world/map/filemap/load_map.c					\
			$(DSRC)game/iso_world/map/filemap/fill_map.c					\
			$(DSRC)game/iso_world/map/map_scale.c							\
			$(DSRC)game/iso_world/map/map_tools_view.c						\
			$(DSRC)game/iso_world/map/map_vertex_create_destroy.c			\
			$(DSRC)game/iso_world/map/map_texture_vertex_destroy.c			\
			$(DSRC)game/iso_world/map/map_texture_vertex_create.c			\
			$(DSRC)game/iso_world/map/map_texture_create_destroy.c			\
			$(DSRC)game/iso_world/map/map_create_destroy.c					\
			$(DSRC)game/iso_world/map/map_3d_create_destroy.c				\
			$(DSRC)game/iso_world/map/map_2d_create_destroy.c				\
			$(DSRC)game/iso_world/map/map_display.c							\
			$(DSRC)game/iso_world/map/map_display_water.c					\
			$(DSRC)game/iso_world/map/project_iso_point.c					\
			$(DSRC)game/iso_world/map/map_update.c							\
			$(DSRC)game/iso_world/map/map_resize.c							\
			$(DSRC)game/iso_world/event/event_mouse.c						\
			$(DSRC)game/iso_world/event/event_keyboard.c					\
			$(DSRC)game/iso_world/event/event_object_move.c					\
			$(DSRC)game/iso_world/kinematic/kinem_create_destroy.c			\
			$(DSRC)game/iso_world/kinematic/kinem_run.c						\
			$(DSRC)game/iso_world/kinematic/kinem_start_stop.c				\
			$(DSRC)game/iso_world/kinematic/kinem_event.c					\

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
				$(DSRC)inventory_system/inventory_display.c				\
				$(DSRC)inventory_system/get_loot.c						\

SRC_MENU 	=	$(DSRC)menu/main/create_main_menu.c						\
				$(DSRC)menu/main/destroy_main_menu.c					\
				$(DSRC)menu/main/display_main_menu.c					\
				$(DSRC)menu/main/event_main_menu.c						\
				$(DSRC)menu/stat_inventory/display_player_stat.c		\
				$(DSRC)menu/stat_inventory/init_display_stat.c			\
				$(DSRC)menu/stat_inventory/display_player_gui.c			\
				$(DSRC)menu/quest/menu_quest_create_destroy.c			\
				$(DSRC)menu/quest/menu_quest_display.c					\
				$(DSRC)menu/quest/menu_quest_event.c					\
				$(DSRC)menu/quest/menu_quest_load_quest.c				\
				$(DSRC)menu/quest/menu_quest_reload.c					\
				$(DSRC)menu/submenu_event_manager.c						\
				$(DSRC)menu/credit/credit_menu_create_destroy.c			\
				$(DSRC)menu/credit/credit_menu_display.c				\
				$(DSRC)menu/credit/credit_menu_event.c					\

SRC_OPTION_MENU =	$(DSRC)menu/option/create_option_menu.c				\
					$(DSRC)menu/option/create_option_menu_button.c		\
					$(DSRC)menu/option/destroy_option_menu.c			\
					$(DSRC)menu/option/display_option_menu.c			\
					$(DSRC)menu/option/event_option_menu.c				\
					$(DSRC)menu/option/set_keyboard_config.c			\

SRC_PAUSE_MENU	=	$(DSRC)menu/pause/create_pause_menu.c				\
					$(DSRC)menu/pause/destroy_pause_menu.c				\
					$(DSRC)menu/pause/display_pause_menu.c				\
					$(DSRC)menu/pause/event_pause_menu.c				\

SRC_HELP_MENU	=	$(DSRC)menu/help/create_help_menu.c					\
					$(DSRC)menu/help/destroy_help_menu.c				\
					$(DSRC)menu/help/display_help_menu.c				\
					$(DSRC)menu/help/event_help_menu.c					\

SRC_GAME	=	$(DSRC)game/game_create.c								\
				$(DSRC)game/game_destroy.c								\
				$(DSRC)game/game_loop.c									\
				$(DSRC)game/game_event.c								\
				$(DSRC)game/function_array.c							\
				$(DSRC)game/set_game_state.c							\

SRC_TOOLS	=	$(DSRC)tools/my_math.c									\
				$(DSRC)tools/as_second.c								\
				$(DSRC)tools/is_key_check_event.c						\

SRC_MAIN	=	$(DSRC)main.c											\
				$(DSRC)usage.c											\
				$(DSRC)master.c											\

SRC_PARTICLES	=	$(DSRC)particles/particles.c						\
					$(DSRC)particles/jump_pixels.c						\
					$(DSRC)particles/sand.c								\
					$(DSRC)particles/reload_particules.c				\
					$(DSRC)particles/particule_manage.c					\

SRC			= $(SRC_MAIN) $(SRC_TOOLS) $(SRC_GAME) $(SRC_WINDOW) $(SRC_SOUND) $(SRC_CONFIG) $(SRC_QUEST) $(SRC_INVENT) $(SRC_GUI) $(SRC_MENU) $(SRC_OPTION_MENU) $(SRC_PAUSE_MENU) $(SRC_HELP_MENU) $(SRC_ISO) $(SRC_MWORLD) $(SRC_FIGHT) $(SRC_PARTICLES)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

INCLUDE = -I./include/ -I./lib/my/include -I./lib/graph/include -I./include/iso_world  -I./include/interface -I./include/gui

CSFML_FLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

CFLAGS	+= -Wall -Wextra -W $(INCLUDE) -g# -Werror

all:  lib $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	make -C ./lib/graph
	@gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -L./lib/graph -lgraph $(CSFML_FLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

lib:
	make -C ./lib/my
	make -C ./lib/graph

lib_re:
	make re -C ./lib/my
	make re -C ./lib/graph

lib_fclean:
	make fclean -C lib/my
	make fclean -C lib/graph

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
