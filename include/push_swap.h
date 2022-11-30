/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:29 by erickbarros       #+#    #+#             */
/*   Updated: 2022/11/30 17:49:13 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"

typedef struct s_stack
{
	struct s_stack *prev;
	int				content;
	struct s_stack *next;
}		t_stack;

void	print_stacks(t_stack *a, t_stack *b);
t_stack	*parse_stack(char **argv);

t_stack	*newstack(int content);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);

int		is_duplicate(t_stack *stack, int num);
int		is_nbr(char	*argv);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);

void	exit_error(void);

int		swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

int		push(t_stack **from, t_stack **to);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

int		rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

int		reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_small(t_stack **a, t_stack **b, int argc);
void	sort_three(t_stack **a);



#endif
