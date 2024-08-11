/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:24:54 by marvin            #+#    #+#             */
/*   Updated: 2024/08/10 17:12:08 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para mover o nó do topo da pilha para o final da pilha
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*bottom;

	temp = *stack;
	*stack = (*stack)->next;
	bottom = find_bottom(*stack);
	temp->next = NULL;
	bottom->next = temp;
}

// Função para mover o nó do topo da pilha a para o final da pilha
void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

// Função para mover o nó do topo da pilha b para o final da pilha
void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

// Função para mover o nó do topo das pilhas a e b para o final das pilhas
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
