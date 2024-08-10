/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:39:39 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/10 17:32:54 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*// Função para salvar os 3 primeiros elementos da pilha A
void	save_three(t_stack *a, t_stack *b)
{
	int	middle;

	middle = a->size / 2;
	while (a->size > 6 && b->size <= middle)
	{
		if (a->top->sort_value <= middle)
			pb(a, b);
		else
			ra(a);
	}
	while (a->size > 3)
		pb(a, b);
}

int	goal_position(t_stack *a, int sort_value_b)
{
	t_node	*temp_a;
	int		goal;
	int		limit;

	temp_a = a->top;
	goal = 0;
	limit = INT_MAX;
	while (temp_a != NULL)
	{
		if (temp_a->sort_value > sort_value_b && temp_a->sort_value < limit)
		{
			limit = temp_a->sort_value;
			goal = temp_a->current_position;
		}
		temp_a = temp_a->next;
	}
	if (limit != INT_MAX)
		return (goal);
	temp_a = a->top;
	while (temp_a != NULL)
	{
		if (temp_a->sort_value < limit)
		{
			limit = temp_a->sort_value;
			goal = temp_a->current_position;
		}
		temp_a = temp_a->next;
	}
	return (goal);
}

void	assign_goal(t_stack *a, t_stack *b)
{
	t_node	*temp_b;
	int		goal;

	temp_b = b->top;
	goal = 0;
	while (temp_b != NULL)
	{
		goal = goal_position(a, temp_b->sort_value);
		temp_b->goal_position = goal;
		temp_b = temp_b->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*temp_b;
	int		size_a;
	int		size_b;

	temp_b = b->top;
	size_a = a->size;
	size_b = b->size;
	while (temp_b)
	{
		temp_b->cost_b = temp_b->current_position;
		if (temp_b->current_position > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->current_position) * -1;
		temp_b->cost_a = temp_b->goal_position;
		if (temp_b->goal_position > size_a / 2)
			temp_b->cost_a = (temp_b->goal_position) * -1;
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
	cheapest = 	INT_MAX;
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
	rotate_a_and_b(a, b, &cost_a, &cost_b);
	pa(a, b);
}
void	sort_to_finish(t_stack *a)
{
	t_node	*temp;
	int	first_sort;

	temp = a->top;
	first_sort = temp->sort_value;
	while (temp)
	{
		if (first_sort >temp->sort_value)
			first_sort = temp->sort_value;
		temp = temp->next;
	}
	if (first_sort > a->size / 2)
	{
		while (a->top->sort_value != first_sort)
			rra(a);
	}
	else
	{
		while (a->top->sort_value != first_sort)
			ra(a);
	}

}

void	rotate_a_and_b(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	if (*cost_a > 0 && *cost_b > 0)
	{
		while (*cost_a > 0 && *cost_b > 0)
		{
			(*cost_a)--;
			(*cost_b)--;
			rr(a, b);
		}
	}
	else if (*cost_a < 0 && *cost_b < 0)
	{
		while (*cost_a < 0 && *cost_b < 0)
		{
			(*cost_a)++;
			(*cost_b)++;
			rrr(a, b);
		}
	}
	while (*cost_a != 0)
	{
		if (*cost_a < 0)
		{
			rra(a);
			(*cost_a)++;
		}
		else if (*cost_a > 0)
		{
			ra(a);
			(*cost_a)--;
		}
	}
	while (*cost_b)
	{
		if (*cost_b < 0)
		{
			rrb(b);
			(*cost_b)++;
		}
		else if (*cost_b > 0)
		{
			rb(b);
			(*cost_b)--;
		}
	}
}

*/
