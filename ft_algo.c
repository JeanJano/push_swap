/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:46:32 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 19:23:18 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_algo_2(t_push **listA)
{
	if (ft_check_next_content(listA))
		ft_rotate(listA, 'a');
}

void	ft_reverse_algo_2(t_push **list)
{
	if (!ft_check_next_content(list))
		ft_rotate(list, 'b');
}

void	ft_algo_3(t_push **listA)
{
	t_push	*tmp;
	t_push	*tmp1;

	tmp = *listA;
	if (ft_check_next_content(&tmp))
		ft_swap(listA, 'a');
	tmp = tmp->next;
	if (ft_check_next_content(&tmp))
		ft_reverse_rotate(listA, 'a');
	tmp1 = *listA;
	if (ft_check_next_content(&tmp1))
		ft_swap(listA, 'a');
}

void	ft_algo_4_5(t_push **listA, t_push **listB, int size)
{
	if (size == 4)
	{
		ft_lst_up_the_min(listA, size);
		ft_push_b(listA, listB);
	}
	if (size == 5)
	{
		ft_lst_up_the_min(listA, size);
		ft_push_b(listA, listB);
		ft_lst_up_the_min(listA, size);
		ft_push_b(listA, listB);
		ft_reverse_algo_2(listB);
	}
	if (!ft_lst_check_ascending(listA))
		ft_algo_3(listA);
	while (*listB)
		ft_push_a(listA, listB);
}

void	ft_algo_sup_5(t_push **listA, t_push **listB)
{
	ft_push_chunck_in_b(listA, listB);
	ft_algo_2(listA);
	ft_refresh_linked_list(listA, listB);
	while ((*listB) != NULL)
	{
		ft_up_min_cost(listB, 'b');
		ft_place_in_a(listA, listB);
		ft_refresh_linked_list(listA, listB);
	}
}
