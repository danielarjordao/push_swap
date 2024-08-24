/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:50:24 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 16:50:24 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Sort the stack with 3 elements
// All combinations of the 3 elements are checked
// Maximum 2 moves are needed to sort the stack
void	simple_sort(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	first = (*a)->sort_value;
	second = (*a)->next->sort_value;
	third = (*a)->next->next->sort_value;
	while (!is_sorted(*a))
	{
		if (first < second && first < third)
		{
			sa(a);
			ra(a);
		}
		else if (first > second && first > third)
		{
			ra(a);
			if (second > third)
				sa(a);
		}
		else if (third < first && third < second)
			rra(a);
		else
			sa(a);
	}
}

// Keep 3 values from the highest half of the stack in stack a
// Sort stack a with simple_sort
// Go through the stack b and find the best moves to sort stack a
// add_goal_positions calculates the goal position of the element in stack a
// calculate_cost calculates the cost of moving the element to the goal position
// move_cheapest moves the element with the lowest cost to stack a
// After all elements were moved to stack a, it is sorted with sort_to_finish
// sort_to_finish does rotations to sort the stack
void	advanced_sort(t_stack **a, t_stack **b)
{
	keep_three(a, b);
	simple_sort(a);
	while (*b)
	{
		add_goal_positions(a, b);
		calculate_cost(a, b);
		move_cheapest(a, b);
	}
	if (!is_sorted(*a))
		sort_to_finish(a);
}

// Add sort values to the stack
// The sort value is the position where the element should be in a sorted stack
// If the size is 2, swap the elements
// If the size is 3, sort the elements using simple_sort
// If the size is greater than 3, sort the elements using advanced_sort
void	sort_stack(t_stack **a, t_stack **b)
{
	int		size;

	size = stack_size(*a);
	add_sort_values(a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		simple_sort(a);
	else if (size > 3)
		advanced_sort(a, b);
}
