/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:24:20 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/01 15:43:26 by egoncalv         ###   ########.fr       */
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
	if (argc == 5 || argc == 6)
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
	int	pos;

	while (stack_size(*a) != 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		if (is_bigger(*a, (*b)->content))
		{
			pa(a, b);
			ra(a);
		}
		else
		{
			pos = get_correct_pos(*a, (*b)->content);
			if (pos > stack_size(*a) / 2)
				insert_bottom(a, b, pos);
			else
				insert_top(a, b, pos);
		}
	}
}

void	insert_top(t_stack **a, t_stack **b, int i)
{
	int	rra_n;

	rra_n = i;
	while (i > 0)
	{
		ra(a);
		i--;
	}
	pa(a, b);
	while (rra_n > 0)
	{
		rra(a);
		rra_n--;
	}
}

void	insert_bottom(t_stack **a, t_stack **b, int i)
{
	int	rra_n;

	rra_n = i - 1;
	while (rra_n > 0)
	{
		rra(a);
		rra_n--;
	}
	pa(a, b);
	while (i > 0)
	{
		ra(a);
		i--;
	}
}

int	get_correct_pos(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (n < stack->content)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int		is_bigger(t_stack *a, int n)
{
	while (a)
	{
		if (n < a->content)
			return (0);
		a = a->next;
	}
	return (1);
}
