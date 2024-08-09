# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 11:53:00 by dramos-j          #+#    #+#              #
#    Updated: 2024/08/09 16:54:02 by dramos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = op_push.c op_reverse_rotate.c op_rotate.c op_swap.c stack_management.c stack_sort_utils.c stack_sort.c stack_utils.c check_args.c main.c
OBJS = $(SRCS:.c=.o) # Altera os arquivos .c para .o para serem compilados
RM = rm -rf # Comando para remover arquivos	e diretórios. -r remove recursivamente e -f força a remoção sem perguntar

all: $(NAME) # Comando para compilar o programa

$(NAME): $(OBJS) # Compila a biblioteca e o programa. -C entra no diretório e executa o comando
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

%.o:%.c # Compila os arquivos .c para .o
	$(CC) $(CFLAGS) -c $^ -o $@

clean: # remove os arquivos .o
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean # remove os arquivos .o e o executável
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(NAME)

re: fclean all # remove os arquivos .o e o executável e compila novamente

.PHONY: all clean fclean re # Indica que os comandos não são arquivos a serem compilados
.SILENT: # Não exibe os comandos executados
