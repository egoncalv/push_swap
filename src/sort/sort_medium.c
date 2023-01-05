/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:34:59 by egoncalv          #+#    #+#             */
/*   Updated: 2023/01/05 10:31:24 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_medium(t_stack **a, t_stack **b)
{
	t_mid	*mid;
	int		chunk_sizes[25];
	int		i;

	if (is_sorted(*a, stack_size(*a)))
		return ;
	mid = malloc(sizeof(t_mid *));
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
			sort_chunk_b(a, b, chunk_sizes[i]);
	 	i--;
	}
	if (!(is_sorted(*a, stack_size(*a))))
	 	sort_medium(a, b);
	free(mid);
}

void	sort_chunk_a(t_stack **a, t_stack **b, int chunk_size)
{
	t_mid	*mid;
	int		new_chunk_size;
	int		tmp;

	new_chunk_size = 0;
	mid = malloc(sizeof(t_mid *));
	while (chunk_size)
	{
		if (is_sorted(*a, chunk_size))
			break ;
		else if (chunk_size == 2)
		{
			sa(*a);
			break ;
		}
		else
		{
			find_midpoint(*a, chunk_size, mid);
			tmp = send_smaller(a, b, mid, chunk_size, 0);
			chunk_size -= tmp;
			new_chunk_size += tmp;
		}
	}
	if (new_chunk_size)
		sort_chunk_b(a, b, new_chunk_size);
	free(mid);
}

void	sort_chunk_b(t_stack **a, t_stack **b, int chunk_size)
{
	t_mid	*mid;
	int		new_chunk_size;
	int		tmp;

	new_chunk_size = 0;
	mid = malloc(sizeof(t_mid *));
	while (chunk_size)
	{
		if (chunk_size <= 2)
			tmp = small_push_b_to_a(a, b, chunk_size);
		else
		{
			find_midpoint(*b, chunk_size, mid);
			tmp = send_bigger(a, b, mid, chunk_size);
		}
		chunk_size -= tmp;
		new_chunk_size += tmp;
		if (new_chunk_size)
		 		sort_chunk_a(a, b, new_chunk_size);
	}
	free(mid);
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
