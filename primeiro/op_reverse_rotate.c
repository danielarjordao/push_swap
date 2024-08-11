/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:27:21 by marvin            #+#    #+#             */
/*   Updated: 2024/08/10 17:19:36 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*bottom;
	t_stack	*second_last;

	bottom = find_bottom(*stack);
	second_last = find_second_to_last(*stack);
	temp = *stack;
	*stack = bottom;
	(*stack)->next = temp;
	second_last->next = NULL;
}

// Função para mover o último nó da pilha a para o currento da pilha
void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

// Função para mover o último nó da pilha b para o currento da pilha
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

// Função para mover o último nó das pilhas a e b para o currento das pilhas
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
