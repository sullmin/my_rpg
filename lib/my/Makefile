##
## EPITECH PROJECT, 2019
## LIBMY_2019
## File description:
## LIBMY Makefile
##

DNBR = nbr/
DSTR = str/

SRC	=	$(DNBR)my_compute_power_rec.c	\
		$(DNBR)my_compute_square_root.c	\
		$(DNBR)convert_base.c			\
		$(DNBR)my_factorial_it.c		\
		$(DNBR)my_power_rec.c			\
		$(DNBR)my_sqrt.c				\
		$(DNBR)my_find_prime_sup.c		\
		$(DNBR)my_getnbr.c				\
		$(DNBR)my_getnbr_base.c			\
		$(DNBR)my_isneg.c				\
		$(DNBR)my_is_prime.c			\
		$(DNBR)my_putnbr_base.c			\
		$(DNBR)my_put_double.c      	\
		$(DNBR)my_putnbr_base_str.c		\
		$(DNBR)my_put_nbr.c				\
		$(DNBR)quick_sort.c				\
		$(DNBR)my_sort_int_array.c		\
		$(DNBR)my_swap.c				\
		read_file.c						\
		get_next_line.c					\
		$(DSTR)my_putchar.c				\
		$(DSTR)my_putstr_error.c		\
		$(DSTR)my_putstr.c				\
		$(DSTR)my_revstr.c				\
		$(DSTR)my_showmem.c					\
		$(DSTR)my_showstr.c					\
		$(DSTR)my_advanced_sort_word_array.c\
		$(DSTR)my_show_word_array.c 		\
		$(DSTR)my_sort_word_array.c 		\
		$(DSTR)my_str_to_word_array.c 		\
		$(DSTR)word_array.c 				\
		$(DSTR)my_strcapitalize.c			\
		$(DSTR)my_strcat.c					\
		$(DSTR)my_strcmp.c					\
		$(DSTR)my_strcpy.c					\
		$(DSTR)my_strdup.c					\
		$(DSTR)my_str_isalpha.c				\
		$(DSTR)my_str_islower.c				\
		$(DSTR)my_str_isnum.c				\
		$(DSTR)my_str_isprintable.c			\
		$(DSTR)my_str_isupper.c				\
		$(DSTR)my_strlen.c					\
		$(DSTR)my_strlowcase.c				\
		$(DSTR)my_strncat.c					\
		$(DSTR)my_strncmp.c					\
		$(DSTR)my_strncpy.c					\
		$(DSTR)my_strstr.c					\
		$(DSTR)my_strupcase.c				\
		$(DSTR)my_printf.c             		\
		$(DSTR)my_printf_display.c     		\
		$(DSTR)my_printf_disp01.c      		\
		$(DSTR)my_printf_disp02.c      		\
		$(DSTR)my_printf_disp03.c			\
		$(DSTR)my_printf_disp_misc.c   		\
		$(DSTR)my_printf_misc.c        		\
		$(DSTR)my_printf_search.c			\

DINCLUDE = ../../include

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W -Werror -I$(DINCLUDE)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	@cp my.h $(DINCLUDE)
	@cp my_printf.h $(DINCLUDE)
	@cp get_next_line.h $(DINCLUDE)
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	clean all

.PHONY :        clean fclean re
