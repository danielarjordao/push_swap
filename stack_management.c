/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:09:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/06 15:40:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para inicializar a pilha
t_stack    *init_stack(void)
{
    t_stack *stack; // Cria um ponteiro para a pilha

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL; // Inicializa o topo da pilha como nulo
    stack->size = 0; // Inicializa o tamanho da pilha como 0
    return (stack);
}
// Função para liberar a pilha
void    free_stack(t_stack *stack)
{
    t_node *temp;

    while (stack->top) // Enquanto houver nós na pilha
    {
        temp = stack->top->next; // Salva o próximo nó
        free(stack->top); // Libera o nó antigo
        stack->top = temp; // O novo topo da pilha é o próximo nó
    }
    free(stack); // Libera a pilha
}

// Função para encontrar o valor mínimo na pilha
int    find_min(t_stack *stack)
{
    int  min_value;
    t_node *next_node;
    
    next_node = stack->top->next; // Salva o endereço do topo da pilha
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
    
    next_node = stack->top->next; // Salva o endereço do topo da pilha
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
