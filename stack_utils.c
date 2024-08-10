/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:40:05 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/10 17:49:23 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
// Função para encontrar o valor mínimo na pilha
int	find_min(t_stack *stack)
{
	int		min_value;
	t_node	*next_node;

	next_node = stack->top->next;
	min_value = stack->top->content;
	while (next_node)
	{
		if (next_node->content < min_value)
			min_value = next_node->content;
		next_node = next_node->next;
	}
	return (min_value);
}

// Função para encontrar o valor máximo na pilha
int	find_max(t_stack *stack)
{
	int		max_value;
	t_node	*next_node;

	next_node = stack->top->next;
	max_value = stack->top->content;
	while (next_node)
	{
		if (next_node->content > max_value)
			max_value = next_node->content;
		next_node = next_node->next;
	}
	return (max_value);
}
*/

// Função para encontrar o ultimo nó na pilha
t_stack	*find_bottom(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_second_to_last(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}
/*
int	find_position(t_stack *stack, int target)
{
	t_node	*node;
	int		pos;

	node = stack->top;
	pos = 1;
	while (node)
	{
		if (node->content == target)
			return (pos);
		pos++;
		node = node->next;
	}
	return (0);
}
*/


