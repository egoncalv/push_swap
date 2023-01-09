/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:54:51 by egoncalv          #+#    #+#             */
/*   Updated: 2023/01/09 23:55:24 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	send_smallest(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		index;

	tmp = *a;
	min = (*a)->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	index = find_index(*a, min);
	while ((*a)->content != min)
	{
		if (index <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}

int	find_index(t_stack *stack, int n)
{
	int	index;

	index = 0;
	while (stack->content != n)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}
