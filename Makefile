# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 11:53:00 by dramos-j          #+#    #+#              #
#    Updated: 2024/07/06 16:00:15 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c stack_management.c swap.c push.c rotate.c reverse_rotate.c
OBJS = $(SRCS:.c=.o) # change the source file to object file
AR = ar rc # archive command to create a static library. r - replace, if the library already exists, c - create a new library
RM = rm -rf # remove command. r - recursive, if the directory is not empty, f - force, ignore nonexistent files and arguments
CP = cp # copy command. 

all: $(NAME) # make all will compile the library and the bonus

$(NAME): $(OBJS) # compile the library push_swap.a and the library libftprintf.a with the object files
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	$(CP) $(LIBFTPRINTF) $(NAME)
	$(AR) $(NAME) $(OBJS)


%.o:%.c # compile the source file to object file
	$(CC) $(CFLAGS) -c $^ -o $@

clean: # remove the object files in the library libftprintf.a and the push_swap.a
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean # make clean and remove the library push_swap.a and the library libftprintf.a
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(NAME)

re: fclean all # make fclean and make all

.PHONY: all clean fclean re # make the commands all, clean, fclean, and re as phony targets so that they are not confused with files of the same name
.SILENT: # silence the commands that are executed