/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fun_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:38:27 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 23:18:11 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

t_dlist	*ft_dlstnew(int *nbr)
{
	t_dlist	*list;

	list = NULL;
	list = (t_dlist *) malloc(sizeof(t_dlist));
	if (list != NULL)
	{
		list->data = nbr;
		list->top = NULL;
		list->bottom = NULL;
	}
	return (list);
}

void	ft_dlstadd_front(t_dlist **list, t_dlist *new)
{
	if (list != NULL && new != NULL)
	{
		if (*list == NULL)
			*list = new;
		else
		{
			new->bottom = *list;
			(*list)->top = new;
			*list = new;
		}
	}
}

int	ft_dlstsize(t_dlist *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->bottom;
	}
	return (len);
}

t_dlist	*ft_dlstlast(t_dlist *list)
{
	if (list == NULL)
		return (NULL);
	while (list->bottom)
		list = list->bottom;
	return (list);
}

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*head;
	t_dlist	*tmp;

	head = NULL;
	tmp = NULL;
	if (lst != NULL && *lst != NULL)
	{
		head = *lst;
		while (head)
		{
			tmp = head->bottom;
			free((void *) head->data);
			free(head);
			head = tmp;
		}
		*lst = NULL;
	}
}
