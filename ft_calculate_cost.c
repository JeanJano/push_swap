/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:28:35 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 19:14:57 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost_to_up(t_push **list, int size)
{
	t_push	*lst;
	int		i;

	lst = *list;
	i = size / 2;
	if (size % 2 == 1)
		i++;
	while (lst)
	{
		if (lst->actualposition <= size / 2)
			lst->cost_up = lst->actualposition - 1;
		if (lst->actualposition > size / 2)
		{
			if (size % 2 == 1 && lst->actualposition == (size / 2) + 1)
				lst->cost_up = i - 1;
			else
				lst->cost_up = i;
			i--;
		}
		lst = lst->next;
	}
}

int	ft_find_index_with_less_cost_to_push(t_push **list)
{
	t_push	*lst;
	int		size;
	int		min;

	size = ft_lst_size(list);
	lst = *list;
	min = size;
	while (lst)
	{
		if (min > lst->cost_place_b_in_a)
			min = lst->actualposition;
		lst = lst->next;
	}
	return (min);
}

static void	ft_case_future_sup_1(t_push *lstb, int size)
{
	int		i;

	i = (size + 1) - lstb->future_place;
	if (lstb->future_place > size / 2)
		lstb->cost_place_b_in_a = i + lstb->cost_up;
	i = lstb->future_place - 1;
	if (lstb->future_place <= size / 2)
		lstb->cost_place_b_in_a = i + lstb->cost_up;
}

void	ft_cost_to_place_b_to_a(t_push **listA, t_push **listB)
{
	t_push	*lstb;
	int		size;

	lstb = *listB;
	size = ft_lstsize_ps(*listA);
	while (lstb)
	{
		if (lstb->future_place == 0)
			lstb->cost_place_b_in_a = lstb->cost_up;
		else if (lstb->future_place == 1)
			lstb->cost_place_b_in_a = 1 + lstb->cost_up;
		else if (lstb->future_place > size)
			lstb->cost_place_b_in_a = 1 + lstb->cost_up;
		else
			ft_case_future_sup_1(lstb, size);
		lstb = lstb->next;
	}
}

void	ft_future_place(t_push **listA, t_push **listB)
{
	t_push	*lsta;
	t_push	*lstb;
	int		max;

	lstb = *listB;
	while (lstb)
	{
		lsta = *listA;
		max = 0;
		while (lsta)
		{
			if (lstb->index > lsta->index && lsta->index > max)
			{
				lstb->future_place = lsta->actualposition + 1;
				max = lsta->index;
			}
			lsta = lsta->next;
		}
		lstb = lstb->next;
	}
}
