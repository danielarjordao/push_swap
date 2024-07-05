/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:20:48 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/05 11:57:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para adicionar um novo nó no topo da pilha
void    push(t_stack *stack, int content)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->content = content;
    new_node->next = stack->top; // O próximo nó do novo nó é o antigo topo da pilha
    stack->top = new_node; // O novo nó é o novo topo da pilha
    stack->size++; // Incrementa o tamanho da pilha
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
// Função para trocar o conteúdo dos dois primeiros nós da pilha
void    swap(t_stack *stack)
{
    t_node *top_node;
    t_node *second_node;

    if (stack->size < 2)
        return ;
    top_node = stack->top; // Guarda o endereço do topo da pilha
    second_node = top_node->next; // Guarda o endereço do segundo nó da pilha
    top_node->next = second_node->next; // O próximo do antigo topo passa a ser o terceiro nó (se houver)
    second_node->next = top_node; // O próximo do segundo nó passa a ser o antigo topo
    stack->top = second_node; // O novo topo da pilha é o segundo nó
}
// Função para mover o nó do topo da pilha para o final da pilha
void    rotate(t_stack *stack)
{
    t_node *temp;
    t_node *last_node;

    if (stack->size < 2)
        return ;
    temp = stack->top; // Guarda o endereço do topo da pilha
    last_node = stack->top; // Inicializa last_node para percorrer a pilha até o último nó
    while (last_node->next) // Percorre a pilha até o último nó
        last_node = last_node->next;
    stack->top = stack->top->next; // O novo topo da pilha é o segundo nó
    last_node->next = temp; // O próximo do último nó é o antigo topo
    temp->next = NULL; // O próximo do antigo topo é NULL
}
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
    