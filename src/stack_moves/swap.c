/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:22:21 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/23 18:44:33 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack_size(stack) < 2)
		return ;
	tmp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top + 1];
	stack->array[stack->top + 1] = tmp;
}
