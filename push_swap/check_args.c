/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:28:19 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/03 14:57:57 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv, t_stack **a)
{
	int	i;
	int	split;

	split = 0;
	if (argc == 2)
		argv = split_args(argv[1], &argc, &split, &i);
	else
		i = 1;
	while (argc == 0 || i < argc)
	{
		if (argc == 0 || !is_integer(argv[i])
			|| is_duplicate(*a, ft_atoi(argv[i])))
		{
			if (split)
				free_argv(argv);
			return (0);
		}
		add_args(a, ft_atoi(argv[i]));
		i++;
	}
	if (split)
		free_argv(argv);
	return (1);
}

char	**split_args(char *argv, int *argc, int *split, int *i)
{
	char	**new_argv;

	new_argv = ft_split(argv, ' ');
	*argc = 0;
	while (new_argv[*argc])
		(*argc)++;
	*i = 0;
	*split = 1;
	return (new_argv);
}

int	is_integer(char *str)
{
	long long	num;
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '	')
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	is_duplicate(t_stack *stack, int content)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->content == content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
