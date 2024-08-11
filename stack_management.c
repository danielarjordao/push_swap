/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:46:10 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 17:46:10 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_sort_value(t_stack **stack)
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
			if (temp->content == INT_MIN && temp->sort_value == 0)
				temp->sort_value = 1;
			if (temp->content > content && temp->sort_value == 0)
			{
				content = temp->content;
				highest = temp;
				temp = *stack;
			}
			else
				temp = temp->next;
		}
		if (highest)
			highest->sort_value = size;
	}
}
