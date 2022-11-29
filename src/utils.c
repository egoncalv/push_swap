/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:17:25 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/29 15:16:36 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_duplicate(t_stack *lst, int num)
{
	while (lst)
	{
		if (lst->content == num)
			return (1);
		lst = lst->next;
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
