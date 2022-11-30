/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:24:20 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/30 17:48:49 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small(t_stack **a, t_stack **b, int argc)
{
	if (is_sorted(*a))
		return ;
	if (argc == 3)
	{
		sa(*a);
		return ;
	}
	if (argc == 4)
		sort_three(a);
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
