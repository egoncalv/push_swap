/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:34:59 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/26 23:55:09 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_medium(t_stack **a, t_stack **b)
{
	int		midpoint;
	int		*chunk_sizes;
	int		i;

	chunk_sizes = malloc(sizeof(int) * 5);
	i = -1;
	while (stack_size(*a) > 2)
	{
		midpoint = find_midpoint(*a, stack_size(*a));
		chunk_sizes[++i] = send_smaller(a, b, midpoint, stack_size(*a), 1);
	}
	sort_small(a, b);
	i = 6;
	while (i--)
	{
		if (chunk_sizes[i])
		{
			if (i == 0)
				sort_chunk(a, b, chunk_sizes[i], 'b');
			else
				sort_chunk(a, b, chunk_sizes[i], 'b');
		}
	}
	free(chunk_sizes);
}

void	sort_chunk(t_stack **a, t_stack **b, int chunk_size, char id)
{
	int		midpoint;
	int		new_chunk_size;
	int		tmp;

	new_chunk_size = 0;
	while (chunk_size > 0)
	{
		if (chunk_size <= 2)
		{
			tmp = small_push(a, b, chunk_size, id);
			chunk_size = 0;
		}	
		else if (id == 'a')
		{
			midpoint = find_midpoint(*a, chunk_size);
			tmp = send_smaller(a, b, midpoint, chunk_size, 0);
		}
		else if (id == 'b')
		{
			midpoint = find_midpoint(*b, chunk_size);
			tmp = send_bigger(a, b, midpoint, chunk_size);
		}
		chunk_size -= tmp;
		new_chunk_size += tmp;
	}
	if (new_chunk_size > 0)
	{
		if (id == 'a' && !is_sorted(*b, new_chunk_size))
			sort_chunk(a, b, new_chunk_size, 'b');
		else if (id == 'b' && !is_sorted(*a, new_chunk_size))
			sort_chunk(a, b, new_chunk_size, 'a');
	}
}

int	small_push(t_stack **a, t_stack **b, int chunk_size, char id)
{
	if (id == 'a')
		return (small_sort_a(a, chunk_size));
	else if (id == 'b')
		return (small_push_b_to_a(a, b, chunk_size));
	return (chunk_size);
}

int	small_sort_a(t_stack **a, int chunk_size)
{
	if (chunk_size == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(*a);
		return (0);
	}
	if (chunk_size == 1)
		return (0);
	return (chunk_size);
}


int	small_push_b_to_a(t_stack **a, t_stack **b, int chunk_size)
{
	if (chunk_size == 2)
	{
		if ((*b)->content > (*b)->next->content)
		{
		 	pa(a, b);
			pa(a, b);
		}
		else
		{
			sb(*b);
			pa(a, b);
			pa(a, b);
		}
		return (2);
	}
	if (chunk_size == 1)
	{
		pa(a, b);
		return (0);
	}
	return (chunk_size);
}
