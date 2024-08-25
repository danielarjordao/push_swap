/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:37:59 by dramos-j          #+#    #+#             */
/*   Updated: 2024/04/20 17:38:47 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(t_list *list)
{
	int	i;

	if (!list || !list->content)
		return (0);
	i = 0;
	while (list->content[i] && i < BUFFER_SIZE)
	{
		if (list->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	if (!content)
		return (NULL);
	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (0);
	lstnew->content = content;
	lstnew->next = 0;
	return (lstnew);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstlast = ft_lstlast(*lst);
	if (lstlast)
		lstlast->next = new;
}

void	freemem(t_list **list, t_list *rest_node, char *rest)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
	if (!rest_node || !rest_node->content[0])
	{
		free(rest);
		free(rest_node);
	}
	else if (rest_node && rest_node->content[0])
		*list = rest_node;
}
