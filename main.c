/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:51:45 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/04 17:09:14 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para imprimir o conteúdo da pilha
void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("\n");
}

// Função para imprimir os valores de ordenação da pilha
void	print_sort_values(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		ft_printf("%d ", current->sort_value);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (0);
	if (!check_args(argc, argv, a))
	{
		ft_printf("Error\n");
		free_stack(a);
		free_stack(b);
		return (0);
	}
	/*
	ft_printf("Antes de ordenar:\n");
	print_stack(a);
	ft_printf("\nComandos para ordenar:\n");
	*/
	if (!is_sorted(a))
		sort_stack(a, b);
	/*
	ft_printf("\nDepois de ordenar a:\n");
	print_stack(a);
	if (b->size)
	{
		ft_printf("\nDepois de ordenar b:\n");
		print_stack(b);
	}
	ft_printf("\n Valores de ordenação de a:\n");
	print_sort_values(a);
	ft_printf("\n Valores de ordenação de b:\n");
	print_sort_values(b);
	*/
	free_stack(a);
	free_stack(b);
	return (0);
}
