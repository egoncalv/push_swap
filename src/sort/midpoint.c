/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:52:51 by egoncalv          #+#    #+#             */
/*   Updated: 2023/01/06 08:51:14 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_midpoint(t_stack *stack, int size, t_mid *mid)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	mid->qty_bigger = 0;
	mid->qty_smaller = 0;
	i = 0;
	while (i < size)
	{
		array[i] = stack->content;
		stack = stack->next;
		i++;
	}
	array = bubble_sort(array, size);
	mid->midpoint = array[size / 2];
	i = -1;
	while (++i < size)
	{
		if (array[i] < mid->midpoint)
			mid->qty_smaller++;
		else if (array[i] > mid->midpoint)
			mid->qty_bigger++;
	}
	free(array);
	return (0);
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
