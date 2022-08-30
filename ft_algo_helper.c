/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:01:38 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/18 17:10:58 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_next_content(t_push **list)
{
	t_push	*tmp;

	tmp = *list;
	if (tmp->next != NULL && tmp->next->content > tmp->content)
		return (0);
	return (1);
}

int	ft_lst_find_the_place_to_go(t_push **listA, int content)
{
	t_push	*tmp;
	int		count;

	tmp = *listA;
	count = 1;
	while (tmp)
	{
		if (content < tmp->content)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (0);
}

int	ft_lst_min_value(t_push **list)
{
	t_push	*tmp;
	int		min;

	tmp = *list;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->next != NULL && min > tmp->next->content)
			min = tmp->next->content;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_lst_min_index(t_push **list, int min)
{
	t_push	*tmp;
	int		index;

	index = 1;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content == min)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_lst_up_the_min(t_push **listA, int size)
{
	t_push	*tmp;
	int		min;
	int		index;

	tmp = *listA;
	min = ft_lst_min_value(listA);
	index = ft_lst_min_index(listA, min);
	if (index == 1)
		return ;
	while (1)
	{
		if (index <= (size / 2) + 1)
			ft_rotate(listA, 'a');
		else if (index > size / 2)
			ft_reverse_rotate(listA, 'a');
		tmp = *listA;
		if (min == tmp->content)
			break ;
		tmp = tmp->next;
	}
}
