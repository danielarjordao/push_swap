/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:04:57 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 17:04:57 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = find_last(*stack);
	last->next = temp;
	temp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
