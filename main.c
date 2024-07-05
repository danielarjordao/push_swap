/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:51:45 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/05 19:15:19 by marvin           ###   ########.fr       */
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
/*
int main(void) {
    t_stack *a;
    t_stack *b;

    a = init_stack();
    b = init_stack();

    push(a, 3);
    push(a, 2);
    push(a, 1);

    ft_printf("Initial stack a: ");
    print_stack(a);

    swap(a);
    ft_printf("After swap: ");
    print_stack(a);

    rotate(a);
    ft_printf("After rotate: ");
    print_stack(a);

    reverse_rotate(a);
    ft_printf("After reverse rotate: ");
    print_stack(a);

    push(b, pop(a));
    ft_printf("After push from a to b: ");
    ft_printf("Stack a: ");
    print_stack(a);
    ft_printf("Stack b: ");
    print_stack(b);

    free_stack(a);
    free_stack(b);
    return (0);
}*/

int     main()
{
    t_stack *a;
    t_stack *b;
    int min_value;

    a = init_stack();
    b = init_stack();
    push(a, 3);
    push(a, 1);
    push(a, 4);
    push(a, 5);
    push(a, 2);
    min_value = find_min(a);
    ft_printf("Initial stack a: ");
    print_stack(a);
    ft_printf("Minimum value in stack a: %d\n", find_min(a));
    move_min_to_b(a, b, min_value);
    ft_printf("After moving minimum value to stack b: ");
    ft_printf("Stack a: ");
    print_stack(a);
    ft_printf("Stack b: ");
    print_stack(b);
    free_stack(a);
    free_stack(b);
    return (0);
}