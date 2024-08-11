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

#endif
