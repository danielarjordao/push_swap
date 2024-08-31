/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:28:19 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/11 15:28:19 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// First, check if the arguments are in the form of a string
// If they are, split them into an array of strings
// Then, check if the arguments are integers and if there are any duplicates
// If there are, free the array of strings and return 0
// If there are no errors, add the arguments to the stack
int	check_args(int argc, char **argv, t_stack **a)
{
	int	i;
	int	split;

	split = 0;
	if (argc == 2)
		argv = split_args(argv[1], &argc, &split, &i);
	else
		i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i])
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

// Split the arguments into an array of strings
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

// Check if the string is an integer
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
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

// Check if the content is a duplicate
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

// Free the array of strings
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
