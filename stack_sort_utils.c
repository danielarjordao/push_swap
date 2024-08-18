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
			if (temp->content > content && temp->sort_value == 0)
			{
				content = temp->content;
				highest = temp;
				temp = *stack;
			}
			else
				temp = temp->next;
		}
		highest->sort_value = size;
	}
}

void	find_goal_position(t_stack **stack, int b_sort, int *goal)
{
	int		limit;
	t_stack	*temp;

	limit = INT_MAX;
	temp = *stack;
	while (temp)
	{
		if (temp->sort_value < limit && temp->sort_value > b_sort)
		{
			limit = temp->sort_value;
			*goal = temp->current_position;
		}
		temp = temp->next;
	}
	if (limit == INT_MAX)
		temp = *stack;
	while (temp)
	{
		if (temp->sort_value < limit)
		{
			limit = temp->sort_value;
			*goal = temp->current_position;
		}
		temp = temp->next;
	}
}

int	nbr_pos(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a != 0 && cost_b != 0)
		move_both(a, b, &cost_a, &cost_b);
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
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
	pa(a, b);
}

void	move_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	if (*cost_a < 0 && *cost_b < 0)
	{
		while (*cost_a < 0 && *cost_b < 0)
		{
			rrr(a, b);
			(*cost_a)++;
			(*cost_b)++;
		}
	}
	else if (*cost_a > 0 && *cost_b > 0)
	{
		while (*cost_a > 0 && *cost_b > 0)
		{
			rr(a, b);
			(*cost_a)--;
			(*cost_b)--;
		}
	}
}
