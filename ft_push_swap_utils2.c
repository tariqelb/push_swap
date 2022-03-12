/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:15:27 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 09:23:50 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long long int	ft_atoi_ll(char *str)
{
	int				i;
	int				sign;
	long long int	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

int	ft_atoi_int(char *str)
{
	int	i;
	int	sign;
	int	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

int	ft_duplication(int **tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i][0] == tab[j][0])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_digit(char *av)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (av[i] == '-' || av[i] == '+')
	{
		i++;
		if (av[i] < '0' || av[i] > '9')
			return (0);
	}
	while (av[i] >= '0' && av[i] <= '9' && av[i])
	{
		flag = 1;
		i++;
	}
	if (av[i] == '\0' && flag == 1)
		return (1);
	return (0);
}
