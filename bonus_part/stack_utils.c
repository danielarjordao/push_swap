/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:24:34 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 15:24:34 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Add a new argument to the stack
void	add_args(t_stack **stack, int content)
{
	t_stack	*temp;
	t_stack	*new;

	temp = *stack;
	new = (t_stack *)malloc(sizeof * new);
	if (!new)
		return ;
	new->content = content;
	new->sort_value = 0;
	new->current_position = -1;
	new->goal_position = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		temp = find_last(*stack);
		temp->next = new;
	}
}

// Get the size of the stack
int	stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

// Find the last element of the stack
t_stack	*find_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

// Update the positions of the stack
void	update_positions(t_stack **stack)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = *stack;
	while (temp)
	{
		temp->current_position = pos++;
		temp = temp->next;
	}
}

// Free the stack
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}