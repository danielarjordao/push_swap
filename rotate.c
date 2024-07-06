/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:24:54 by marvin            #+#    #+#             */
/*   Updated: 2024/07/06 15:24:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para mover o nó do topo da pilha para o final da pilha
void    rotate(t_stack *stack)
{
    t_node *temp;
    t_node *last_node;

    if (stack->size < 2)
        return ;
    temp = stack->top; // Guarda o endereço do topo da pilha
    last_node = find_last_node(stack); // Guarda o endereço do último nó da pilha
    stack->top = stack->top->next; // O novo topo da pilha é o segundo nó
    last_node->next = temp; // O próximo do último nó é o antigo topo
    temp->next = NULL; // O próximo do antigo topo é NULL
}

// Função para mover o nó do topo da pilha a para o final da pilha
void    ra(t_stack *a)
{
    rotate(a);
    ft_printf("ra\n");
}

// Função para mover o nó do topo da pilha b para o final da pilha
void    rb(t_stack *b)
{
    rotate(b);
    ft_printf("rb\n");
}

// Função para mover o nó do topo das pilhas a e b para o final das pilhas
void    rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}

