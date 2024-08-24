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

// Start checking the stack from the bottom up, decrementing the size
// Find the highest value that has not been sorted yet
// Assign a sort value, the actual size value, to the highest value
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

// Go through the stack a looking for the best position to insert the element
// Check if the current element sort value is bigger than the b_sort
// And if it is smaller than the limit (limit is the lowest sort value found)
// If it is, assign the goal position to the current element
// After checking all elements, if there is no element with a lower sort value
// Start checking from the beginning of the stack
// Find the lowest sort value and assign the goal position to the element
void	find_goal_position(t_stack **a, int b_sort, int *goal)
{
	int		limit;
	t_stack	*temp;

	limit = INT_MAX;
	temp = *a;
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
		temp = *a;
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

// Get the absolute value of the number
int	nbr_pos(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

// Move the element with the lowest cost to stack a
// If is needed to move both stacks, call move_both
// If the cost is negative, do a reverse rotation, moving the element to the top
// If the cost is positive, do a rotation, moving the element to the bottom
// After the element is in the right position and stack a is ready to receive it
// Move the element to stack a
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

// While both costs are different from 0
// If both costs are negative, do a reverse rotation on both stacks
// If both costs are positive, do a rotation on both stacks
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
