/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:24:54 by marvin            #+#    #+#             */
/*   Updated: 2024/08/09 18:43:43 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para mover o nó do topo da pilha para o final da pilha
void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*last_node;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	last_node = find_last_node(stack);
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	last_node->next = temp;
	temp->prev = last_node;
	temp->next = NULL;
	update_positions(stack);
}

// Função para mover o nó do topo da pilha a para o final da pilha
void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

// Função para mover o nó do topo da pilha b para o final da pilha
void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

// Função para mover o nó do topo das pilhas a e b para o final das pilhas
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
void	rotate_a_and_b(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			rr(a, b);
			cost_a--;
			cost_b--;
		}
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			rrr(a, b);
			cost_a++;
			cost_b++;
		}
	}
	while  (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}
