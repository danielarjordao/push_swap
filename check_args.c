/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:15:48 by marvin            #+#    #+#             */
/*   Updated: 2024/07/20 15:10:33 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para verificar se um argumento é um número inteiro
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

// Função para verificar se um argumento é um número repetido
int	is_duplicate(t_stack *stack, int content)
{
	t_node	*top;

	top = stack->top;
	while (top)
	{
		if (top->content == content)
			return (1);
		top = top->next;
	}
	return (0);
}

int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
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

// Função para verificar se os argumentos são válidos
int	check_args(int argc, char **argv, t_stack *stack)
{
	int	flag;

	flag = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = count_args(argv);
		flag = 1;
	}
	argc--;
	while (argc > 0)
	{
		if (!is_integer(argv[argc])
			|| is_duplicate(stack, ft_atoi(argv[argc])))
			break ;
		push(stack, ft_atoi(argv[argc]));
		argc--;
	}
	if (flag)
		push(stack, ft_atoi(argv[0]));
	if (argv && flag)
		free_argv(argv);
	return (1);
}
