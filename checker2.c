/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:46:01 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 19:15:05 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_only_space(char *str)
{
	int	i;
	int	val;
	int	space;

	i = 0;
	val = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = str[i];
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n'
			|| str[i] != '\v' || str[i] != '\f' || str[i] != '\r')
			space = str[i];
		i++;
	}
	if (space != 0 && val == 0)
		return (1);
	return (0);
}

void	ft_check_future(t_push **listA, t_push **listB)
{
	t_push	*lsta;
	t_push	*lstb;
	int		min;
	int		new;

	lsta = *listA;
	min = 2147483647;
	while (lsta)
	{
		if (min > lsta->index)
		{
			min = lsta->index;
			new = lsta->actualposition;
		}
		lsta = lsta->next;
	}
	lstb = *listB;
	while (lstb)
	{
		if (lstb->index < min)
			lstb->future_place = new;
		lstb = lstb->next;
	}
}
