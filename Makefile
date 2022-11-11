# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 00:53:41 by erickbarros       #+#    #+#              #
#    Updated: 2022/11/11 17:18:35 by erickbarros      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = 	src/push_swap.c \
		src/utils.c

OBJ = $(SRC:.c=.o)

LIB_OBJ = 	ft_printf/src/*.o \
			ft_printf/libft/*.o \

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ft_printf
	@gcc $(CFLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)
	@echo "DONE"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(LIB_OBJ)

fclean: clean
	@$(MAKE) -C ft_printf/ fclean
	@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
