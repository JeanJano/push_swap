/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:30:16 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/22 11:38:32 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	parsing(char **av, t_push **list)
{
	int		i;
	int		j;
	char	**tab;
	t_push	*new;

	i = 1;
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i], ' ');
		while (tab[j])
		{
			new = ft_lstnew_ps(tab[j]);
			ft_lstadd_back_ps(list, new);
			j++;
		}
		ft_free_split(tab, j);
		i++;
	}
}
