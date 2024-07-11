/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:04:08 by marvin            #+#    #+#             */
/*   Updated: 2024/07/11 10:04:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_stack(t_stack *a)
{
    if (a->size <= 3)
        simple_sort(a); // Ordena a pilha com 3 elementos
}

// Função para verificar se a pilha está ordenada
int is_sorted(t_stack *stack)
{
    t_node  *current;

    current = stack->top; // Inicia a partir do topo da pilha
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
        if (a->top->content == find_min(a))
        {
            sa(a); // Se o menor elemento estiver no topo, aplica a operação sa
            ra(a); // Em seguida, aplica a operação ra
        }
        else if (a->top->content == find_max(a) )
        {
            ra(a); // Se o maior elemento estiver no topo, aplica a operação ra
            if (a->top->content > a->top->next->content)
                sa(a); // Se o segundo maior elemento estiver abaixo do maior, aplica a operação sa
        }
        else if (a->top->next->content == find_max(a))
            rra(a); // Se o maior elemento estiver abaixo do topo, aplica a operação rra
        else
            sa(a); // Se o menor elemento estiver abaixo do topo, aplica a operação sa
    }
}

