/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:58:24 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/22 00:05:46 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

t_list	*ft_read_instraction(t_list *act)
{
	char	str[6];
	int		rd;

	rd = read(0, str, 5);
	str[rd] = 0;
	if (rd)
		ft_lstadd_back(&act, ft_lstnew((void *)ft_strdup(str)));
	while (rd)
	{
		rd = read(0, str, 5);
		str[rd] = 0;
		if (rd)
			ft_lstadd_back(&act, ft_lstnew((void *)ft_strdup(str)));
	}
	return (act);
}

void	ft_checker2(t_dlist **s_a, t_dlist **s_b, t_list *act)
{
	if (ft_strcmp(act->content, "pa\n") == 0)
		ft_push_a_b(s_b, s_a, "");
	else if (ft_strcmp(act->content, "pb\n") == 0)
		ft_push_a_b(s_a, s_b, "");
	else if (ft_strcmp(act->content, "sa\n") == 0)
		ft_swap_sa_sb_ss(s_a, NULL, "");
	else if (ft_strcmp(act->content, "sb\n") == 0)
		ft_swap_sa_sb_ss(s_b, NULL, "");
	else if (ft_strcmp(act->content, "ss\n") == 0)
		ft_swap_sa_sb_ss(s_a, s_b, "");
	else if (ft_strcmp(act->content, "ra\n") == 0)
		ft_rotate_ra_rb_rr(s_a, NULL, "");
	else if (ft_strcmp(act->content, "rb\n") == 0)
		ft_rotate_ra_rb_rr(s_b, NULL, "");
	else if (ft_strcmp(act->content, "rr\n") == 0)
		ft_rotate_ra_rb_rr(s_a, s_b, "");
	else if (ft_strcmp(act->content, "rra\n") == 0)
		ft_reverse_rotate_rra_rrb_rrr(s_a, NULL, "");
	else if (ft_strcmp(act->content, "rrb\n") == 0)
		ft_reverse_rotate_rra_rrb_rrr(s_b, NULL, "");
	else if (ft_strcmp(act->content, "rrr\n") == 0)
		ft_reverse_rotate_rra_rrb_rrr(s_a, s_b, "");
}

void	ft_checker(t_dlist **s_a, t_dlist **s_b, t_list *act)
{
	int	size;
	int	act_size;

	act_size = ft_lstsize(act);
	size = ft_dlstsize(*s_a);
	while (act)
	{
		ft_checker2(s_a, s_b, act);
		act = act->next;
	}
	if (ft_check_sort(*s_a) == 1 && ft_dlstsize(*s_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list	*act;
	t_dlist	*s_a;
	t_dlist	*s_b;

	act = NULL;
	s_a = NULL;
	s_b = NULL;
	if (ac == 1)
		return (0);
	if (ft_fill_stack(&s_a, ac, av) == 0)
		return (0);
	act = ft_read_instraction(act);
	if (ft_act_error(act) == 1)
		return (0);
	ft_checker(&s_a, &s_b, act);
	ft_dlstclear(&s_a);
	if (s_b != NULL)
		ft_dlstclear(&s_b);
	if (ft_lstsize(act) > 0)
		ft_lstclear(&act);
	return (0);
}
