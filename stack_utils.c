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

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
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
		while (temp_cost_a++ < 0 && temp_cost_b++ < 0)
			rrr(a, b);
	}
	else if (temp_cost_a > 0 && temp_cost_b > 0)
	{
		while (temp_cost_a-- > 0 && temp_cost_b-- > 0)
			rr(a, b);
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

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
