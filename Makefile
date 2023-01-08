# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:59:17 by iabkadri          #+#    #+#              #
#    Updated: 2023/01/08 22:29:32 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDE := -I includes/
HEADERS := includes/push_swap.h		\
			includes/libft.h		\
			includes/ft_fprintf.h

OBJ_DIR := ./obj/
SRC_DIR := ./src/
LIB_DIR := ./lib/

SRCS := main.c				\
		swap.c				\
		push.c				\
		rotate.c			\
		reverse_rotate.c	\
		quick_sort.c		\
		heap_sort.c			\
		best_move.c			\
		sort_three.c		\
		small_sort.c		\
		sort_five.c			\
		error.c
LIBFT_SRCS = $(SRC_DIR)libft/*.c
FPRINTF_SRCS = $(SRC_DIR)ft_fprintf/*.c

OBJS = $(addprefix $(OBJ_DIR),$(SRCS:%.c=%.o))

NAME := push_swap
LIBS = $(LIB_DIR)*.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(SRC_DIR)libft
	@make -C $(SRC_DIR)ft_fprintf
	$(CC) $^ $(LIBS) -o $@

$(OBJ_DIR)%.o: %.c $(LIBFT_SRCS) $(FPRINTF_SRCS) $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(LIB_DIR)
re: fclean all
