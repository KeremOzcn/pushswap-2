# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 10:56:51 by kozcan            #+#    #+#              #
#    Updated: 2025/03/15 15:31:10 by kozcan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDE = push_swap.h

SRC = push_swap.c \
	  handle_errors.c \
	  stack_utils.c	\
	  fill_stack.c \
	  commands/swap.c \
	  commands/push.c \
	  commands/reverse.c \
	  sort_utils.c \
	  movements.c \
	  sort.c \
	  commands/rotate.c

LIBFT = lib/libft/libft.a

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C lib/libft

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)
	make clean -C lib/libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/libft

re: fclean all

.PHONY: all clean fclean re

valg:
	