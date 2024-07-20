/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:09:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/07/20 15:51:52 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para inicializar a pilha
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

// Função para liberar a pilha
void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top)
	{
		temp = stack->top->next;
		free(stack->top);
		stack->top = temp;
	}
	free(stack);
}

void	update_positions(t_stack *stack)
{
	t_node	*node;
	int		pos;

	node = stack->top;
	pos = 1;
	while (node)
	{
		node->position = pos++;
		node = node->next;
	}
}
