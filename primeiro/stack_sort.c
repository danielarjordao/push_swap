/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:04:08 by marvin            #+#    #+#             */
/*   Updated: 2024/08/10 18:02:44 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	sort_value(*a);
	if ((*a)->size == 2)
		sa(a);
	else if ((*a)->size == 3)
		simple_sort(a);
	if (*b)
		ft_printf("Error\n");
//	else
//	{
//		sort_value(a);
//		advanced_sort(a, b);
//	}
}

// Função para verificar se a pilha está ordenada
int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while(stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Função para ordenar pilhas com 3 elementos
void	simple_sort(t_stack **a)
{
	while (!is_sorted(*a))
	{
		if ((*a)->sort_value == 1
			&& find_bottom(*a)->sort_value == 3)
		{
			sa(a);
			ra(a);
		}
		else if ((*a)->sort_value == 3)
		{
			ra(a);
			if ((*a)->sort_value > (*a)->next->sort_value)
				sa(a);
		}
		else if ((*a)->next->sort_value == 3)
			rra(a);
		else
			sa(a);
	}
}
/*
void	advanced_sort(t_stack *a, t_stack *b)
{
	save_three(a, b);
	if (a->size == 3)
		simple_sort(a);
	while (b->size)
	{
		assign_goal(a, b);
		calculate_cost(a, b);
		find_cheapest(a, b);
		print_stack(a);
		print_stack(b);
	}
	sort_to_finish(a);
}*/

