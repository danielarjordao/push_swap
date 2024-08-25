# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 14:38:10 by dramos-j          #+#    #+#              #
#    Updated: 2024/08/11 14:38:10 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = check_args.c \
		swap.c push.c rotate.c reverse_rotate.c \
		stack_manipulation.c stack_sort.c \
		stack_sort_utils.c stack_utils.c
MAIN = main.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf
CHECKER = checker
SRCS_BONUS = ./bonus/checker.c ./bonus/get_next_line/get_next_line.c \
			./bonus/get_next_line/get_next_line_utils.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MAIN)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(OBJS) $(LIBFTPRINTF)

bonus: $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS) $(OBJS_BONUS) $(LIBFTPRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
