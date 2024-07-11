/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:27:21 by marvin            #+#    #+#             */
/*   Updated: 2024/07/06 15:27:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para mover o último nó da pilha para o topo da pilha
void    reverse_rotate(t_stack *stack)
{
    t_node *previous_node;
    t_node *last_node;
    
    if (stack->size < 2) // Se a pilha tiver menos de 2 nós, retorna
        return ;
    previous_node = NULL; // Inicializa previous_node para guardar o penúltimo nó
    last_node = stack->top; // Inicializa last_node para percorrer a pilha até o penúltimo nó
    while (last_node->next) // Percorre a pilha até o penúltimo nó
    {
        previous_node = last_node; // Guarda o endereço do penúltimo nó
        last_node = last_node->next; // O último nó passa a ser o próximo do último nó
    }
    previous_node->next = NULL; // O próximo do penúltimo nó é NULL, pois ele será o ultimo nó
    last_node->next = stack->top; // O próximo do antigo último nó é o antigo topo
    stack->top = last_node; // O novo topo da pilha é o antigo último nó
}

// Função para mover o último nó da pilha a para o topo da pilha
void    rra(t_stack *a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}

// Função para mover o último nó da pilha b para o topo da pilha
void    rrb(t_stack *b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}

// Função para mover o último nó das pilhas a e b para o topo das pilhas
void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}