/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:34:59 by egoncalv          #+#    #+#             */
/*   Updated: 2022/12/01 23:49:38 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_medium(t_stack **a, t_stack **b)
{
	int	midpoint;

	midpoint = find_midpoint(*a);
	
}

int	find_midpoint(t_stack *stack)
{
	int	*array;
	int	size;
	int	i;
	int	midpoint;
	
	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		array[i] = stack->content;
		stack = stack->next;
		i++;
	}
	array = bubble_sort(array, size);
	midpoint = array[size / 2];
	free(array);
	return (midpoint);
}

int	*bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;
	
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}
