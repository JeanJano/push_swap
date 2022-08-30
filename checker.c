/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:34:17 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 14:32:15 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) == 0 || ft_check_only_space(av[i]))
			return (0);
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' '
					|| av[i][j] == '-' || av[i][j] == '+')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	count(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**tab;

	i = 1;
	count = 0;
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i], ' ');
		while (tab[j])
			j++;
		count += j;
		ft_free_split(tab, j);
		i++;
	}
	return (count);
}

static int	*tab(char **av)
{
	int		index[3];
	int		*res;
	char	**arr;

	index[0] = 1;
	index[2] = 0;
	res = malloc((count(av) + 1) * sizeof(int));
	if (!res)
		return (NULL);
	while (av[index[0]])
	{
		index[1] = 0;
		arr = ft_split(av[index[0]], ' ');
		while (arr[index[1]])
		{
			res[index[2]] = ft_atoi(arr[index[1]]);
			index[2]++;
			index[1]++;
		}
		index[0]++;
		ft_free_split(arr, index[1]);
	}
	res[index[2]] = 0;
	return (res);
}

static int	double_checker(char **av)
{
	int	i;
	int	j;
	int	*array;

	i = 0;
	array = tab(av);
	while (i < count(av) - 1)
	{
		j = i + 1;
		while (j < count(av))
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	free(array);
	return (1);
}

int	global_checker(char **av)
{
	if (!checker(av) || !double_checker(av) || !ft_integer_checker(av))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
