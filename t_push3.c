/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:20:35 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 11:56:15 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_while_rotate(t_push **list, int way, int index)
{
	if (way == 0)
	{
		while (index > 0)
		{
			ft_reverse_rotate(list, 'a');
			index--;
		}	
	}
	else if (way == 1)
	{
		while (index > 0)
		{
			ft_rotate(list, 'a');
			index--;
		}
	}
}

static void	ft_case_future_0(t_push **listB, t_push **listA, int size)
{
	t_push	*lstb;
	int		min;
	int		i;

	min = ft_min_index(listA);
	i = (size + 1) - min;
	lstb = *listB;
	if (lstb->future_place > size / 2)
	{
		ft_while_rotate(listA, 0, i);
		ft_push_a(listA, listB);
	}
	i = min - 1;
	if (lstb->future_place <= size / 2)
	{
		ft_while_rotate(listA, 1, i);
		ft_push_a(listA, listB);
	}
}

static void	ft_case_future_sup_1(t_push **listA, t_push **listB, int size)
{
	int		i;
	t_push	*lstb;

	lstb = *listB;
	i = (size + 1) - lstb->future_place;
	if (lstb->future_place > size / 2)
	{
		ft_while_rotate(listA, 0, i);
		ft_push_a(listA, listB);
	}
	i = lstb->future_place - 1;
	if (lstb->future_place <= size / 2)
	{
		ft_while_rotate(listA, 1, i);
		ft_push_a(listA, listB);
	}
}

void	ft_place_in_a(t_push **listA, t_push **listB)
{
	t_push	*lsta;
	t_push	*lstb;
	int		size;

	lstb = *listB;
	lsta = *listA;
	size = ft_lstsize_ps(lsta);
	if (lstb->future_place == 1)
		ft_push_a(listA, listB);
	else if (lstb->future_place > size)
	{
		ft_push_a(listA, listB);
		ft_rotate(listA, 'a');
	}
	else if (lstb->future_place == 0)
		ft_case_future_0(listB, listA, size);
	else
		ft_case_future_sup_1(listA, listB, size);
}

void	ft_rotate_until_ascending(t_push **list)
{
	t_push	*lst;
	int		index;
	int		size;

	lst = *list;
	index = 0;
	while (lst)
	{
		if (lst->next != NULL && lst->index > lst->next->index)
			break ;
		index++;
		lst = lst->next;
	}
	size = ft_lstsize_ps(*list);
	index++;
	if (index < size / 2)
		while (!ft_lst_check_ascending(list))
			ft_rotate(list, 'a');
	else
		while (!ft_lst_check_ascending(list))
			ft_reverse_rotate(list, 'a');
}
