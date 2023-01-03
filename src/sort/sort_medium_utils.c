/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:56:06 by egoncalv          #+#    #+#             */
/*   Updated: 2023/01/03 10:11:14 by egoncalv         ###   ########.fr       */
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
	int		j;
	int		chunk_size;

	j = 0;
	chunk_size = 0;
	while (chunk_size < mid->qty_smaller && size)
	{
		if ((*a)->content < mid->midpoint)
		{
			pb(a, b);
			if (stack_size(*b) >= 2 && (*b)->content < (*b)->next->content)
				sb(*b);
			chunk_size++;
		}
		else if (stack_last(*a)->content < mid->midpoint)
			rra(a);
		else
		{
			ra(a);
			j++;
		}
		size--;
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
	int		chunk_size;
	int		j;
	
	chunk_size = 0;
	j = 0;
	while (chunk_size < mid->qty_bigger && size)
	{
		if ((*b)->content > mid->midpoint)
		{
			pa(a, b);
			if ((*a)->content > (*a)->next->content)
			 	sa(*a);
			chunk_size++;
		}
		else
		{
			rb(b);
			j++;
		}
		size--;
	}
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
