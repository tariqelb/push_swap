/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:11:11 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 23:19:59 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

char	*ft_strjoin_frees1(char const *s1, char const *s2)
{
	size_t	len;
	size_t	index_i;
	size_t	index_j;
	char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc(sizeof(char) * (len + 1));
	if (joined == NULL)
		return (NULL);
	index_i = 0;
	index_j = 0;
	while (s1[index_j])
		joined[index_i++] = s1[index_j++];
	index_j = 0;
	while (s2[index_j])
		joined[index_i++] = s2[index_j++];
	joined[index_i] = 0;
	free((void *) s1);
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	dest = NULL;
	len = ft_strlen(s1);
	dest = (char *) malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

void	ft_free(void **data, int type, int len)
{
	int		i;
	char	**type1;
	int		**type2;

	i = 0;
	if (type == 1)
	{
		type1 = (char **) data;
		while (type1[i])
			free(type1[i++]);
		free(type1);
	}
	else
	{
		type2 = (int **) data;
		while (i < len)
			free(type2[i++]);
		free(type2);
	}
	data = NULL;
}

int	ft_tab_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_int_range(char *tab)
{
	long long int	nbr;

	nbr = ft_atoi_ll(tab);
	if (nbr > 2147483647)
		return (0);
	if (nbr < -2147483648)
		return (0);
	return (1);
}
