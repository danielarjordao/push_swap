/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:09:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/14 15:24:51 by dramos-j         ###   ########.fr       */
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
    stack->current = NULL; // Inicianiza com o no atual
    stack->size = 0; // Inicializa o tamanho da pilha como 0
    return (stack);
}
// Função para liberar a pilha
void    free_stack(t_stack *stack)
{
    t_node *temp;

    while (stack->current) // Enquanto houver nós na pilha
    {
        temp = stack->current->next; // Salva o próximo nó
        free(stack->current); // Libera o nó antigo
        stack->current = temp; // O novo currento da pilha é o próximo nó
    }
    free(stack); // Libera a pilha
}

// Função para remover o nó do currento da pilha e retornar o conteúdo do nó (pop off)
int    pop(t_stack *stack)
{
    t_node *temp;
    int content;

    if (!stack->current)
        return (0);
    temp = stack->current; // Guarda o endereço do currento da pilha
    content = stack->current->content; // Guarda o conteúdo do currento da pilha
    stack->current = stack->current->next; // O novo currento da pilha é o próximo nó
    free(temp); // Libera o nó antigo
    stack->size--; // Decrementa o tamanho da pilha
    return (content);
}

void update_positions(t_stack *stack) 
{
    t_node *node;
    int pos;
    
    node = stack->current;
    pos = 1;
    while (node) 
    {
        node->position = pos++;
        node = node->next;
    }
}
