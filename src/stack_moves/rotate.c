/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:50:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/24 11:18:03 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *a)
{
	if (rotate(a) == 1)
		ft_printf("ra\n");	
}

void	rb(t_stack *b)
{
	if (rotate(b) == 1)
		ft_printf("rb\n");	
}

void	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) == 1 || rotate(b) == 1)
		ft_printf("rr\n");
}

int	rotate(t_stack *stack)
{
	int	first;
	int	i;

	if (stack_size(stack) == 0)
		return (0);
	i = stack->top;
	first = stack->array[stack->top];
	while (i < stack_size(stack) - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack_size(stack) - 1] = first;
	return (1);
}
