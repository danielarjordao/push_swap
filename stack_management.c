/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:46:10 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 17:46:10 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_sort_values(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*highest;
	int		content;
	int		size;

	size = stack_size(*stack);
	while (--size > 0)
	{
		temp = *stack;
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
				temp = *stack;
			}
			else
				temp = temp->next;
		}
		if (highest)
			highest->sort_value = size;
	}
}

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

void	keep_three(t_stack **a, t_stack **b)
{
	int		size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = 0;
	while (size_a > 6 && size_b < size_a / 2)
	{
		if ((*a)->sort_value <= size_a / 2)
		{
			pb(a, b);
			size_a--;
			size_b++;
		}
		else
			ra(a);
	}
	while (size_a > 3)
	{
		pb(a, b);
		size_a--;
	}
}

void	add_goal_positions(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		goal;

	temp_b = *b;
	update_positions(a);
	update_positions(b);
	goal = 0;
	while (temp_b)
	{
		goal = find_goal_position(a, temp_b->sort_value);
		temp_b->goal_position = goal;
		temp_b = temp_b->next;
	}
}
