/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:22:07 by marvin            #+#    #+#             */
/*   Updated: 2024/07/14 15:45:23 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para trocar o conteúdo dos dois primeiros nós da pilha
void    swap(t_stack *stack)
{
    t_node *current_node;
    t_node *second_node;

    if (stack->size < 2)
        return ;
    current_node = stack->top; // Guarda o endereço do currento da pilha
    second_node = current_node->next; // Guarda o endereço do segundo nó da pilha
    current_node->next = second_node->next; // O próximo do antigo currento passa a ser o terceiro nó (se houver)
    second_node->next = current_node; // O próximo do segundo nó passa a ser o antigo currento
    stack->top = second_node; // O novo currento da pilha é o segundo nó
    update_positions(stack);
}

// Função para trocar o conteúdo dos dois primeiros nós da pilha a
void    sa(t_stack *a)
{
    swap(a);
    ft_printf("sa\n");
}

// Função para trocar o conteúdo dos dois primeiros nós da pilha b
void    sb(t_stack *b)
{
    swap(b);
    ft_printf("sb\n");
}

// Função para trocar o conteúdo dos dois primeiros nós das pilhas a e b
void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}