# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 20:59:26 by tel-bouh          #+#    #+#              #
#    Updated: 2021/12/21 23:24:10 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRC = ./ft_push_swap.c ./ft_push_swap_utils.c ./ft_push_swap_utils2.c ./ft_push_swap_utils3.c \
	  ./ft_split.c ./ft_list_fun.c ./ft_actions.c ./ft_sort_3_and_5.c \
	  ./ft_quick_sort.c ./ft_quick_sort1.c ./ft_quick_sort2.c

INCLUDE = ./

SRC_BONUS = ./bonus/ft_checker_bonus.c ./bonus/ft_checker_utils_bonus.c ./bonus/ft_actions_bonus.c \
			./bonus/ft_list_fun_bonus.c ./bonus/ft_slist_fun_bonus.c ./bonus/ft_split_bonus.c \
			./bonus/ft_push_swap_utils2_bonus.c ./bonus/ft_push_swap_utils3_bonus.c ./bonus/ft_push_swap_utils_bonus.c

INCLUDE_BONUS = ./bonus/

FLAG = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(FLAG) $(SRC) -I $(INCLUDE)

bonus : $(BONUS)

$(BONUS) :
	gcc -o $(BONUS) $(FLAG) $(SRC_BONUS) -I $(INCLUDE_BONUS)

fclean :
	rm -rf $(NAME) $(BONUS)

re: fclean all
