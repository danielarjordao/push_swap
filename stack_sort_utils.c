/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:39:39 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/09 18:50:39 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_three(t_stack *a, t_stack *b)
{
	int	middle;

	middle = a->size / 2;
	while (a->size > 6 && b->size <= middle)
	{

		if (a->top->current_position <= middle)
			pb(a, b);
		else
			ra(a);
	}
	while (a->size > 3)
		pb(a, b);
}

void	goal_position(t_stack *a, t_stack *b)
{
	t_node	*temp_b;
	t_node	*temp_a;
	int		goal;
	int		limit;

	temp_b = b->top;
	while (temp_b)
	{
		goal = -1;
		limit = INT_MAX;
		temp_a = a->top;
		while (temp_a)
		{
			if (temp_b->content < temp_a->content && temp_a->content < limit)
			{
				limit = temp_a->content;
				goal = temp_a->current_position;
			}
			temp_a = temp_a->next;
		}
		temp_b->goal_position = goal;
		temp_b = temp_b->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*temp_b;

	temp_b = b->top;
	while (temp_b != NULL)
	{
		temp_b->cost_b = temp_b->current_position;
		if (temp_b->current_position > b->size / 2)
			temp_b->cost_b = b->size - temp_b->current_position * -1;
		temp_b->cost_a = temp_b->goal_position;
		if (temp_b->goal_position > a->size / 2)
			temp_b->cost_a = a->size - temp_b->goal_position * -1;
		temp_b = temp_b->next;
	}
}

void	find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*temp_b;
	unsigned int		cheapest;
	unsigned int		total_cost;
	int		cost_a;
	int		cost_b;

	temp_b = b->top;
	cheapest = 	UINT_MAX;
	while (temp_b != NULL)
	{
		total_cost = (unsigned int)temp_b->cost_a + (unsigned int)temp_b->cost_b;
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cost_a = temp_b->cost_a;
			cost_b = temp_b->cost_b;
		}
		temp_b = temp_b->next;
	}
	rotate_a_and_b(a, b, cost_a, cost_b);
	pa(a, b);
}
