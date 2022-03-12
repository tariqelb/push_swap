/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:59:08 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 10:41:45 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_back_to_a(t_dlist **s_a, t_dlist **s_b)
{
	int	size;
	int	pos;

	size = ft_dlstsize(*s_b);
	ft_prepare_s_a(s_a, s_b, size);
	pos = 0;
	while (*s_b)
	{
		pos = ft_indexof_biggest_elem(*s_b);
		if (pos <= size / 2)
		{
			while (pos--)
				ft_rotate_ra_rb_rr(s_b, NULL, "rb\n");
			ft_push_a_b(s_b, s_a, "pa\n");
			size--;
		}
		else
		{
			while (pos++ < size)
				ft_reverse_rotate_rra_rrb_rrr(s_b, NULL, "rrb\n");
			ft_push_a_b(s_b, s_a, "pa\n");
			size--;
		}
	}
}

int	ft_pivot_order(t_dlist *s_a, int pivot)
{
	int	elem;
	int	len;

	len = 0;
	elem = ft_biggest_elem(s_a);
	while (elem != pivot)
	{
		elem = ft_nextsmall_elem(s_a, elem);
		len++;
	}
	return (len);
}

int	ft_number_of_push(t_dlist *s_a, int *p, int flag, int size)
{
	int	pushed;

	if (flag == 0)
		pushed = ft_pivot_order(s_a, p[0]);
	if (flag == 1)
		pushed = ft_pivot_order(s_a, p[1]) - ft_pivot_order(s_a, p[0]);
	if (flag == 2)
		pushed = ft_pivot_order(s_a, p[1]) - ft_pivot_order(s_a, p[0]);
	if (flag == 3)
		pushed = ft_pivot_order(s_a, p[1]) - ft_pivot_order(s_a, p[0]);
	if (flag == 4)
		pushed = ft_pivot_order(s_a, p[1]) - ft_pivot_order(s_a, p[0]);
	if (flag == 5)
		pushed = size - ft_pivot_order(s_a, p[0]);
	return (pushed);
}

void	ft_push_to_sb2(t_dlist **s_a, t_dlist **s_b, int *p, int flg)
{
	int	pushed;
	int	size;
	int	index;

	index = 0;
	size = ft_dlstsize(*s_a);
	pushed = ft_number_of_push(*s_a, p, flg, size);
	while (index < size && pushed >= 1)
	{
		if (flg == 2 && *((*s_a)->data) <= p[0] && *((*s_a)->data) > p[1])
			ft_push_a_b(s_a, s_b, "pb\n");
		else if (flg == 3 && *((*s_a)->data) <= p[0] && *((*s_a)->data) > p[1])
			ft_push_a_b(s_a, s_b, "pb\n");
		else if (flg == 4 && *((*s_a)->data) <= p[0] && *((*s_a)->data) > p[1])
			ft_push_a_b(s_a, s_b, "pb\n");
		else if (flg == 5 && (*((*s_a)->data) <= p[0]))
			ft_push_a_b(s_a, s_b, "pb\n");
		else
		{
			ft_reverse_rotate_rra_rrb_rrr(s_a, NULL, "rra\n");
			pushed++;
			index++;
		}
		pushed--;
	}
}

void	ft_push_to_sb3(t_dlist **s_a, t_dlist **s_b, int *p, int flg)
{
	int	pushed;
	int	size;
	int	index;

	index = 0;
	size = ft_dlstsize(*s_a);
	pushed = ft_number_of_push(*s_a, p, flg, size);
	while (index < size && pushed >= 1)
	{
		if (flg == 0 && *((*s_a)->data) > p[0])
			ft_push_a_b(s_a, s_b, "pb\n");
		else if (flg == 1 && *((*s_a)->data) <= p[0] && *((*s_a)->data) > p[1])
			ft_push_a_b(s_a, s_b, "pb\n");
		else
		{
			ft_reverse_rotate_rra_rrb_rrr(s_a, NULL, "rra\n");
			pushed++;
			index++;
		}
		pushed--;
	}
}
