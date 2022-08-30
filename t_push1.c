/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:58:14 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 18:49:22 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_lst_secondlast_ps(t_push **list)
{
	t_push	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->next->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_place_actual_position(t_push **list)
{
	t_push	*lst;
	int		i;

	i = 1;
	lst = *list;
	while (lst)
	{
		lst->actualposition = i;
		i++;
		lst = lst->next;
	}
}

void	ft_place_index(t_push **list)
{
	t_push	*lst;
	int		limit;
	int		size;

	size = ft_lst_size(list);
	while (size > 0)
	{
		lst = *list;
		limit = ft_find_max_with_limit(lst, size);
		size--;
		while (lst)
		{
			if (limit > lst->content)
				lst->index = size;
			lst = lst->next;
		}
	}
}

void	ft_initialise_final_index(t_push **list)
{
	t_push	*lst;
	int		size;

	lst = *list;
	size = ft_lst_size(list);
	while (lst)
	{
		lst->index = size;
		lst = lst->next;
	}
}

void	ft_refresh_linked_list(t_push **listA, t_push **listB)
{
	int		sizeb;
	t_push	*lstb;

	sizeb = ft_lst_size(listB);
	lstb = *listB;
	ft_place_actual_position(listA);
	if (lstb != NULL)
	{
		ft_place_actual_position(listB);
		ft_cost_to_up(listB, sizeb);
		ft_future_place(listA, listB);
		ft_check_future(listA, listB);
		ft_cost_to_place_b_to_a(listA, listB);
	}
}
