/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:53:29 by erickbarros       #+#    #+#             */
/*   Updated: 2023/01/08 15:35:14 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	struct s_stack	*next;
}		t_stack;

typedef struct s_mid
{
	int	midpoint;
	int	qty_bigger;
	int	qty_smaller;
}		t_mid;

void	print_stacks(t_stack *a, t_stack *b);
t_stack	*parse_stack(char **argv);
void	free_stack(t_stack *stack);
void	free_2d_array(char **array);

t_stack	*newstack(int content);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);

int		is_duplicate(t_stack *stack, int num);
int		is_nbr(char	*argv);

int		is_sorted(t_stack *stack, int size);
int		is_sorted_descending(t_stack *stack, int size);

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

void	sort_small(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);

int		get_correct_pos(t_stack *stack, int n);
int		is_bigger(t_stack *a, int n);
void	insert_top(t_stack **a, t_stack **b, int i);
void	insert_bottom(t_stack **a, t_stack **b, int i);

void	sort_medium(t_stack **a, t_stack **b);

void	sort_chunk_a(t_stack **a, t_stack **b, int chunk_size);
void	sort_chunk_b(t_stack **a, t_stack **b, int chunk_size);

int		small_push_b_to_a(t_stack **a, t_stack **b, int chunk_size);
int		send_smaller(t_stack **a, t_stack **b, t_mid *mid, int last);
int		send_bigger(t_stack **a, t_stack **b, t_mid *mid, int last);

void	reverse_rotate_i(t_stack **stack, int i, char id);
int		is_last(t_stack *stack, int size);

int		find_midpoint(t_stack *stack, int size, t_mid *mid);
int		*bubble_sort(int *array, int size);

#endif
