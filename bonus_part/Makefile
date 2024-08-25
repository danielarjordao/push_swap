# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 15:55:24 by dramos-j          #+#    #+#              #
#    Updated: 2024/08/24 15:55:24 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf
GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  main.c check_args.c stack_utils.c \
		swap.c push.c rotate.c reverse_rotate.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF) $(GET_NEXT_LINE)

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

