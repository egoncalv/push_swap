/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:56:06 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/30 03:06:29 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// This function will go through (size) elements of
// stack A and send all numbers bigger than midpoint
// to the opposite stack B. If (last_chunk) is true, 
// we rotate without restoring stack, because we only
// have one chunk. Otherwise we always restore the stack
// after pushing, so we do not lose track of chunk.

int	send_smaller(t_stack **a, t_stack **b, t_mid *mid, int size, int last)
{
	t_stack	*a_tmp;
	int		i;
	int		j;
	int		chunk_size;

	i = 0;
	j = 0;
	a_tmp = (*a);
	chunk_size = 0;
	while (size > 0)
	{
		if (a_tmp->content < mid->midpoint)
		{
			j += i;
			rotate_i(a, i, 'a');
			while ((*a)->content < mid->midpoint)
			{
				chunk_size++;
				size--;
				pb(a, b);
			}
			a_tmp = *a;
			i = 0;
		}
		else if (stack_last(*a)->content < mid->midpoint)
		{
			chunk_size++;
			size--;
			rra(a);
			pb(a, b);
		}
		else
		{
			a_tmp = a_tmp->next;
			i++;
			size--;
		}
	}
	if (!last)
		reverse_rotate_i(a, j, 'a');
	return (chunk_size);
}

// This function will go through (size) elements of
// stack B and send all numbers bigger than midpoint
// to the opposite stack A

int	send_bigger(t_stack **a, t_stack **b, t_mid *mid, int size)
{
	t_stack	*b_tmp;
	int		chunk_size;
	int		i;
	int		j;
	
	i = 0;
	b_tmp = (*b);
	chunk_size = 0;

	j = 0;
	int last = 0;

	if (stack_size(*b) == size)
	 	last = 1;
	while (size > 0)
	{
		if (b_tmp->content > mid->midpoint)
		{
				j += i;
				rotate_i(b, i, 'b');
				while ((*b)->content > mid->midpoint)
				{
					chunk_size++;
					size--;
					pa(a, b);
				}
			b_tmp = *b;
			i = 0;
		}
		else
		{
			b_tmp = b_tmp->next;
			size--;
			i++;
		}
	}
	if (!last)
		reverse_rotate_i(b, j, 'b');
	return (chunk_size);
}

void	rotate_i(t_stack **stack, int i, char id)
{
	while (i)
	{
		if (id == 'a')
			ra(stack);
		else if (id == 'b')
			rb(stack);
		i--;
	}
}

void reverse_rotate_i(t_stack **stack, int i, char id)
{
	while (i)
	{
		if (id == 'a')
			rra(stack);
		else if (id == 'b')
			rrb(stack);
		i--;
	}
}
