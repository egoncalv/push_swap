/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:24:20 by egoncalv          #+#    #+#             */
/*   Updated: 2022/11/30 01:34:41 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small(t_stack **a, t_stack **b, int argc)
{
	if (argc == 3)
	{
		if (is_sorted(*a))
			return ;
		else
		{
			sa(*a);
			return ;
		}
	}
	ft_printf("%p",*b);
}
