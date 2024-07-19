/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:40:05 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/14 14:48:27 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para encontrar o valor mínimo na pilha
int    find_min(t_stack *stack)
{
    int  min_value;
    t_node *next_node;
    
    next_node = stack->top->next; // Salva o endereço do currento da pilha
    min_value = stack->top->content; // Inicializa o valor mínimo com o primeiro valor da pilha
    while (next_node) // Enquanto houver nós na pilha
    {
        if (next_node->content < min_value) // Se o conteúdo do nó atual for menor que o valor mínimo
            min_value = next_node->content; // Atualiza o valor mínimo
        next_node = next_node->next; // Passa para o próximo nó
    }
    return (min_value); // Retorna o valor mínimo
}

// Função para encontrar o valor máximo na pilha
int    find_max(t_stack *stack)
{
    int  max_value;
    t_node *next_node;
    
    next_node = stack->top->next; // Salva o endereço do currento da pilha
    max_value = stack->top->content; // Inicializa o valor máximo com o primeiro valor da pilha
    while (next_node) // Enquanto houver nós na pilha
    {
        if (next_node->content > max_value) // Se o conteúdo do nó atual for maior que o valor máximo
            max_value = next_node->content; // Atualiza o valor máximo
        next_node = next_node->next; // Passa para o próximo nó
    }
    return (max_value); // Retorna o valor máximo
}

// Função para encontrar o ultimo nó na pilha
t_node    *find_last_node(t_stack *stack)
{
    t_node *last_node;
    
    last_node = stack->top; // Inicializa last_node para percorrer a pilha até o último nó
    while (last_node->next) // Percorre a pilha até o último nó
        last_node = last_node->next;
    return (last_node); // Retorna o último nó
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