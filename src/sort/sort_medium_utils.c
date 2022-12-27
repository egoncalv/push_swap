/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:56:06 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 00:09:11 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// This function will go through (size) elements of
// stack A and send all numbers bigger than midpoint
// to the opposite stack B. If (last_chunk) is true, 
// we rotate without restoring stack, because we only
// have one chunk. Otherwise we always restore the stack
// after pushing, so we do not lose track of chunk.

int	send_smaller(t_stack **a, t_stack **b, int midpoint, int size, int last)
{
	t_stack	*a_tmp;
	int		i;
	int		tmp;
	int		chunk_size;

	i = 0;
	a_tmp = (*a);
	chunk_size = 0;
	while (size > 0)
	{
		if (a_tmp->content < midpoint)
		{
			if (last)
				tmp = rotate_push(a, b, i, 'a');
			else
				tmp = rotate_push_rotate(a, b, midpoint, i, 'a');
			chunk_size += tmp;
			size -= tmp;
			i = 0;
			a_tmp = *a;
		}
		else
		{
			a_tmp = a_tmp->next;
			i++;
			size--;
		}
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
	int		tmp;
	int		i;

	i = 0;
	b_tmp = (*b);
	chunk_size = 0;

	int	last_chunk = 0;
	if (size == stack_size(*b))
		last_chunk = 1;
	while (size > 0)
	{
		if (b_tmp->content > midpoint)
		{
			if (last_chunk)
				tmp = rotate_push(b, a, i, 'b');
			else
				tmp = rotate_push_rotate(b, a, midpoint, i, 'b');
			chunk_size += tmp;
			size -= tmp;
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
	return (chunk_size);
}

int	rotate_push_rotate(t_stack **from, t_stack **to, int midpoint, int i, char id)
{
	int	chunk_size;

	chunk_size = 0;
	rotate_i(from, i, id);
	if (id == 'a')
	{
		while ((*from)->content < midpoint)
		{
			pb(from, to);
			chunk_size++;
		}
	}
	else if (id == 'b')
	{
		while ((*from)->content > midpoint)
		{
			pa(to, from);
			chunk_size++;
		}
	}
	reverse_rotate_i(from, i, id);
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

//This functions checks if the given index is closer to the start or end
// of the stack A, deciding if it will rotate or reverse rotate. It then 
//rotates and pushes the node to stack B

int	rotate_push(t_stack **from, t_stack **to, int i, char id)
{
	int size;

	size = stack_size(*(from));
	if (i < (size / 2))
		rotate_i(from, i, id);
	else
		reverse_rotate_i(from, size - i, id);
	if (id == 'a')
		pb(from, to);
	else if (id == 'b')
		pa(to, from);
	return (1);
}
