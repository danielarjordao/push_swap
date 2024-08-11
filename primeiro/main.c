/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:51:45 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/10 18:27:31 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para imprimir o conteúdo da pilha
void	print_stack(t_stack **stack)
{
	t_stack	*current;

	current = (*stack);
	while (current)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (0);
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!a || !b)
		return (0);
	if (!check_args(argc, argv, a))
	{
		ft_printf("Error\n");
		free_stack(a);
		free_stack(b);
		return (0);
	}
	ft_printf("Antes de ordenar:\n");
	print_stack(a);
	ft_printf("\nComandos para ordenar:\n");
	if (!is_sorted(*a))
		sort_stack(a, b);
	ft_printf("\nDepois de ordenar a:\n");
	print_stack(a);
	if (*b)
	{
		ft_printf("\nDepois de ordenar b:\n");
		print_stack(b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
