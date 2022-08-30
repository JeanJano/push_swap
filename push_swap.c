/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:17:28 by jsauvage          #+#    #+#             */
/*   Updated: 2022/08/30 19:14:42 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ft_print_test(t_push *list_a, t_push *list_b)
// {
// 	ft_printf("\nListe A\n\n");
// 	ft_printf("  list\t |   position\t|  final\n");
// 	ft_printf("_________________________________\n\n");
// 	while (list_a)
// 	{
// 		ft_printf("  %d\t | \t%d\t|    %d\t\n", list_a->content,
// 			list_a->actualposition, list_a->index);
// 		list_a = list_a->next;
// 	}
// 	ft_printf("\nListe B\n\n");
// 	ft_printf("  list\t |   position\t|  final   | future | cost place\n");
// 	ft_printf("______________________________________________________\n\n");
// 	while (list_b)
// 	{
// 		ft_printf("  %d\t | \t%d\t|    %d   |     %d    |    %d\t\n",
// 			list_b->content, list_b->actualposition, list_b->index,
// 			list_b->future_place, list_b->cost_place_b_in_a);
// 		list_b = list_b->next;
// 	}
// 	ft_printf("\n\n");
// }

static void	ft_choose_algo(t_push **list_a, t_push **list_b, int size)
{
	if (size == 1)
		return ;
	if (ft_lst_check_ascending(list_a))
		return ;
	else if (size == 2)
		ft_algo_2(list_a);
	else if (size == 3)
		ft_algo_3(list_a);
	else if (size <= 5)
		ft_algo_4_5(list_a, list_b, size);
	else if (size > 5)
		ft_algo_sup_5(list_a, list_b);
}

int	main(int ac, char **av)
{
	t_push	*list_a;
	t_push	*list_b;
	int		size;

	list_a = NULL;
	list_b = NULL;
	if (ac <= 1)
		return (1);
	if (!global_checker(av))
		return (1);
	size = count(av);
	parsing(av, &list_a);
	ft_refresh_linked_list(&list_a, &list_b);
	ft_initialise_final_index(&list_a);
	ft_place_index(&list_a);
	ft_choose_algo(&list_a, &list_b, size);
	if (!ft_lst_check_ascending(&list_a))
		ft_rotate_until_ascending(&list_a);
	ft_free_linked_list(&list_a);
	return (1);
}
