/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:25:41 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 14:25:41 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	int				sort_value;
	int				current_position;
	int				goal_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}			t_stack;

// check_args.c
int		get_args(int argc, char **argv, t_stack **a);
int		is_integer(char *str);
int		is_duplicate(t_stack *stack, int content);
void	add_args(t_stack **stack, int content);
void	free_argv(char **argv);

// swap.c
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// push.c
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotate.c
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate.c
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// stack_sort.c
void	sort_stack(t_stack **a, t_stack **b);
void	simple_sort(t_stack **a);
void	advanced_sort(t_stack **a, t_stack **b);

// stack_manipulation.c
void	keep_three(t_stack **a, t_stack **b);
void	add_goal_positions(t_stack **a, t_stack **b);
void	calculate_cost(t_stack **a, t_stack **b);
void	move_cheapest(t_stack **a, t_stack **b);
void	sort_to_finish(t_stack **a);

// stack_sort_utils.c
void	add_sort_values(t_stack **stack);
int		find_goal_position(t_stack **stack, int b_sort);
int		nbr_pos(int nbr);
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b);

// stack_utils.c
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*find_last(t_stack *stack);
void	update_positions(t_stack **stack);
void	free_stack(t_stack **stack);

#endif
