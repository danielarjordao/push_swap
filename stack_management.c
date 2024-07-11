/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:09:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/11 19:04:45 by marvin           ###   ########.fr       */
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
