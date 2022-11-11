# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 00:53:41 by erickbarros       #+#    #+#              #
#    Updated: 2022/11/11 13:49:46 by erickbarros      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = src/push_swap.c \

OBJ = $(SRC:.c=.o)

LIB_OBJ = ft_printf/src/*.o \
			ft_printf/libft/*.o \

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ft_printf
	@gcc $(CFLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C ft_printf/ fclean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
