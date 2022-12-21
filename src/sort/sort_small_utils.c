/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:54:51 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/10 23:58:20 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	int	ra_n;

	rra_n = stack_size(*a) - i;
	if (stack_size(*a) == 4)
		ra_n = i - 1;
	else
		ra_n = i;
	while (rra_n > 0)
	{
		rra(a);
		rra_n--;
	}
	pa(a, b);
	while (ra_n > 0)
	{
		ra(a);
		ra_n--;
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
