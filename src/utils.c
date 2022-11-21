/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:25 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/21 22:57:52 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_duplicate(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->array[i])
	{
		if (num == stack->array[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_nbr(char	*argv)
{
	int	i;

	i = -1;
	if (argv[0] == '-')
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
