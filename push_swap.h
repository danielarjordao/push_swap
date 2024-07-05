/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:49:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/05 18:54:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

// Estrutura de um nó da pilha
typedef struct s_node
{
    int content;
    struct s_node *next;
}               t_node;

// Estrutura da pilha
typedef struct s_stack
{
    t_node	*top;
    int		size;
}			t_stack;

// Funções de manipulação de pilha
void    push(t_stack *stack, int content);
int     pop(t_stack *stack);
void    swap(t_stack *stack);
void    rotate(t_stack *stack);
void    reverse_rotate(t_stack *stack);
t_stack    *init_stack(void);
void    free_stack(t_stack *stack);

// Funções de ordenação
int     find_min(t_stack *a);
void    move_min_to_b(t_stack *a, t_stack *b, int min_value);
void    move_greater_to_b(t_stack *a, t_stack *b, int min_value);

#endif