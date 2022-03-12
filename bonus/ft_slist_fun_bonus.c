/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_list_fun_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:40:40 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 23:10:37 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = NULL;
	list = (t_list *) malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	tmp = NULL;
	if (lst != NULL)
	{
		head = *lst;
		while (head)
		{
			tmp = head->next;
			free(head->content);
			free(head);
			head = tmp;
		}
		*lst = NULL;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (new != NULL && lst != NULL)
	{
		head = *lst;
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (head->next != NULL)
				head = head->next;
			head->next = new;
		}
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
