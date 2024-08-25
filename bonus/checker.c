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

int	check_command2(char *command, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(command, "rra", 3))
		reverse_rotate(a);
	else if (!ft_strncmp(command, "rrb", 3))
		reverse_rotate(b);
	else if (!ft_strncmp(command, "rrr", 3))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else if (!ft_strncmp(command, "ra", 2))
		rotate(a);
	else if (!ft_strncmp(command, "rb", 2))
		rotate(b);
	else if (!ft_strncmp(command, "rr", 2))
	{
		rotate(a);
		rotate(b);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	check_command(char *command, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(command, "sa", 2))
		swap(a);
	else if (!ft_strncmp(command, "sb", 2))
		swap(b);
	else if (!ft_strncmp(command, "ss", 2))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp(command, "pa", 2))
		push(b, a);
	else if (!ft_strncmp(command, "pb", 2))
		push(a, b);
	else
		return (check_command2(command, a, b));
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
	if (argc < 2 || !check_args(argc, argv, &a))
	{
		free_stack(&a);
		return (0);
	}
	command = get_next_line(0);
	while (command != NULL)
	{
		if (!check_command(command, &a, &b))
			break ;
		free(command);
		command = get_next_line(0);
	}
	free(command);
	print_return(a, b);
	free_stack(&a);
	free_stack(&b);
	return (1);
}
