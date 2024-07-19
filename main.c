/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:51:45 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/14 17:54:16 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2) // Se não houver argumentos
        return (0); 
    a = init_stack(); // Inicializa a pilha A
    b = init_stack(); // Inicializa a pilha B
    if (!a || !b) // Se não for possível alocar memória para as pilhas
        return (0);
    if (!check_args(argc, argv, a)) // Se houver argumentos inválidos
    {
        ft_printf("Error\n");
        free_stack(a);
        free_stack(b);
        return (0);
    }
    // Testando as funções, apagar antes de enviar
    printf("Antes de ordenar:\n");
    t_node *node = a->top;
    while (node) {
        printf("Content: %d, Position: %d\n", node->content, node->position);
        node = node->next;
    }

    if (!is_sorted(a)) // Se a pilha A já estiver ordenada
        sort_stack(a, b); // Ordena a pilha A
    
    // Testando as funções, apagar antes de enviar
    ft_printf("\nDepois de ordenar a:\n");
    print_stack(a);
    ft_printf("\nDepois de ordenar b:\n");
    print_stack(b);

    free_stack(a); // Libera a memória da pilha A
    free_stack(b); // Libera a memória da pilha B
    return (0);
}