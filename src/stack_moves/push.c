/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:27:35 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/24 10:48:04 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (push(b, a) == 1)
		ft_printf("pa\n");
	return ;
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(a, b) == 1)
		ft_printf("pb\n");
	return ;
}

int	push(t_stack *from, t_stack *to)
{
	int	tmp;
	int	i;

	if (stack_size(from) < 1)
		return (0);
	i = 0;
	while (to->array[i])
	{
		tmp = to->array[i];
		i++;
		to->array[i] = tmp;
	}
	to->array[0] = from->array[from->top];
	from->top++;
	return (1);
}
