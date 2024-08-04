/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:08:03 by marvin            #+#    #+#             */
/*   Updated: 2024/08/04 15:57:03 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para remover o nó do topo da pilha
// e retornar o conteúdo do nó (pop off)
int	pop(t_stack *stack)
{
	t_node	*temp;
	int		content;

	if (!stack->top)
		return (0);
	temp = stack->top;
	content = stack->top->content;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (content);
}

void	push(t_stack *stack, int content, int sort_value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->sort_value = sort_value;
	new_node->next = stack->top;
	new_node->prev = NULL;
	if (stack->top)
		stack->top->prev = new_node;
	stack->top = new_node;
	stack->size++;
	update_positions(stack);
}


void	pa(t_stack *a, t_stack *b)
{
	push(a, pop(b), b->top->sort_value);
	ft_printf("pa\n");
}

// Função para mover o nó do currento da pilha b para o currento da pilha a
void	pb(t_stack *a, t_stack *b)
{
	push(b, pop(a), a->top->sort_value);
	ft_printf("pb\n");
}
