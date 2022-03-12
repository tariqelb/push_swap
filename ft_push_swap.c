/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:08:27 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 21:42:37 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	ft_push_to_sb(t_dlist **s_a, t_dlist **s_b, int *p, int flg)
{
	if (flg > 1)
		ft_push_to_sb2(s_a, s_b, p, flg);
	else if (flg <= 1)
		ft_push_to_sb3(s_a, s_b, p, flg);
}

int	main(int ac, char **av)
{
	int		size;
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (ac == 1)
		return (0);
	if (ft_fill_stack(&stack_a, ac, av) == 0)
		return (0);
	size = ft_dlstsize(stack_a);
	if (ft_check_sort(stack_a) == 1)
		return (0);
	if (size <= 3)
		ft_push_swap_3(&stack_a, size);
	else if (size <= 5)
		ft_push_swap_5(&stack_a, &stack_b, size);
	else if (size > 5)
		ft_quick_sort(&stack_a, &stack_b, size);
	ft_dlstclear(&stack_a);
	return (0);
}
