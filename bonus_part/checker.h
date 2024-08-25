/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:02:17 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/24 16:02:17 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

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
int		check_args(int argc, char **argv, t_stack **a);
char	**split_args(char *argv, int *argc, int *split, int *i);
int		is_integer(char *str);
int		is_duplicate(t_stack *stack, int content);
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

// stack_utils.c
void	add_args(t_stack **stack, int content);
t_stack	*find_last(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);

#endif
