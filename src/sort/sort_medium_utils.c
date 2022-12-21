/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:56:06 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/21 18:32:30 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	send_smaller(t_stack **a, t_stack **b, int midpoint, int size)
{
	t_stack	*a_tmp;
	int		j;
	int		chunk_size;

	j = 0;
	a_tmp = (*a);
	chunk_size = 0;
	while (size > 0)
	{
		if (a_tmp->content < midpoint)
		{
			check_and_rotate(a, j);
			pb(a, b);
			j = 0;
			a_tmp = *a;
			chunk_size++;
		}
		else
		{
			a_tmp = a_tmp->next;
			j++;
		}	
		size--;
	}
	return (chunk_size);
}

int	send_bigger(t_stack **a, t_stack **b, int midpoint, int size)
{
	t_stack	*b_tmp;
	int		chunk_size;
	int		j;

	j = 0;
	b_tmp = (*b);
	chunk_size = 0;
	while (size > 0)
	{
		if (b_tmp->content > midpoint)
		{
			rotate_push_rotate(a, b, j);
			b_tmp = *b;
			j = 0;
			chunk_size++;
		}
		else
		{
			b_tmp = b_tmp->next;
			j++;
		}
		size--;
	}
	return (chunk_size);
}

void	rotate_push_rotate(t_stack **a, t_stack **b, int i)
{
	int	j;

	j = i;	
	while (i--)
		rb(b);
	pa(a, b);
	while (j--)
		rrb(b);
}

void	check_and_rotate(t_stack **stack, int i)
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
