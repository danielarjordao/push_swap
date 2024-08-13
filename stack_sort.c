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

void	advanced_sort(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	keep_three(a, b);
	simple_sort(a);
	temp = *b;
	while (temp)
	{
		add_goal_positions(a, b);
		temp = temp->next;
	}
}

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
