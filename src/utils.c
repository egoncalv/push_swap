/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:25 by erickbarros       #+#    #+#             */
/*   Updated: 2023/01/05 10:13:39 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_nbr(char	*argv)
{
	int	i;

	i = -1;
	if (argv[0] == '-' || argv[0] == '+')
		i++;
	while (argv[++i])
		if (argv[i] < 48 || argv[i] > 57)
			return (0);
	return (1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	is_sorted(t_stack *stack, int size)
{
	while (size && stack)
	{
		if (stack->next)
		{
			if (stack->content > stack->next->content)
				return (0);
		}
		stack = stack->next;
		size--;
	}
	return (1);
}

int	is_sorted_descending(t_stack *stack, int size)
{
	while (size && stack)
	{
		if (stack->next)
		{
			if (stack->content < stack->next->content)
				return (0);
		}
		stack = stack->next;
		size--;
	}
	return (1);
}
