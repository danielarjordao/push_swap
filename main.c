/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:51:45 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/06 16:27:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
    // Inicializa duas pilhas
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    // Adiciona alguns elementos na stack_a
    push(stack_a, 5);
    push(stack_a, 10);
    push(stack_a, 20);
    push(stack_a, 1);
    push(stack_a, 15);

    ft_printf("Stack A inicial:\n");
    print_stack(stack_a);

    // Testa a função swap
    ft_printf("\nChamando a função sa (swap)...\n");
    sa(stack_a);
    ft_printf("\nStack A após sa (swap):\n");
    print_stack(stack_a);

    // Testa a função push
    ft_printf("\nChamando a função pb (push para B)...\n");
    pb(stack_a, stack_b);
    ft_printf("\nStack A após pb (push para B):\n");
    print_stack(stack_a);
    ft_printf("Stack B após pb (push para B):\n");
    print_stack(stack_b);

    // Testa a função rotate
    ft_printf("\nStack A inicial:\n");
    print_stack(stack_a);
    ft_printf("\nChamando a função ra (rotate)...\n");
    ra(stack_a);
    ft_printf("\nStack A após ra (rotate):\n");
    print_stack(stack_a);

    // Testa a função reverse rotate
    ft_printf("\nStack A inicial:\n");
    print_stack(stack_a);
    ft_printf("\nChamando a função rra (reverse rotate)...\n");
    rra(stack_a);
    ft_printf("\nStack A após rra (reverse rotate):\n");
    print_stack(stack_a);

    // Testa a função push de volta para stack_a
    ft_printf("\nChamando a função pa (push para A)...\n");
    pa(stack_a, stack_b);
    ft_printf("\nStack A após pa (push para A):\n");
    print_stack(stack_a);
    ft_printf("Stack B após pa (push para A):\n");
    print_stack(stack_b);

    // Testa a função sb
    push(stack_b, 30);
    push(stack_b, 40);
    ft_printf("\nStack B inicial:\n");
    print_stack(stack_b);
    ft_printf("\nChamando a função sb (swap)...\n");
    sb(stack_b);
    ft_printf("\nStack B após sb (swap):\n");
    print_stack(stack_b);

    // Testa a função ss
    ft_printf("\nStack A inicial:\n");
    print_stack(stack_a);
    ft_printf("Stack B inicial:\n");
    print_stack(stack_b);
    ft_printf("\nChamando a função ss (swap ambas as pilhas)...\n");
    ss(stack_a, stack_b);
    ft_printf("\nStack A após ss (swap ambas as pilhas):\n");
    print_stack(stack_a);
    ft_printf("Stack B após ss (swap ambas as pilhas):\n");
    print_stack(stack_b);

    // Testa a função rb
    ft_printf("\nStack B inicial:\n");
    print_stack(stack_b);
    ft_printf("\nChamando a função rb (rotate)...\n");
    rb(stack_b);
    ft_printf("\nStack B após rb (rotate):\n");
    print_stack(stack_b);

    // Testa a função rr
    ft_printf("\nStack A inicial:\n");
    print_stack(stack_a);
    ft_printf("Stack B inicial:\n");
    print_stack(stack_b);
    ft_printf("\nChamando a função rr (rotate ambas as pilhas)...\n");
    rr(stack_a, stack_b);
    ft_printf("\nStack A após rr (rotate ambas as pilhas):\n");
    print_stack(stack_a);
    ft_printf("Stack B após rr (rotate ambas as pilhas):\n");
    print_stack(stack_b);

    // Testa a função rrb
    ft_printf("\nStack B inicial:\n");
    print_stack(stack_b);
    ft_printf("\nChamando a função rrb (reverse rotate)...\n");
    rrb(stack_b);
    ft_printf("\nStack B após rrb (reverse rotate):\n");
    print_stack(stack_b);

    // Testa a função rrr
    ft_printf("\nStack A inicial:\n");
    print_stack(stack_a);
    ft_printf("Stack B inicial:\n");
    print_stack(stack_b);
    ft_printf("\nChamando a função rrr (reverse rotate ambas as pilhas)...\n");
    rrr(stack_a, stack_b);
    ft_printf("\nStack A após rrr (reverse rotate ambas as pilhas):\n");
    print_stack(stack_a);
    ft_printf("Stack B após rrr (reverse rotate ambas as pilhas):\n");
    print_stack(stack_b);

    // Testa funções de encontrar min e max
    int min = find_min(stack_a);
    int max = find_max(stack_a);
    ft_printf("\nMin de Stack A: %d\n", min);
    ft_printf("Max de Stack A: %d\n", max);

    // Testa função pop
    ft_printf("\nStack A inicial:\n");
    print_stack(stack_a);
    int popped_value = pop(stack_a);
    ft_printf("\nValor retirado de Stack A: %d\n", popped_value);
    ft_printf("Stack A após pop:\n");
    print_stack(stack_a);

    // Libera a memória das pilhas
    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}
