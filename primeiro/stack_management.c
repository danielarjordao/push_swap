/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:09:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/10 18:26:01 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_args(t_stack **stack, int content)
{
	t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return;
	new_node->content = content;
	new_node->sort_value = 0;
	new_node->current_position = -1;
	new_node->goal_position = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->next = *stack;
	*stack = new_node;
}


// Função para liberar a pilha
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
/*
void	update_positions(t_stack *stack)
{
	t_node	*node;
	int		pos;

	node = stack->top;
	pos = 0;
	node->current_position = pos;
	node = node->next;
	while (node)
	{
		node->current_position = pos++;
		node = node->next;
	}
}
*/
// Função para incluir um valor de ordem na pilha
void	sort_value(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*highest;
	int		content;
	int		size;

	size = stack->size;
	while (--size > 0)
	{
		temp = stack;
		content = INT_MIN;
		highest = NULL;
		while (temp)
		{
			if (temp->content == INT_MIN && temp->sort_value == 0)
				temp->sort_value = 1;
			if (temp->content > content && temp->sort_value == 0)
			{
				content = temp->content;
				highest = temp;
				temp = stack;
			}
			else
				temp = temp->next;
		}
		if (highest)
			highest->sort_value = size;
	}
}



