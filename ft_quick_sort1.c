/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:36:43 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 10:40:56 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_biggest_elem(t_dlist *s_a)
{
	int	elem;

	elem = 0;
	if (s_a != NULL)
		elem = *(s_a->data);
	while (s_a)
	{
		if (*(s_a->data) > elem)
			elem = *(s_a->data);
		s_a = s_a->bottom;
	}
	return (elem);
}

int	ft_smallest_elem(t_dlist *s_a)
{
	int	elem;

	elem = 0;
	if (s_a != NULL)
		elem = *(s_a->data);
	while (s_a)
	{
		if (*(s_a->data) < elem)
			elem = *(s_a->data);
		s_a = s_a->bottom;
	}
	return (elem);
}

int	ft_nextsmall_elem(t_dlist *s_a, int elem)
{
	int	next;
	int	flag;

	flag = 0;
	while (s_a)
	{
		if (*(s_a->data) < elem)
		{
			if (flag == 0)
			{
				next = *(s_a->data);
				flag = 1;
			}
			else if (*(s_a->data) > next)
				next = *(s_a->data);
		}
		s_a = s_a->bottom;
	}
	return (next);
}

int	ft_indexof_nextbigg_elem(t_dlist *s_a, int elem)
{
	int	pos;
	int	index;
	int	prev;

	pos = -1;
	index = 0;
	while (s_a)
	{
		if (*(s_a->data) > elem)
		{
			if (pos == -1)
			{
				prev = *(s_a->data);
				pos = index;
			}
			else if (*(s_a->data) < prev)
			{
				prev = *(s_a->data);
				pos = index;
			}
		}
		index++;
		s_a = s_a->bottom;
	}
	return (pos);
}

void	ft_prepare_s_a(t_dlist **s_a, t_dlist **s_b, int size)
{
	int	index;
	int	elem;

	index = -1;
	size = ft_dlstsize(*s_a);
	elem = ft_biggest_elem(*s_b);
	index = ft_indexof_nextbigg_elem(*s_a, elem);
	if (index == -1)
		return ;
	if (index <= (size / 2))
		while (index-- > 0)
			ft_rotate_ra_rb_rr(s_a, NULL, "ra\n");
	else if (index > (size / 2))
		while (index++ < size)
			ft_reverse_rotate_rra_rrb_rrr(s_a, NULL, "rra\n");
}
