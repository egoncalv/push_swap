/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:22:21 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/23 19:08:37 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *a)
{
	if (swap(a) == 1)
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b) == 1)
		ft_printf("sb\n");
}

int	swap(t_stack *stack)
{
	int	tmp;

	if (stack_size(stack) < 2)
		return (0);
	tmp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top + 1];
	stack->array[stack->top + 1] = tmp;
	return (1);
}
