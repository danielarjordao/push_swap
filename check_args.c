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

int	is_integer(char *str)
{
	long long	num;
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
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

void	add_args(t_stack **stack, int content)
{
	t_stack	*temp;
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = content;
	new->sort_value = 0;
	new->goal_position = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	if (!*stack)
	{
		new->current_position = 0;
		*stack = new;
	}
	else
	{
		temp = find_last(*stack);
		new->current_position = temp->current_position + 1;
		temp->next = new;
	}
}

int	get_args(int argc, char **argv, t_stack **a)
{
	int	i;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		i = 0;
	}
	else
		i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]) 
			|| is_duplicate(*a, ft_atoi(argv[i])))
				return (0);
		add_args(a, ft_atoi(argv[i]));
		i++;
	}
	return (1);
}
