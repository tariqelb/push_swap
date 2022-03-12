/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:11:16 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/22 00:08:00 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (s1[index] - s2[index]);
	}
	return (s1[index] - s2[index]);
}

t_list	*ft_acts(void)
{
	t_list	*instra;

	instra = NULL;
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("pa\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("pb\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("sa\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("sb\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("ss\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("ra\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("rb\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("rr\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("rra\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("rrb\n")));
	ft_lstadd_back(&instra, ft_lstnew(ft_strdup("rrr\n")));
	return (instra);
}

int	ft_act_error(t_list *act)
{
	int		error;
	t_list	*instra;
	t_list	*a;
	int		flag;

	flag = 0;
	instra = ft_acts();
	while (act && flag == 0)
	{
		error = 0;
		a = instra;
		while (a)
		{
			if (ft_strcmp((char *)act->content, (char *)a->content) != 0)
				error++;
			a = a->next;
		}
		if (error == 11)
			flag = 1;
		act = act->next;
	}
	ft_lstclear(&instra);
	if (flag == 1)
		write(2, "Error\n", 6);
	return (flag);
}

int	ft_check_sort(t_dlist *s_a)
{
	while (s_a && s_a->bottom)
	{
		if (*(s_a->data) > *(s_a->bottom->data))
			return (0);
		s_a = s_a->bottom;
	}
	return (1);
}

int	ft_digit_2(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ' && av[i][j])
			j++;
		if (av[i][j] == 0)
			return (1);
		i++;
	}
	return (0);
}
