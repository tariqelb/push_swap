/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:53:45 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 10:43:38 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_swap_3(t_dlist **s_a, int size)
{
	int	second;
	int	third;

	second = *((*s_a)->bottom->data);
	if (size == 3)
		third = *((*s_a)->bottom->bottom->data);
	if (size == 2 && (*((*s_a)->data) > second))
		ft_swap_sa_sb_ss(s_a, NULL, "sa\n");
	else if ((*((*s_a)->data) > second) && (*((*s_a)->data) < third))
		ft_swap_sa_sb_ss(s_a, NULL, "sa\n");
	else if ((*((*s_a)->data) < second) && (*((*s_a)->data) > third))
		ft_reverse_rotate_rra_rrb_rrr(s_a, NULL, "rra\n");
	else if ((*((*s_a)->data) > second) && (second > third))
	{
		ft_swap_sa_sb_ss(s_a, NULL, "sa\n");
		ft_reverse_rotate_rra_rrb_rrr(s_a, NULL, "rra\n");
	}
	else if ((third < *((*s_a)->data)) && (second < third))
		ft_rotate_ra_rb_rr(s_a, NULL, "ra\n");
	else if ((third > *((*s_a)->data)) && (second > third))
	{
		ft_swap_sa_sb_ss(s_a, NULL, "sa\n");
		ft_rotate_ra_rb_rr(s_a, NULL, "ra\n");
	}
}

int	ft_index_of_next_elem(t_dlist *s_a, int elem)
{
	int		index;
	int		pos;
	t_dlist	*prev;

	pos = -1;
	index = 0;
	while (s_a)
	{
		if (*(s_a->data) > elem)
		{
			if (pos != -1 && *(prev->data) > *(s_a->data))
			{
				pos = index;
				prev = s_a;
			}
			if (pos == -1)
			{
				pos = index;
				prev = s_a;
			}
		}
		index++;
		s_a = s_a->bottom;
	}
	return (pos);
}

int	ft_index_of_smallest_elem(t_dlist *s_a)
{
	int	index;
	int	pos;
	int	elem;

	pos = -1;
	index = 0;
	if (s_a)
	{
		elem = *(s_a->data);
		pos = 0;
		while (s_a)
		{
			if (*(s_a->data) < elem)
			{
				pos = index;
				elem = *(s_a->data);
			}
			index++;
			s_a = s_a->bottom;
		}
	}
	return (pos);
}

void	ft_prepare_stack(t_dlist **s_a, t_dlist **s_b, int size)
{
	int	index;

	index = -1;
	if (s_b != NULL && *(s_b) != NULL)
		index = ft_index_of_next_elem(*s_a, *((*s_b)->data));
	if (index == -1)
		index = ft_index_of_smallest_elem(*s_a);
	if (index <= (size / 2))
	{
		while (index > 0)
		{
			ft_rotate_ra_rb_rr(s_a, NULL, "ra\n");
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			ft_reverse_rotate_rra_rrb_rrr(s_a, NULL, "rra\n");
			index++;
		}
	}
}

void	ft_push_swap_5(t_dlist **s_a, t_dlist **s_b, int size)
{
	if (size == 4)
		ft_push_a_b(s_a, s_b, "pb\n");
	else
	{
		ft_push_a_b(s_a, s_b, "pb\n");
		ft_push_a_b(s_a, s_b, "pb\n");
	}
	ft_push_swap_3(s_a, 3);
	ft_prepare_stack(s_a, s_b, 3);
	ft_push_a_b(s_b, s_a, "pa\n");
	ft_prepare_stack(s_a, s_b, 4);
	if (size > 4)
	{
		ft_push_a_b(s_b, s_a, "pa\n");
		ft_prepare_stack(s_a, NULL, 5);
	}
}
