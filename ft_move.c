/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:34:33 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/28 22:11:38 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_swap(t_push **list, char c)
{
	t_push	*tmp;
	int		value[2];

	if (!*list || ft_lstsize_ps(*list) <= 1)
		return ;
	tmp = (*list)->next;
	value[0] = (*list)->content;
	value[1] = tmp->content;
	(*list)->content = value[1];
	tmp->content = value[0];
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	ft_swap_both(t_push **listA, t_push **listB)
{
	t_push	*tmp;
	int		value[2];

	if (!*listA || !*listB || ft_lstsize_ps(*listA) <= 1
		|| ft_lstsize_ps(*listB) <= 1)
		return ;
	tmp = (*listA)->next;
	value[0] = (*listA)->content;
	value[1] = tmp->content;
	(*listA)->content = value[1];
	tmp->content = value[0];
	tmp = (*listB)->next;
	value[0] = (*listB)->content;
	value[1] = tmp->content;
	(*listB)->content = value[1];
	tmp->content = value[0];
	ft_printf("ss\n");
}

void	ft_push_a(t_push **listA, t_push **listB)
{
	t_push	*tmp;

	if (!*listB || ft_lstsize_ps(*listB) < 1)
		return ;
	tmp = *listB;
	*listB = (*listB)->next;
	ft_lstadd_front_ps(listA, tmp);
	ft_printf("pa\n");
}

void	ft_push_b(t_push **listA, t_push **listB)
{
	t_push	*tmp;

	if (!*listA || ft_lstsize_ps(*listA) < 1)
		return ;
	tmp = *listA;
	*listA = (*listA)->next;
	ft_lstadd_front_ps(listB, tmp);
	ft_printf("pb\n");
}
