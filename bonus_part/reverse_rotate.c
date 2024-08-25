/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:08:15 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 17:08:15 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
