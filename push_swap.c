/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:40:05 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/06 15:52:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para remover o nó do topo da pilha e retornar o conteúdo do nó (pop off)
int    pop(t_stack *stack)
{
    t_node *temp;
    int content;

    if (!stack->top)
        return (0);
    temp = stack->top; // Guarda o endereço do topo da pilha
    content = stack->top->content; // Guarda o conteúdo do topo da pilha
    stack->top = stack->top->next; // O novo topo da pilha é o próximo nó
    free(temp); // Libera o nó antigo
    stack->size--; // Decrementa o tamanho da pilha
    return (content);
}

// Função para imprimir o conteúdo da pilha
void    print_stack(t_stack *stack) 
{
    t_node  *current;

    current = stack->top;
    while (current) // Enquanto houver nós na pilha
    {
        ft_printf("%d ", current->content); // Imprime o conteúdo do nó
        current = current->next;
    }
    ft_printf("\n");
}