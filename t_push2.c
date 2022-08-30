/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:00:06 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 18:15:23 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_law_chunck_in_b(t_push **listA, t_push **listB, int law)
{
	int		i;

	i = law - 2;
	while (i > 0)
	{
		ft_push_b(listA, listB);
		i--;
	}
}

void	ft_push_chunck_in_b(t_push **listA, t_push **listB)
{
	t_push	*lsta;
	int		low;
	int		high;
	int		size;

	size = ft_lst_size(listA);
	low = size / 3;
	high = low * 2;
	lsta = *listA;
	while (size > low)
	{
		if (lsta->index <= low)
			ft_rotate(listA, 'a');
		else if (lsta->index <= high)
			ft_push_b(listA, listB);
		else if (lsta->index > high)
		{
			ft_push_b(listA, listB);
			ft_rotate(listB, 'b');
		}
		lsta = *listA;
		size = ft_lst_size(listA);
	}
	ft_push_law_chunck_in_b(listA, listB, low);
}

int	ft_min_index(t_push **list)
{
	t_push	*lst;
	int		min;
	int		res;

	lst = *list;
	min = lst->index;
	res = lst->actualposition;
	while (lst)
	{
		if (min < lst->index)
		{
			res = lst->actualposition;
			min = lst->index;
		}
		lst = lst->next;
	}
	return (res + 1);
}

int	ft_lst_min_cost(t_push **list)
{
	t_push	*lst;
	int		min;

	min = 2147483647;
	lst = *list;
	min = lst->cost_place_b_in_a;
	while (lst)
	{
		if (min > lst->cost_place_b_in_a)
			min = lst->cost_place_b_in_a;
		lst = lst->next;
	}
	lst = *list;
	while (lst)
	{
		if (lst->cost_place_b_in_a == min)
		{
			min = lst->actualposition;
			break ;
		}
		lst = lst->next;
	}
	return (min);
}

void	ft_up_min_cost(t_push **list, char name)
{
	t_push	*lst;
	int		min;
	int		count;
	int		size;

	lst = *list;
	size = ft_lstsize_ps(lst);
	if (size <= 1)
		return ;
	min = ft_lst_min_cost(list);
	if (min <= size / 2)
		count = min - 1;
	else
		count = (ft_lstsize_ps(lst) - min) + 1;
	while (count > 0)
	{
		if (min <= size / 2)
			ft_rotate(list, name);
		else
			ft_reverse_rotate(list, name);
		count--;
	}
}
