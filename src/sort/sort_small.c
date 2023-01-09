/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:24:20 by egoncalv          #+#    #+#             */
/*   Updated: 2023/01/09 23:44:32 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a, size))
		return ;
	else if (size == 2)
		sa(*a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five(a, b);
}

void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->content;
	middle = (*a)->next->content;
	bottom = (*a)->next->next->content;
	if (top < middle && top < bottom && middle > bottom)
	{
		sa(*a);
		ra(a);
	}
	if (top > middle && top < bottom && middle < bottom)
		sa(*a);
	if (top < middle && top > bottom && middle > bottom)
		rra(a);
	if (top > middle && top > bottom && middle > bottom)
	{
		sa(*a);
		rra(a);
	}
	if (top > middle && top > bottom && middle < bottom)
		ra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_size(*a) != 3)
		send_smallest(a, b);
	if ((*b)->content < (*b)->next->content)
		sb(*b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
