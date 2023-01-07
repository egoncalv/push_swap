# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 00:53:41 by erickbarros       #+#    #+#              #
#    Updated: 2023/01/07 22:28:18 by egoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRC = 	src/push_swap.c \
		src/utils.c \
		src/stack_moves/stack_utils.c \
		src/stack_moves/push.c \
		src/stack_moves/swap.c \
		src/stack_moves/rotate.c \
		src/stack_moves/reverse_rotate.c \
		src/sort/sort_small.c \
		src/sort/sort_small_utils.c \
		src/sort/sort_medium.c \
		src/sort/sort_medium_utils.c \
		src/sort/midpoint.c \

BONUS_NAME = checker

BONUS = bonus/checker.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = bonus/checker.o

LIB_OBJ = 	ft_printf/src/*.o \
			ft_printf/libft/*.o \

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ft_printf
	@gcc $(CFLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)
	@echo "Mandatory compiled"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	@gcc $(CFLAGS) $(BONUS_OBJ) $(LIB_OBJ) -o $(BONUS_NAME)
	@echo "Bonus compiled"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(LIB_OBJ)
	@rm -rf $(BONUS_OBJ)

fclean: clean
	@$(MAKE) -C ft_printf/ fclean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
 