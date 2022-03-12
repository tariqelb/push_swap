/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils3_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:46:36 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 23:19:33 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

int	**ft_initialize(int **nbr, int len, int *error)
{
	int	i;

	i = 0;
	nbr = (int **) malloc(sizeof(int *) * len);
	if (nbr == NULL)
	{
		*error = 1;
		return (NULL);
	}
	while (i < len)
	{
		nbr[i] = NULL;
		nbr[i] = (int *) malloc(sizeof(int));
		if (nbr[i] == NULL)
		{
			ft_free((void **) nbr, 2, i);
			*error = 1;
			return (NULL);
		}
		i++;
	}
	return (nbr);
}

int	ft_num_tab(char **tab, int len, int ***nbr)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	*nbr = NULL;
	*nbr = ft_initialize(*nbr, len, &error);
	if (error == 1)
		return (1);
	while (tab[i])
	{
		nbr[0][i][0] = ft_atoi_int(tab[i]);
		i++;
	}
	return (0);
}

int	**ft_get_numbers(char **tab, int tab_len, int **error)
{
	int	**nbr;
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_digit(tab[i]) == 0 || ft_int_range(tab[i]) == 0)
		{
			**error = 1;
			return (NULL);
		}
		i++;
	}
	**error = ft_num_tab(tab, tab_len, &nbr);
	if (**error == 1)
		return (NULL);
	if (ft_duplication(nbr, tab_len) == 1)
	{
		**error = 1;
		ft_free((void **) nbr, 2, tab_len);
		return (nbr);
	}
	return (nbr);
}

int	**ft_valide_args(int ac, char **av, int *tab_len, int *error)
{
	int		i;
	char	*str;
	char	**tab;
	int		**nbr;

	str = NULL;
	tab = NULL;
	i = 1;
	str = ft_strdup(" ");
	while (i < ac)
	{
		str = ft_strjoin_frees1(str, av[i]);
		str = ft_strjoin_frees1(str, " ");
		i++;
	}
	tab = ft_split(str, ' ');
	free(str);
	*tab_len = ft_tab_len(tab);
	nbr = ft_get_numbers(tab, *tab_len, &error);
	ft_free((void **) tab, 1, *tab_len);
	return (nbr);
}

int	ft_fill_stack(t_dlist **stack_A, int ac, char **av)
{
	int		error;
	t_dlist	*new;
	int		**tab;
	int		tab_len;
	int		i;

	error = 0;
	tab_len = 0;
	i = 0;
	tab = ft_valide_args(ac, av, &tab_len, &error);
	if (error == 1 || ft_digit_2(ac, av) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (tab_len > 0)
	{
		new = ft_dlstnew(tab[tab_len - 1]);
		ft_dlstadd_front(stack_A, new);
		tab_len--;
	}
	free(tab);
	return (1);
}
