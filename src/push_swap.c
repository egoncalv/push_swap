/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:38 by erickbarros       #+#    #+#             */
/*   Updated: 2023/01/08 18:00:04 by egoncalv         ###   ########.fr       */
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
	if (stack_size(a) < 6)
		sort_small(&a, &b);
	else
		sort_medium(&a, &b);
	free_stack(a);
	free_stack(b);
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
		j = -1;
		while (arg[++j])
		{
			if (is_duplicate(stack, (int)ft_atoi(arg[j])) || !(is_nbr(arg[j]))
				|| ft_atoi(arg[j]) > INT_MAX || ft_atoi(arg[j]) < INT_MIN)
			{
				free_2d_array(arg);
				free_stack(stack);
				exit_error();
			}
			stack_add_back(&stack, newstack((int)ft_atoi(arg[j])));
		}
		free_2d_array(arg);
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free (stack);
		stack = tmp;
	}
}

void	free_2d_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free (array);
}
