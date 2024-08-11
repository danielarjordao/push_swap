/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:08:03 by marvin            #+#    #+#             */
/*   Updated: 2024/08/10 17:18:07 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack	**dst)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

// Função para mover o nó do currento da pilha b para o currento da pilha a
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}
