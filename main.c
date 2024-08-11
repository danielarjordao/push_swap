/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:25:29 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 15:25:29 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		ft_printf("%d \0", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack *a;

	a = NULL;
	if (!get_args(argc, argv, &a))
	{
		ft_printf("Error\n");
		return (0);
	}
	print_stack(a);
	return (1);
}
