/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:39:33 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/20 15:50:40 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Funcao para encontrar o menor custo de rotação
int	find_rotation_cost(t_stack *stack, int target)
{
	int		rotation_cost;
	t_node	*current;

	rotation_cost = 0;
	current = stack->top;
	while (current->content != target)
	{
		rotation_cost++;
		current = current->next;
	}
	return (rotation_cost);
}

void	cost_analysis(t_stack *a, t_stack *b)
{
	int	ra_cost;
	int	rra_cost;
	int	pb_cost;

	ra_cost = a->top->position - 1;
	rra_cost = a->size - a->top->position + 1;
	pb_cost = find_pb_cost(a, b);
	if (ra_cost <= rra_cost && ra_cost <= pb_cost)
		ra(a);
	else if (rra_cost <= ra_cost && rra_cost <= pb_cost)
		rra(a);
	else
		pb(a, b);
}
