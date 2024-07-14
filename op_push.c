/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:08:03 by marvin            #+#    #+#             */
/*   Updated: 2024/07/14 15:23:16 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack *stack, int content) 
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->content = content;
    new_node->next = stack->current; // O próximo nó do novo nó é o antigo atual
    new_node->prev = NULL; // O novo nó é o novo atual, então não tem nó anterior
    if (stack->current) 
        stack->current->prev = new_node; // O antigo topo agora aponta para o novo nó como seu anterior
    stack->current = new_node; // O novo nó é o novo topo da pilha
    stack->size++; // Incrementa o tamanho da pilha
    // Atualiza as posições dos nós na pilha
    update_positions(stack);
}

// Função para mover o nó do currento da pilha a para o currento da pilha b
void    pa(t_stack *a, t_stack *b)
{
    push(a, pop(b));
    ft_printf("pa\n");
}

// Função para mover o nó do currento da pilha b para o currento da pilha a
void    pb(t_stack *a, t_stack *b)
{
    push(b, pop(a));
    ft_printf("pb\n");
}