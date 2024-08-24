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

// stack_utils.c
void	add_args(t_stack **stack, int content);
int		stack_size(t_stack *stack);
t_stack	*find_last(t_stack *stack);
void	update_positions(t_stack **stack);
void	free_stack(t_stack **stack);

#endif
