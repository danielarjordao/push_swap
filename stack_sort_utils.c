/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:20:00 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/17 18:20:00 by dramos-j         ###   ########.fr       */
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

int	nbr_pos(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int		temp_cost_a;
	int		temp_cost_b;

	temp_cost_a = cost_a;
	temp_cost_b = cost_b;
	if (temp_cost_a < 0 && temp_cost_b < 0)
	{
		while (temp_cost_a < 0 && temp_cost_b < 0)
		{
			rrr(a, b);
			temp_cost_a++;
			temp_cost_b++;
		}
	}
	else if (temp_cost_a > 0 && temp_cost_b > 0)
	{
		while (temp_cost_a > 0 && temp_cost_b > 0)
		{
			rr(a, b);
			temp_cost_a--;
			temp_cost_b--;
		}
	}
	while (temp_cost_a)
	{
		if (temp_cost_a < 0)
		{
			rra(a);
			temp_cost_a++;
		}
		else if (temp_cost_a > 0)
		{
			ra(a);
			temp_cost_a--;
		}
	}
	while (temp_cost_b != 0)
	{
		if (temp_cost_b > 0)
		{
			rb(b);
			temp_cost_b--;
		}
		else if (temp_cost_b < 0)
		{
			rrb(b);
			temp_cost_b++;
		}
	}
	pa(a, b);
}
