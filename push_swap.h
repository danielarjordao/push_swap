/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:49:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/11 17:18:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

// Funções das operações básicas
void    swap(t_stack *stack);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    push(t_stack *stack, int content);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    rotate(t_stack *stack);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    reverse_rotate(t_stack *stack);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

// Funções de manipulação de pilha
t_stack    *init_stack(void);
void    free_stack(t_stack *stack);
int     find_min(t_stack *stack);
int     find_max(t_stack *stack);
t_node    *find_last_node(t_stack *stack);

// Funções utilitárias
int     pop(t_stack *stack);
void    print_stack(t_stack *stack);

// Funções de ordenação
void    sort_stack(t_stack *a);
int     is_sorted(t_stack *stack);
void    simple_sort(t_stack *a);

// Funções de verificação de argumentos
int     is_number(char *str);
int     is_integer(char *str);
int     is_duplicate(t_stack *stack, int num);
int     countwords(char **words);
int     check_args(int argc, char **argv, t_stack *stack);

#endif