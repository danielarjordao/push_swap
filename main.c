/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:51:45 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/06 12:16:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stack *stack) {
    t_node  *current;

    current = stack->top;
    while (current) {
        ft_printf("%d ", current->content);
        current = current->next;
    }
    ft_printf("\n");
}

int main() {
    t_stack *a;

    // Caso de teste 1: Pilha desordenada
    a = init_stack();
    push(a, 5);
    push(a, 2);
    push(a, 8);
    push(a, 1);
    push(a, 4);

    printf("Caso de teste 1 - Pilha desordenada:\n");
    printf("Pilha 'a' antes da ordenacao:\n");
    print_stack(a);
    push_swap(a);
    printf("Pilha 'a' depois da ordenacao:\n");
    print_stack(a);
    free_stack(a);
    printf("\n");

    // Caso de teste 2: Pilha já ordenada
    a = init_stack();
    push(a, 5);
    push(a, 4);
    push(a, 3);
    push(a, 2);
    push(a, 1);

    printf("Caso de teste 2 - Pilha já ordenada:\n");
    printf("Pilha 'a' antes da ordenacao:\n");
    print_stack(a);
    push_swap(a);
    printf("Pilha 'a' depois da ordenacao:\n");
    print_stack(a);
    free_stack(a);
    printf("\n");

    // Caso de teste 3: Pilha com elementos repetidos
    a = init_stack();
    push(a, 3);
    push(a, 2);
    push(a, 3);
    push(a, 1);
    push(a, 2);

    printf("Caso de teste 3 - Pilha com elementos repetidos:\n");
    printf("Pilha 'a' antes da ordenacao:\n");
    print_stack(a);
    push_swap(a);
    printf("Pilha 'a' depois da ordenacao:\n");
    print_stack(a);
    free_stack(a);
    printf("\n");

    // Caso de teste 4: Pilha vazia
    a = init_stack();

    printf("Caso de teste 4 - Pilha vazia:\n");
    printf("Pilha 'a' antes da ordenacao:\n");
    print_stack(a);
    push_swap(a);
    printf("Pilha 'a' depois da ordenacao:\n");
    print_stack(a);
    free_stack(a);
    printf("\n");

    return 0;
}