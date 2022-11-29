/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:22:21 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/29 18:19:41 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *a)
{
	if (swap(a) == 1)
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b) == 1)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (!swap(a))
		return ;
	if (!swap(b))
		return ;
	ft_printf("ss\n");
}

int	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return (0);
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	return (1);
}
