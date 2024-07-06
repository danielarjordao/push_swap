/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:08:03 by marvin            #+#    #+#             */
/*   Updated: 2024/07/06 13:08:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para adicionar um novo nó no topo da pilha
void    push(t_stack *stack, int content)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->content = content;
    new_node->next = stack->top; // O próximo nó do novo nó é o antigo topo da pilha
    stack->top = new_node; // O novo nó é o novo topo da pilha
    stack->size++; // Incrementa o tamanho da pilha
}

// Função para mover o nó do topo da pilha a para o topo da pilha b
void    pa(t_stack *a, t_stack *b)
{
    push(a, pop(b));
    ft_printf("pa\n");
}

// Função para mover o nó do topo da pilha b para o topo da pilha a
void    pb(t_stack *a, t_stack *b)
{
    push(b, pop(a));
    ft_printf("pb\n");
}