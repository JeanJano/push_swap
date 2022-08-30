/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:10:46 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 18:05:35 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_push
{
	int				content;
	int				index;
	int				actualposition;
	int				cost_up;
	int				cost_place_b_in_a;
	int				future_place;
	struct s_push	*next;
}					t_push;

void				parsing(char **av, t_push **list);

t_push				*ft_lstnew_ps(void *content);
void				ft_lstadd_back_ps(t_push **lst, t_push *new);
t_push				*ft_lstlast_ps(t_push *lst);
void				ft_lstadd_front_ps(t_push **lst, t_push *new);
int					ft_lstsize_ps(t_push *lst);
t_push				*ft_lst_secondlast_ps(t_push **list);
void				ft_place_index(t_push **list);
void				ft_place_actual_position(t_push **list);
void				ft_initialise_final_index(t_push **list);
void				ft_refresh_linked_list(t_push **listA, t_push **listB);
void				ft_push_chunck_in_b(t_push **listA, t_push **listB);
void				ft_place_in_a(t_push **listA, t_push **listB);
void				ft_up_min_cost(t_push **list, char name);
void				ft_rotate_until_ascending(t_push **list);
int					ft_min_index(t_push **list);

int					ft_integer_checker(char **av);
int					global_checker(char **av);
int					count(char **av);
int					ft_check_only_space(char *str);

void				ft_free_split(char **arr, int i);
void				ft_free_linked_list(t_push **list);

void				ft_swap(t_push **list, char c);
void				ft_swap_both(t_push **listA, t_push **listB);
void				ft_push_a(t_push **listA, t_push **ListB);
void				ft_push_b(t_push **listA, t_push **listB);
void				ft_rotate(t_push **list, char c);
void				ft_rotate_both(t_push **listA, t_push **listB);
void				ft_reverse_rotate(t_push **list, char c);
void				ft_reverse_rotate_both(t_push **listA, t_push **listB);

void				ft_algo_2(t_push **listA);
void				ft_algo_3(t_push **listA);
void				ft_algo_4_5(t_push **listA, t_push **listB, int size);
void				ft_algo_sup_5(t_push **listA, t_push **listB);

int					ft_check_next_content(t_push **list);
int					ft_lst_find_the_place_to_go(t_push **listA, int content);
int					ft_lst_min_value(t_push **list);
int					ft_lst_min_index(t_push **list, int min);
void				ft_lst_up_the_min(t_push **listA, int size);
int					ft_lst_check_ascending(t_push **list);
int					ft_lst_check_descending(t_push **list);
int					ft_find_max_with_limit(t_push *list, int count);
int					ft_lst_size(t_push **list);

void				ft_cost_to_up(t_push **list, int size);
int					ft_find_index_with_less_cost_to_push(t_push **list);
void				ft_cost_to_place_b_to_a(t_push **listA, t_push **listB);
void				ft_future_place(t_push **listA, t_push **listB);

void				ft_check_future(t_push **listA, t_push **listB);

#endif
