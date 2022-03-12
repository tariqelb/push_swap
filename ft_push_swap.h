/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:09:28 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/12/21 21:44:11 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlist
{
	int				*data;
	struct s_dlist	*top;
	struct s_dlist	*bottom;
}				t_dlist;

typedef long long int	t_lli;

char	*ft_strjoin_frees1(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_free(void **data, int type, int len);
int		ft_tab_len(char **str);
int		ft_int_range(char *tab);

t_lli	ft_atoi_ll(char *str);
int		ft_atoi_int(char *str);
int		ft_duplication(int **tab, int tab_len);
int		ft_strlen(const char *str);
int		ft_digit(char *av);

int		**ft_initialize(int **nbr, int len, int *error);
int		ft_num_tab(char **tab, int len, int ***nbr);
int		**ft_get_numbers(char **tab, int tab_len, int **error);
int		**ft_valide_args(int ac, char **av, int *tab_len, int *error);
int		ft_fill_stack(t_dlist **stack_A, int ac, char **av);
char	**ft_split(char const *s, char c);

t_dlist	*ft_dlstnew(int *nbr);
void	ft_dlstadd_front(t_dlist **list, t_dlist *new);
int		ft_dlstsize(t_dlist *list);
t_dlist	*ft_dlstlast(t_dlist *list);
void	ft_dlstclear(t_dlist **lst);

void	ft_push_a_b(t_dlist **stack_A, t_dlist **stack_B, char *act);
void	ft_swap_sa_sb_ss(t_dlist **stack_A, t_dlist **stack_B, char *act);
void	ft_rotate_ra_rb_rr(t_dlist **stack_A, t_dlist **stack_B, char *act);
void	ft_reverse_rotate_rra_rrb_rrr(t_dlist **s_A, t_dlist **s_B, char *act);
void	ft_putstr(char *str);

void	ft_push_swap_3(t_dlist **s_a, int size);
int		ft_index_of_next_elem(t_dlist *s_a, int elem);
int		ft_index_of_smallest_elem(t_dlist *s_a);
void	ft_prepare_stack(t_dlist **s_a, t_dlist **s_b, int size);
void	ft_push_swap_5(t_dlist **s_a, t_dlist **s_b, int size);

int		ft_biggest_elem(t_dlist *s_a);
int		ft_smallest_elem(t_dlist *s_a);
int		ft_nextsmall_elem(t_dlist *s_a, int elem);
int		ft_indexof_nextbigg_elem(t_dlist *s_a, int elem);
void	ft_prepare_s_a(t_dlist **s_a, t_dlist **s_b, int size);

void	ft_push_back_to_a(t_dlist **s_a, t_dlist **s_b);
int		ft_pivot_order(t_dlist *s_a, int pivot);
int		ft_number_of_push(t_dlist *s_a, int *p, int flag, int size);
void	ft_push_to_sb2(t_dlist **s_a, t_dlist **s_b, int *p, int flg);
void	ft_push_to_sb3(t_dlist **s_a, t_dlist **s_b, int *p, int flg);

int		ft_indexof_biggest_elem(t_dlist *s_a);
int		ft_get_pivot(t_dlist **s_a, int elem, int size, int flag);
void	ft_next_pivot(t_dlist **s_a, int *pivot, int size, int flag);
void	ft_push_to_b_5(t_dlist **s_a, t_dlist **s_b, int size, int flag);
void	ft_quick_sort(t_dlist **s_a, t_dlist **s_b, int size);

int		ft_check_sort(t_dlist *s_a);
int		ft_digit_2(int ac, char **av);
void	ft_push_to_sb(t_dlist **s_a, t_dlist **s_b, int *p, int flg);

#endif
