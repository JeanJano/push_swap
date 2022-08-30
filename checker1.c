/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:47:14 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 14:33:54 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static long	ft_check_int(const char *nptr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		count++;
		i++;
	}
	if (count > 10)
		return (0);
	return (1);
}

static int	ft_check_negative_signe(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-' && (av[i + 1] == '-' || av[i + 1] == '\0'))
			return (0);
		if (av[i] == '+' && (av[i + 1] == '+' || av[i + 1] == '\0'))
			return (0);
		if (av[i] == '-' && i > 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_cmp_int(char *av)
{
	if (!ft_check_negative_signe(av))
		return (0);
	if (!ft_check_int(av))
		return (0);
	return (1);
}

int	ft_integer_checker(char **av)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i], ' ');
		while (tab[j])
		{
			if (!ft_cmp_int(tab[j]))
			{
				ft_free_split(tab, j);
				return (0);
			}
			j++;
		}
		ft_free_split(tab, j);
		i++;
	}
	return (1);
}
