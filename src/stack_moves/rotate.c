/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:50:32 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/29 21:25:24 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*  
	Shift up all elements of stack by 1.
	The first element becomes the last one.
*/

void	ra(t_stack **a)
{
	if (rotate(a) == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (rotate(b) == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if (!rotate(a))
	{
		if (!rotate(b))
			return ;
	}
	ft_printf("rr\n");
}

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (!(*stack))
		return (0);
	last = stack_last(*stack);
	head = (*stack)->next;
	last->next = *stack;
	(*stack)->prev = last;
	(*stack)->next = NULL;
	*stack = head;
	return (1);
}
