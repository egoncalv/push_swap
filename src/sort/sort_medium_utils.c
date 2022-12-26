/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:56:06 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/26 12:23:21 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// This function will go through (size) elements of
// stack A and send all numbers bigger than midpoint
// to the opposite stack B. If (last_chunk) is true, 
// we rotate without restoring stack, because we only
// have one chunk. Otherwise we always restore the stack
// after pushing, so we do not lose track of chunk.

int	send_smaller(t_stack **a, t_stack **b, int midpoint, int size, int last_chunk)
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
			if (last_chunk)
				rotate_push(a, b, j);
			else
				rotate_push_rotate(a, b, j, 'a');
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

// This function will go through (size) elements of
// stack B and send all numbers bigger than midpoint
// to the opposite stack A

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
			rotate_push_rotate(a, b, j, 'b');
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

// This function will rotate stack identified with (id) (i) times,
// push from one stack to another and then will restore stack as it
// was, so we don't lose track of chunks.

void	rotate_push_rotate(t_stack **a, t_stack **b, int i, int id)
{
	int	j;

	j = i;	
	while (i--)
	{
		if (id == 'b')
			rb(b);
		if (id == 'a')
			ra(a);
	}
	if (id == 'b')
		pa(a, b);
	if (id == 'a')
		pb(a, b);
	while (j--)
	{
		if (id == 'b')
			rrb(b);
		else if (id == 'a')
			rra(a);
	}
}

//This functions checks if the given index is closer to the start or end
// of the stack A, deciding if it will rotate or reverse rotate. It then 
//rotates and pushes the node to stack B

void	rotate_push(t_stack **a, t_stack **b, int i)
{
	if (i < (stack_size(*a) / 2))
	{
		while (i)
		{
			ra(a);
			i--;
		}
	}
	else
	{
		while (i < stack_size(*a))
		{
			rra(a);
			i++;
		}
	}
	pb(a, b);
}
