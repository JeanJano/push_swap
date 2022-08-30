/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_helper1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:43:55 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/21 15:27:06 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_check_ascending(t_push **list)
{
	t_push	*lst;

	lst = *list;
	while (lst)
	{
		if (lst->next != NULL && lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_lst_check_descending(t_push **list)
{
	t_push	*lst;

	lst = *list;
	while (lst)
	{
		if (lst->next != NULL && lst->content < lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_find_max_with_limit(t_push *list, int count)
{
	t_push	*lst;
	int		max;

	lst = list;
	max = ft_lst_min_value(&lst);
	while (lst)
	{
		if (count == lst->index && max < lst->content)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	ft_lst_size(t_push **list)
{
	t_push	*lst;
	int		count;

	count = 0;
	lst = *list;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
