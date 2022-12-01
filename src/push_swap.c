/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:38 by erickbarros       #+#    #+#             */
/*   Updated: 2022/12/01 17:08:28 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
		return (1);
	a = parse_stack(argv);
	b = 0;
	if (argc <= 6)
		sort_small(&a, &b, argc);
	//print_stacks(a, b);
	free_stacks(&a, &b);
	return (1);
}

t_stack	*parse_stack(char **argv)
{
	int			i;
	t_stack	*stack;
	
	stack = newstack(ft_atoi(argv[1]));
	i = 1;
	while (argv[++i]) //Check for duplicates, ensure all arguments are integers, and are not bigger than MAX_INT
	{ 
		if (is_duplicate(stack, ft_atoi(argv[i])) || !(is_nbr(argv[i])))
			exit_error();
		stack_add_back(&stack, newstack(ft_atoi(argv[i])));
	}
	return (stack);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("\n--------------STACK A--------------\n");
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
	ft_printf("\n--------------STACK B--------------\n");
	while (b)
	{
		ft_printf("%d\n", b->content);
		b = b->next;
	}
}
