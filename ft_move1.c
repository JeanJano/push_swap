/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:00:22 by jsauvage          #+#    #+#             */
/*   Updated: 2022/07/20 19:57:48 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_rotate(t_push **list, char c)
{
	t_push	*tmp;

	if (!*list)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(list, tmp);
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_both(t_push **listA, t_push **listB)
{
	t_push	*tmp;

	if (!*listA || !*listB)
		return ;
	tmp = *listA;
	*listA = (*listA)->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(listA, tmp);
	tmp = *listB;
	*listB = (*listB)->next;
	tmp->next = NULL;
	ft_lstadd_back_ps(listB, tmp);
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_push **list, char c)
{
	t_push	*tmp;
	t_push	*last;
	t_push	*second_last;

	if (!*list)
		return ;
	tmp = *list;
	second_last = ft_lst_secondlast_ps(list);
	last = ft_lstlast_ps(tmp);
	ft_lstadd_front_ps(list, last);
	second_last->next = NULL;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_reverse_rotate_both(t_push **listA, t_push **listB)
{
	t_push	*tmp;
	t_push	*last;
	t_push	*second_last;

	if (!*listA || !*listB)
		return ;
	tmp = *listA;
	second_last = ft_lst_secondlast_ps(listA);
	last = ft_lstlast_ps(tmp);
	ft_lstadd_front_ps(listA, last);
	second_last->next = NULL;
	tmp = *listB;
	second_last = ft_lst_secondlast_ps(listB);
	last = ft_lstlast_ps(tmp);
	ft_lstadd_front_ps(listB, last);
	second_last->next = NULL;
	ft_printf("rrr\n");
}
