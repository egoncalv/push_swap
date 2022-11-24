/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:20:42 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/24 11:33:50 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *a)
{
	if (reverse_rotate(a) == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b) == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (reverse_rotate(a) || reverse_rotate(b))
		ft_printf("rrr\n");
}

int	reverse_rotate(t_stack *stack)
{
	int	i;
	int last;

	stack->size = stack_size(stack);
	if (stack->size < 1)
		return (0);
	last = stack->array[stack->size - 1];
	i = stack->size - 1;
	while (i > stack->top)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[stack->top] = last;
	return (1);
}
