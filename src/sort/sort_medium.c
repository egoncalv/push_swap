/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:34:59 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/10 21:56:28 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_medium(t_stack **a, t_stack **b)
{
	int		midpoint;

	midpoint = find_midpoint(*a);
	send_less(a, b, midpoint, stack_size(*a));
}

void	send_less(t_stack **a, t_stack **b, int midpoint, int size)
{
	t_stack	*a_tmp;
	int		i;
	int		j;
	

	i = 0;
	j = 0;
	a_tmp = (*a);
	while (i < size)
	{
		if (a_tmp->content < midpoint)
		{
			reverse_i(a, j);
			pb(a,b);
			a_tmp = *a;
		}
		else
		{
			a_tmp = a_tmp->next;
			j++;
		}	
		i++;
	}
}

void	reverse_i(t_stack **stack, int i)
{
	if (i < (stack_size(*stack) / 2))
	{
		while (i)
		{
			ra(stack);
			i--;
		}
	}
	else
	{
		while (i < stack_size(*stack))
		{
			rra(stack);
			i++;
		}
	}
}
