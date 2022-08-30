/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:45:46 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 18:47:44 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_push	*ft_lstnew_ps(void *content)
{
	t_push	*res;

	res = malloc(sizeof(t_push));
	if (!res)
		return (NULL);
	res->content = ft_atoi(content);
	res->future_place = 0;
	res->next = NULL;
	return (res);
}

void	ft_lstadd_back_ps(t_push **lst, t_push *new)
{
	t_push	*last;

	if (*lst)
	{
		last = ft_lstlast_ps((*lst));
		last->next = new;
	}
	else
		*lst = new;
}

t_push	*ft_lstlast_ps(t_push *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front_ps(t_push **lst, t_push *new)
{
	new->next = (*lst);
	*lst = new;
}

int	ft_lstsize_ps(t_push *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
