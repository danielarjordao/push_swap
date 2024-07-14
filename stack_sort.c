/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:04:08 by marvin            #+#    #+#             */
/*   Updated: 2024/07/14 18:04:38 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_stack(t_stack *a, t_stack *b)
{
    if (a->size <= 3)
        simple_sort(a); // Ordena a pilha com 3 elementos
    else
        advanced_sort(a, b); // Ordena a pilha com mais de 5 elementos
}

// Função para verificar se a pilha está ordenada
int is_sorted(t_stack *stack)
{
    t_node  *current;

    current = stack->current; // Inicia a partir do currento da pilha
    while (current->next) // Enquanto houver nós na pilha
    {
        if (current->content > current->next->content) // Se o nó atual for maior que o próximo
            return (0); // A pilha não está ordenada
        current = current->next; // Avança para o próximo nó da pilha, pois a pilha está ordenada até agora
    }
    return (1); // Se o loop terminar, a pilha está ordenada
}

// Função para ordenar pilhas com 3 elementos
void    simple_sort(t_stack *a)
{
    if (a->size != 3) // Se a pilha não tiver 3 elementos
        return ;
    while (!is_sorted(a)) // Enquanto a pilha não estiver ordenada
    {
        if (a->current->content == find_min(a) && a->current->next->content == find_max(a))
        {
            sa(a); // Se o menor elemento estiver no currento, aplica a operação sa
            ra(a); // Em seguida, aplica a operação ra
        }
        else if (a->current->content == find_max(a) )
        {
            ra(a); // Se o maior elemento estiver no currento, aplica a operação ra
            if (a->current->content > a->current->next->content)
                sa(a); // Se o segundo maior elemento estiver abaixo do maior, aplica a operação sa
        }
        else if (a->current->next->content == find_max(a))
            rra(a); // Se o maior elemento estiver abaixo do currento, aplica a operação rra
        else
            sa(a); // Se o menor elemento estiver abaixo do currento, aplica a operação sa
    }
}
/*
// Função para ordenar pilhas com mais de 5 elementos
void    advanced_sort(t_stack *a, t_stack *b)
{
    while (!is_sorted(a)) // Enquanto a pilha não estiver ordenada
    {
        if (a->current->content == find_min(a))
            pb(a, b); // Se o menor elemento estiver no currento, aplica a operação pb
        else 
            ra(a); // Se o menor elemento estiver abaixo do currento, aplica a operação ra
    }
    while (b->size) // Enquanto a pilha B não estiver vazia
        pa(a, b); // Aplica a operação pa
}*/

int find_median(t_stack *stack) 
{
    int size;
    t_stack  *temp;

    temp = stack;
    size = stack->size / 2;
    while (size)
    {
        if (temp->current->content == find_min(temp))
        {
            pop(temp);
            size--;
        }
        else
            rotate(temp);
    }
    return (find_min(temp));
}

void advanced_sort(t_stack *a, t_stack *b) {
    int median;
    int size = a->size;
    int original_size = size;

    median = find_median(a);
    printf("Pivot: %d\n", median); // Debug print
    for (int i = 0; i < original_size; i++) 
    {
        if (a->current->content > median) 
        {
            printf("pb: %d\n", a->current->content); // Debug print
            pb(a, b);
        } 
        else 
        {
            printf("ra: %d\n", a->current->content); // Debug print
            ra(a);
        }
    }

    // Move todos os elementos restantes de a para b
    while (a->size > 0) 
    {
        printf("pb (remaining): %d\n", a->current->content); // Debug print
        pb(a, b);
    }
}
