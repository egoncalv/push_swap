/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:27:35 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/28 00:01:24 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
		Take the first element at the top of stack "from"
		and put it at the top of stack "to".
		Note that my operations are done using pointer references,
		so it impacts directly in the stack
*/
void	pa(t_stack **a, t_stack **b)
{
	if (push(b, a) == 1)
		ft_printf("pa\n");
	return ;
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b) == 1)
		ft_printf("pb\n");
	return ;
}

int	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!(*from))
		return (0);
	if (!(*to))
	{
		(*to) = newstack((*from)->content);
		tmp = *from;
		*from = (*from)->next;
		free(tmp);
	}
	else
	{
		(*to)->prev = newstack((*from)->content);
		(*to)->prev->next = (*to);
		*to = (*to)->prev;
		tmp = *from;
		*from = (*from)->next;
		free(tmp);
	}
	return (1);
}
