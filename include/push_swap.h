/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:29 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/23 19:03:18 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"

typedef struct	s_stack
{
	int	top;
	int	size;
	int	*array;
}		t_stack;


int		is_duplicate(t_stack *stack, int num);
int		is_nbr(char	*argv);
int		stack_size(t_stack *stack);

void	exit_error(void);

int		swap(t_stack *stack);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);

#endif
