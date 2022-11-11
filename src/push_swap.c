/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:38 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/11 17:20:22 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;
	//t_list	*tmp;
	int		i;

	if (argc < 2)
		return (1);
	stack_a = ft_lstnew(ft_atoi(argv[1]));
	i = 1;
	while (argv[++i]) //Check for duplicates, ensure all arguments are integers, and are not bigger than MAX_INT
	{
		if (is_duplicate(stack_a, ft_atoi(argv[i])) || !(is_nbr(argv[i])))
			exit_error();
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
	}
	return (1);
}
