/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:22:07 by marvin            #+#    #+#             */
/*   Updated: 2024/07/06 15:22:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para trocar o conteúdo dos dois primeiros nós da pilha
void    swap(t_stack *stack)
{
    t_node *top_node;
    t_node *second_node;

    if (stack->size < 2)
        return ;
    top_node = stack->top; // Guarda o endereço do topo da pilha
    second_node = top_node->next; // Guarda o endereço do segundo nó da pilha
    top_node->next = second_node->next; // O próximo do antigo topo passa a ser o terceiro nó (se houver)
    second_node->next = top_node; // O próximo do segundo nó passa a ser o antigo topo
    stack->top = second_node; // O novo topo da pilha é o segundo nó
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