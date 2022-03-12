/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:20:13 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 09:27:18 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_indexof_biggest_elem(t_dlist *s_a)
{
	int	pos;
	int	index;
	int	elem;

	pos = 0;
	index = 0;
	if (s_a != NULL)
		elem = *(s_a->data);
	while (s_a)
	{
		if (*(s_a->data) > elem)
		{
			elem = *(s_a->data);
			pos = index;
		}
		index++;
		s_a = s_a->bottom;
	}
	return (pos);
}

int	ft_get_pivot(t_dlist **s_a, int elem, int size, int flag)
{
	int	index;
	int	index_j;
	int	len;

	index = 0;
	len = size / 5;
	while (index <= flag)
	{
		index_j = 0;
		if (index == 0)
			index_j = 2;
		while (index_j < len)
		{
			elem = ft_nextsmall_elem(*s_a, elem);
			index_j++;
		}
		index++;
	}
	return (elem);
}

void	ft_next_pivot(t_dlist **s_a, int *pivot, int size, int flag)
{
	int	elem;

	elem = ft_biggest_elem(*s_a);
	if (flag == 3)
	{
		pivot[0] = ft_get_pivot(s_a, elem, size, 2);
		pivot[1] = ft_get_pivot(s_a, elem, size, 3);
	}
	if (flag == 4)
	{
		pivot[0] = ft_get_pivot(s_a, elem, size, 3);
		pivot[1] = ft_get_pivot(s_a, elem, size, 4);
	}
	if (flag == 5)
		pivot[0] = ft_get_pivot(s_a, elem, size, 4);
}

void	ft_push_to_b_5(t_dlist **s_a, t_dlist **s_b, int size, int flag)
{
	int	pivot[2];
	int	elem;

	elem = ft_biggest_elem(*s_a);
	if (flag == 0)
		pivot[0] = ft_get_pivot(s_a, elem, size, 0);
	if (flag == 1)
	{
		pivot[0] = ft_get_pivot(s_a, elem, size, 0);
		pivot[1] = ft_get_pivot(s_a, elem, size, 1);
	}
	if (flag == 2)
	{
		pivot[0] = ft_get_pivot(s_a, elem, size, 1);
		pivot[1] = ft_get_pivot(s_a, elem, size, 2);
	}
	ft_next_pivot(s_a, pivot, size, flag);
	ft_push_to_sb(s_a, s_b, pivot, flag);
}

void	ft_quick_sort(t_dlist **s_a, t_dlist **s_b, int size)
{
	ft_push_to_b_5(s_a, s_b, size, 0);
	ft_push_back_to_a(s_a, s_b);
	ft_push_to_b_5(s_a, s_b, size, 1);
	ft_push_back_to_a(s_a, s_b);
	ft_push_to_b_5(s_a, s_b, size, 2);
	ft_push_back_to_a(s_a, s_b);
	ft_push_to_b_5(s_a, s_b, size, 3);
	ft_push_back_to_a(s_a, s_b);
	ft_push_to_b_5(s_a, s_b, size, 4);
	ft_push_back_to_a(s_a, s_b);
	ft_push_to_b_5(s_a, s_b, size, 5);
	ft_push_back_to_a(s_a, s_b);
}
