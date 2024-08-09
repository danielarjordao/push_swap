/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:04:08 by marvin            #+#    #+#             */
/*   Updated: 2024/08/09 18:50:58 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		simple_sort(a);
	else
	{
		update_positions(a);
		advanced_sort(a, b);
	}
}

// Função para verificar se a pilha está ordenada
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

// Função para ordenar pilhas com 3 elementos
void	simple_sort(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (a->top->content == find_min(a)
			&& a->top->next->content == find_max(a))
		{
			sa(a);
			ra(a);
		}
		else if (a->top->content == find_max(a))
		{
			ra(a);
			if (a->top->content > a->top->next->content)
				sa(a);
		}
		else if (a->top->next->content == find_max(a))
			rra(a);
		else
			sa(a);
	}
}

void	advanced_sort(t_stack *a, t_stack *b)
{
	save_three(a, b);
	if (a->size == 3)
		simple_sort(a);
	while (b->size)
	{
		goal_position(a, b);
		calculate_cost(a, b);
		find_cheapest(a, b);
	}
}


