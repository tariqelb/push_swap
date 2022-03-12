/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:46:17 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/22 00:09:44 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_BONUS_H
# define FT_CHECKER_BONUS_H

# include "../ft_push_swap.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

int		ft_strcmp(char *s1, char *s2);
t_list	*ft_acts(void);
int		ft_act_error(t_list *act);

t_list	*ft_read_instraction(t_list *act);
void	ft_checker2(t_dlist **s_a, t_dlist **s_b, t_list *act);
void	ft_checker(t_dlist **s_a, t_dlist **s_b, t_list *act);

#endif
