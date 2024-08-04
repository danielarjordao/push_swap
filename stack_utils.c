/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:40:05 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/04 16:48:52 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Função para encontrar o ultimo nó na pilha
t_node	*find_last_node(t_stack *stack)
{
	t_node	*last_node;

	last_node = stack->top;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}


