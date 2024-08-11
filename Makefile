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
SRCS = check_args.c main.c \
		swap.c push.c rotate.c reverse_rotate.c \
		stack_management.c stack_utils.c stack_sort.c 
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
