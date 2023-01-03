/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:34:59 by egoncalv          #+#    #+#             */
/*   Updated: 2023/01/03 10:08:33 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_medium(t_stack **a, t_stack **b)
{
	t_mid	*mid;
	int		*chunk_sizes;
	int		i;

	mid = malloc(sizeof(t_mid *));
	chunk_sizes = malloc(sizeof(int) * 12);
	i = -1;
	while (stack_size(*a) > 2)
	{
		find_midpoint(*a, stack_size(*a), mid);
		chunk_sizes[++i] = send_smaller(a, b, mid, stack_size(*a), 1);
	}
	sort_small(a, b);
	while (i >= 0)
	{
		if (chunk_sizes[i])
			sort_chunk(a, b, chunk_sizes[i], 'b');
	 	i--;
	}
	free(chunk_sizes);
	free(mid);
}

void	sort_chunk(t_stack **a, t_stack **b, int chunk_size, char id)
{
	t_mid	*mid;
	int		new_chunk_size;
	int		tmp;

	new_chunk_size = 0;
	mid = malloc(sizeof(t_mid *));
	while (chunk_size)
	{
		if (id == 'a' && is_sorted(*a, chunk_size))
			break ;
		else if (id == 'b' && is_sorted_descending(*b, chunk_size))
		{
			while (chunk_size)
			{
				pa(a, b);
				new_chunk_size++;
				chunk_size--;
			}
			sort_chunk(a, b, new_chunk_size, 'a');
			return ;
		}
		else if (chunk_size <= 2)
		{
			tmp = small_push(a, b, chunk_size, id);
			if (id == 'a')
				break ;
		}
		else if (id == 'a')
		{
			find_midpoint(*a, chunk_size, mid);
			tmp = send_smaller(a, b, mid, chunk_size, 0);
		}
		else if (id == 'b')
		{
			find_midpoint(*b, chunk_size, mid);
			tmp = send_bigger(a, b, mid, chunk_size);
		}
		chunk_size -= tmp;
		new_chunk_size += tmp;
	}
	if (new_chunk_size)
	{
		if (id == 'a' && !is_sorted(*b, new_chunk_size))
			sort_chunk(a, b, new_chunk_size, 'b');
		else if (id == 'b' && !is_sorted(*a, new_chunk_size))
			sort_chunk(a, b, new_chunk_size, 'a');
	}
	free(mid);
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
		return (-2);
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
		return (1);
	}
	return (chunk_size);
}
