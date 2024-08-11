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
	int		third;

	first = (*a)->sort_value;
	third = (*a)->next->next->sort_value;
	while (!is_sorted(*a))
	{
		if (first == 0 && third == 1)
		{
			sa(a);
			ra(a);
		}
		else if (first == 2)
		{
			ra(a);
			if (third == 0)
				sa(a);
		}
		else if (first == 1 && third == 0)
			rra(a);
		else if (first == 1 && third == 2) // 2 1 3
			sa(a);
	}
}

void	advanced_sort(t_stack **a, t_stack **b)
{
	save_three(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		size;

	size = stack_size(*a);
	ft_printf("size: %d\n", size);
	add_sort_value(a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		simple_sort(a);
	else if (size > 3)
		advanced_sort(a, b);
}
