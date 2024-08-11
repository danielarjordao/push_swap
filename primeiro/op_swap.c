/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:22:07 by marvin            #+#    #+#             */
/*   Updated: 2024/08/10 17:06:45 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para trocar o conteúdo dos dois primeiros nós da pilha
void	swap(t_stack *stack)
{
	int temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	temp = stack->sort_value;
	stack->sort_value = stack->next->sort_value;
	stack->next->sort_value = temp;
}

// Função para trocar o conteúdo dos dois primeiros nós da pilha a
void	sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

// Função para trocar o conteúdo dos dois primeiros nós da pilha b
void	sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

// Função para trocar o conteúdo dos dois primeiros nós das pilhas a e b
void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
