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

// First, push half of the stack with the lowest values to stack b
// Then, keep 3 elements from the highest half of the stack in stack a
void	keep_three(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(*a);
	size_b = 0;
	while (size_a > 3 && size_b < size_a / 2)
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

// Update the actual position of the elements in stack a and b
// Go through the stack b and find the best position to insert the element
// Assign the goal position to the element
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
		find_goal_position(a, temp_b->sort_value, &goal);
		temp_b->goal_position = goal;
		temp_b = temp_b->next;
	}
}

// Calculate the cost of moving the elements to the goal position
// The cost_b is its current position, if it is in the first half of the stack
// If it is not, the cost_b is the current position minus the size_b negated
// The cost_a is the goal position, if it is in the first half of the stack
// If it is not, the cost_a is the goal position minus the size_a negated
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

// Calculate the total cost of moving the elements to the goal position
// Use nbr_pos to get the absolute value of the cost
// Assign the cost to the element with the lowest total cost
// Move the element to stack a
void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		cheapest;
	int		total_cost;
	int		cost_a;
	int		cost_b;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		total_cost = nbr_pos(temp->cost_a) + nbr_pos(temp->cost_b);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	move(a, b, cost_a, cost_b);
}

// Here, the stack a is almost sorted
// The elements are in the right position, but the stack is not sorted
// Sort the stack with rotations or reverse rotations to finish the sorting
void	sort_to_finish(t_stack **a)
{
	int		first;

	first = (*a)->sort_value;
	while ((*a)->sort_value && first > stack_size(*a) / 2)
		ra(a);
	while ((*a)->sort_value && first <= stack_size(*a) / 2)
		rra(a);
}
