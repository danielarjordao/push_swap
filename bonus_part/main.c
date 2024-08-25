/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:03:32 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/24 16:03:32 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*
void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		ft_printf("%d ", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}*/

int	check_command(char *command, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(command, "sa", 2))
		sa(&a);
	else if (!ft_strncmp(command, "sb", 2))
		sb(&b);
	else if (!ft_strncmp(command, "ss", 2))
		ss(&a, &b);
	else if (!ft_strncmp(command, "pa", 2))
		pa(&a, &b);
	else if (!ft_strncmp(command, "pb", 2))
		pb(&a, &b);
	else if (!ft_strncmp(command, "rra", 3))
		rra(&a);
	else if (!ft_strncmp(command, "rrb", 3))
		rrb(&b);
	else if (!ft_strncmp(command, "rrr", 3))
		rrr(&a, &b);
	else if (!ft_strncmp(command, "ra", 2))
		ra(&a);
	else if (!ft_strncmp(command, "rb", 2))
		rb(&b);
	else if (!ft_strncmp(command, "rr", 2))
		rr(&a, &b);
	else
		return (0);
	return (1);
}

void	print_return(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!check_args(argc, argv, &a))
	{
		free_stack(&a);
		return (0);
	}
	command = get_next_line(0);
	while (command != NULL)
	{
		if (!check_command(command, a, b))
		{
			ft_printf("Error\n");
			break ;
		}
		free(command);
		command = get_next_line(0);
	}
	free(command);
	print_return(a, b);
	free_stack(&a);
	free_stack(&b);
	return (1);
}
