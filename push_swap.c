/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:40:05 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/05 19:24:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para encontrar o valor mínimo na pilha
int    find_min(t_stack *a)
{
    int  min_value;
    t_node *next_node;
    
    next_node = a->top->next; // Salva o endereço do topo da pilha
    min_value = a->top->content; // Inicializa o valor mínimo com o primeiro valor da pilha
    while (next_node) // Enquanto houver nós na pilha
    {
        if (next_node->content < min_value) // Se o conteúdo do nó atual for menor que o valor mínimo
            min_value = next_node->content; // Atualiza o valor mínimo
        next_node = next_node->next; // Passa para o próximo nó
    }
    return (min_value); // Retorna o valor mínimo
}

// Função para mover o mínimo valor da pilha a para a pilha b
void    move_min_to_b(t_stack *a, t_stack *b, int min_value)
{
    int  i;
    int  size;
    
    size = a->size; // Salva o tamanho da pilha a
    i = 0;
    while (i < size) // Enquanto houver nós na pilha a
    {
        if (a->top->content == min_value) // Se o conteúdo do nó atual for igual ao valor mínimo
        {
            push(b, pop(a)); // Move o nó da pilha a para a pilha b
            ft_printf("pb\n");
            i++;
        }
        else
        {
            rotate(a); // Move o nó do topo da pilha a para o final da pilha
            ft_printf("ra\n");
        }
        i++;
    }
}

