# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 07:44:39 by bbauer            #+#    #+#              #
#    Updated: 2017/05/30 07:30:03 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS =  -fsanitize=address -g -o lem_in_debug
LEAKCHECKFLAGS = -g -o lem_in_leakcheck
SRCF = ants_go_marching.c \
		lem_in.c \
		mark_shortest_path.c \
		print_debug.c \
		process_commands.c \
		queue_tools.c \
		read_map.c \
		read_tools.c \
		room_search.c \
		summon_ants.c \
		vanish_ant_farm.c \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./include/

.PHONY: all, clean, fclean, re

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF)
	@echo "Compiling lem_in"
	$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	mkdir -p $(OBJDIR)
	mv $(SRCF:.c=.o) $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@
	echo "lem_in: SUCCESS!"

$(LIBFT):
	@make -C $(LIBDIR) all

$(FT_PRINTF): $(LIBFT)
	@make -C $(FTPFDIR) all

clean:
	@echo "Cleaning lem_in"
	@rm -rf $(OBJDIR)
	@rm -f lem_in_debug
	@rm -rf lem_in_debug.dSYM
	@rm -f lem_in_leakcheck
	@rm -rf lem_in_leakcheck.dSYM
	@make -C $(LIBDIR) clean
	@make -C $(FTPFDIR) clean

fclean: clean
	@echo "FCleaning lem_in"
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling lem_in with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling lem_in for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS)
