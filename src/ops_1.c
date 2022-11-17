/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:28 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/15 16:17:25 by erickbarros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swap the first 2 elements at the top of stack
void	ft_swap(t_list *lst)
{
	int	tmp;

	if (ft_lstsize(lst) < 2)
		return ;
	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}
