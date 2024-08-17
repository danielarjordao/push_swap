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

void	keep_three(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;

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

void	calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *a;
	temp_b = *b;
	size_a = stack_size(temp_a);
	size_b = stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->current_position;
		if (temp_b->current_position > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->current_position) * -1;
		temp_b->cost_a = temp_b->goal_position;
		if (temp_b->goal_position > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->goal_position) * -1;
		temp_b = temp_b->next;
	}
}

void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (nbr_pos(temp->cost_a) + nbr_pos(temp->cost_b) < nbr_pos(cheapest))
		{
			cheapest = nbr_pos(temp->cost_a) + nbr_pos(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	move(a, b, cost_a, cost_b);
}

void	sort_to_finish(t_stack **a)
{
	int		first;

	first = (*a)->sort_value;
	if (first > stack_size(*a) / 2)
	{
		while ((*a)->sort_value != 0)
			ra(a);
	}
	else
	{
		while ((*a)->sort_value != 0)
			rra(a);
	}
}
