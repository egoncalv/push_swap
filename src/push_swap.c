/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:38 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/21 22:57:42 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	///t_stack	*b;
	int		i;

	if (argc < 2)
		return (1);
	a = malloc(sizeof(t_stack *));
	a->array = malloc(sizeof(int) * argc - 1);
	i = 0;
	while (argv[i + 1]) //Check for duplicates, ensure all arguments are integers, and are not bigger than MAX_INT
	{
		if (is_duplicate(a, ft_atoi(argv[i + 1])) || !(is_nbr(argv[i + 1])))
			exit_error();
		a->array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = -1;
	while (a->array[++i])
		ft_printf("%d\n", a->array[i]);
	return (1);
}
