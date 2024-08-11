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

// Funções para receber e validar argumentos
int		get_args(int argc, char **argv, t_stack **a);
int		is_integer(char *str);
int		is_duplicate(t_stack *stack, int content);
void	add_args(t_stack **stack, int content);

// Funções para retirar informações da stack
t_stack	*find_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);

// Funções para manipular a stack
void    add_sort_value(t_stack **stack);
void	save_three(t_stack **a, t_stack **b);

// Funções para ordenar a stack
void	simple_sort(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);

// Operações de stack
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);


#endif
