/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:27:21 by marvin            #+#    #+#             */
/*   Updated: 2024/07/14 15:37:33 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack *stack) 
{
    t_node *previous_node;
    t_node *last_node;

    last_node = find_last_node(stack);
    previous_node = last_node->prev;  
    if (previous_node)
        previous_node->next = NULL; // O próximo do penúltimo nó é NULL, pois ele será o ultimo nó
    last_node->next = stack->current; // O próximo do antigo último nó é o antigo topo
    stack->current->prev = last_node;
    last_node->prev = NULL;
    stack->current = last_node; // O novo topo da pilha é o antigo último nó
    // Atualiza as posições dos nós na pilha
    update_positions(stack);
}

// Função para mover o último nó da pilha a para o currento da pilha
void    rra(t_stack *a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}

// Função para mover o último nó da pilha b para o currento da pilha
void    rrb(t_stack *b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}

// Função para mover o último nó das pilhas a e b para o currento das pilhas
void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}