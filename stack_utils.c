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

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

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

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	find_goal_position(t_stack **stack, int b_sort)
{
	int		limit;
	int		goal;
	t_stack	*temp;

	limit = INT_MAX;
	goal = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->sort_value < limit && temp->sort_value > b_sort)
		{
			limit = temp->sort_value;
			goal = temp->current_position;
		}
		temp = temp->next;
	}
	if (limit != INT_MAX)
		return (goal);
	temp = *stack;
	while (temp)
	{
		if (temp->sort_value < limit)
		{
			limit = temp->sort_value;
			goal = temp->current_position;
		}
		temp = temp->next;
	}
	return (goal);
}
