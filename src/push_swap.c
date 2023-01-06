/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:38 by erickbarros       #+#    #+#             */
/*   Updated: 2023/01/06 08:49:12 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = parse_stack(argv);
	b = 0;
	if (argc <= 6)
		sort_small(&a, &b);
	else
		sort_medium(&a, &b);
	free_stacks(&a, &b);
	return (1);
}

t_stack	*parse_stack(char **argv)
{
	int			i;
	int			j;
	char		**arg;
	t_stack		*stack;

	i = 0;
	stack = 0;
	while (argv[++i])
	{
		arg = ft_split(argv[i], ' ');
		j = 0;
		while (arg[j])
		{
			if (is_duplicate(stack, ft_atoi(arg[j])) || !(is_nbr(arg[j])))
				exit_error();
			stack_add_back(&stack, newstack(ft_atoi(arg[j])));
			j++;
		}
		free(arg);
	}
	return (stack);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

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
