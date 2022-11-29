/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:20:42 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/29 21:34:32 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Shift down all elements of stack by 1.
	The last element becomes the first one.
*/

void	rra(t_stack **a)
{
	if (reverse_rotate(a) == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (reverse_rotate(b) == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if (!reverse_rotate(a))
	{
		if (!reverse_rotate(b))
			return ;
	}
		ft_printf("rrr\n");
}

int	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack))
		return (0);
	last = stack_last(*stack);
	last->prev->next = 0;
	(*stack)->prev = last;
	last->next = *stack;
	last->prev = 0;
	*stack = last;
	return (1);
}
