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

// Find the last element of the stack
t_stack	*find_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

// Check if the stack is sorted
int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
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
