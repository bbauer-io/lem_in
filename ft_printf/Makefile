# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#              #
#    Updated: 2017/05/09 15:10:12 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = gcc
LIBFT = ./../libft/libft.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS =  -fsanitize=address -g -o ft_printf_debug
LEAKCHECKFLAGS = -g -o ft_printf_leakcheck
SRCF =	apply_precision.c \
		apply_prefix.c \
		apply_width.c \
		apply_width_wchar.c \
		fix_sign_placement.c \
		ft_printf.c \
		ft_vprintf.c \
		read_flags.c \
		read_length.c \
		read_precision.c \
		read_specifier.c \
		read_width.c \
		save_chars_printed.c \
		verify_flag_compatibility.c \
		verify_flag_compatibility_continued.c \
		write_char.c \
		write_conversion_substr.c \
		write_hex.c \
		write_octal.c \
		write_signed_int.c \
		write_string.c \
		write_unsigned_int.c \
		write_wchar.c \
		write_wstring.c \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./../libft/
INCDIR = ./include/

.PHONY: all, clean, fclean, re

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT)
	@echo "Compiling ft_printf"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(OBJDIR)
	@ar rc $(NAME) $(OBJ) $(LIBFT)
	@echo "ft_printf: SUCCESS!"

$(LIBFT):
	make -C $(LIBDIR) all

clean:
	@echo "Cleaning ft_printf"
	@rm -rf $(OBJDIR)
	@rm -rf ft_printf_debug
	@rm -rf ft_printf_debug.dSYM
	@rm -rf ft_printf_leakcheck
	@rm -rf ft_printf_leakcheck.dSYM
	@make -C $(LIBDIR) clean

fclean: clean
	@echo "FCleaning ft_printf"
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

debug: $(LIBFT)
	@echo "Compiling ft_printf with debugging options"
	$(CC) $(SRC) ./tests/$(TEST) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT)
	@echo "Compiling ft_printf for leak checks with valgrind"
	$(CC) $(SRC) ./tests/$(TEST) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS)
