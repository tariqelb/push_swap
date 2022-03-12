/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:37:51 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 23:17:26 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	ft_push_a_b(t_dlist **stack_a, t_dlist **stack_b, char *act)
{
	t_dlist	*push;
	t_dlist	*nxt;

	if (stack_a && *stack_a)
	{
		nxt = (*stack_a)->bottom;
		push = *stack_a;
		push->bottom = *stack_b;
		push->top = NULL;
		if (*stack_b != NULL)
			(*stack_b)->top = push;
		*stack_b = push;
		*stack_a = nxt;
		if (*stack_a != NULL)
			(*stack_a)->top = NULL;
	}
	ft_putstr(act);
}

void	ft_swap_sa_sb_ss(t_dlist **stack_a, t_dlist **stack_b, char *act)
{
	t_dlist	*temp;

	if (stack_a && *stack_a && (*stack_a)->bottom)
	{
		temp = (*stack_a)->bottom;
		if (temp->bottom)
			temp->bottom->top = (*stack_a);
		(*stack_a)->bottom = temp->bottom;
		temp->bottom = (*stack_a);
		(*stack_a)->top = temp;
		temp->top = NULL;
		(*stack_a) = temp;
	}
	if (stack_b && *stack_b && (*stack_b)->bottom)
	{
		temp = (*stack_b)->bottom;
		if (temp->bottom)
			temp->bottom->top = (*stack_b);
		(*stack_b)->bottom = temp->bottom;
		temp->bottom = (*stack_b);
		(*stack_b)->top = temp;
		temp->top = NULL;
		(*stack_b) = temp;
	}
	ft_putstr(act);
}

void	ft_rotate_ra_rb_rr(t_dlist **stack_a, t_dlist **stack_b, char *act)
{
	t_dlist	*temp;
	t_dlist	*last;

	temp = NULL;
	if (stack_a && *stack_a && (*stack_a)->bottom)
	{
		temp = (*stack_a)->bottom;
		last = ft_dlstlast(*stack_a);
		last->bottom = *stack_a;
		(*stack_a)->top = last;
		(*stack_a)->bottom = NULL;
		temp->top = NULL;
		*stack_a = temp;
	}
	if (stack_b && *stack_b && (*stack_b)->bottom)
	{
		temp = (*stack_b)->bottom;
		last = ft_dlstlast(*stack_b);
		last->bottom = *stack_b;
		(*stack_b)->top = last;
		(*stack_b)->bottom = NULL;
		temp->top = NULL;
		*stack_b = temp;
	}
	ft_putstr(act);
}

void	ft_reverse_rotate_rra_rrb_rrr(t_dlist **s_a, t_dlist **s_b, char *act)
{
	t_dlist	*last;

	last = NULL;
	if (s_a && *s_a && (*s_a)->bottom)
	{
		last = ft_dlstlast(*s_a);
		last->bottom = (*s_a);
		last->top->bottom = NULL;
		(*s_a)->top = last;
		last->top = NULL;
		*s_a = last;
	}
	if (s_b && *s_b && (*s_b)->bottom)
	{
		last = ft_dlstlast(*s_b);
		last->bottom = *s_b;
		last->top->bottom = NULL;
		(*s_b)->top = last;
		last->top = NULL;
		*s_b = last;
	}
	ft_putstr(act);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
