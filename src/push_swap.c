/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:38 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/29 15:17:40 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	//t_stack	*b;
	int		i;

	if (argc < 2)
		return (1);
	a = newstack(ft_atoi(argv[1]));
	i = 1;
	while (argv[++i]) //Check for duplicates, ensure all arguments are integers, and are not bigger than MAX_INT
	{
		if (is_duplicate(a, ft_atoi(argv[i])) || !(is_nbr(argv[i])))
			exit_error();
		stack_add_back(&a, newstack(ft_atoi(argv[i])));
	}

	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
	return (1);
}
