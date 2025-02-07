/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:47:35 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/07 11:53:50 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	break_conditions(t_stack *stack_b, t_stack *nav_a, t_stack *nav_b)
{
	int	min_b;
	int	max_b;
	int	i;

	i = 0;
	min_b = ft_find_min(stack_b);
	max_b = ft_find_max(stack_b);
	search_proxi(nav_a->nbr, stack_b);
	if (nav_a->nbr > nav_b->nbr && nav_a->nbr > min_b && nav_b->proxi == 1)
		i = 1;
	else if (nav_a->nbr > max_b && nav_b->nbr == max_b)
		i = 1;
	else if (nav_a->nbr < min_b && nav_b->nbr == max_b)
		i = 1;
	return (i);
}

void	change_best_index(int i, int *j, t_stack **reset, t_stack *nav_a)
{
	*j = i;
	if (*reset)
		(*reset)->bestmove = 0;
	nav_a->bestmove = 1;
	*reset = nav_a;
}

int	get_index_b(t_stack *stack_b, int i, t_stack *nav_a)
{
	t_stack	*nav_b;

	i = 0;
	nav_b = stack_b;
	while (nav_b)
	{
		if (break_conditions(stack_b, nav_a, nav_b) == 1)
			break ;
		i++;
		nav_b = nav_b->next;
	}
	nav_b->proxi = 0;
	return (i);
}

int	ft_cheapest_move(t_stack **stack_a, t_stack *stack_b, int size_b)
{
	int		i_ndex_b;
	int		j_best_b;
	int		k_ndex_a;
	int		l_best_a;
	t_stack	*nav_a;
	t_stack	*reset;

	k_ndex_a = 0;
	l_best_a = 0;
	nav_a = (*stack_a);
	reset = NULL;
	j_best_b = size_b + ft_stacksize(nav_a) * 2;
	while (nav_a)
	{
		i_ndex_b = get_index_b(stack_b, i_ndex_b, nav_a);
		if (k_ndex_a > ft_stacksize(*stack_a)/2)
			k_ndex_a = ft_stacksize(*stack_a) - k_ndex_a;
		if (i_ndex_b + k_ndex_a < j_best_b + l_best_a)
		{
			change_best_index(i_ndex_b, &j_best_b, &reset, nav_a);
			l_best_a = k_ndex_a;
			if (j_best_b <= 2)
				return (j_best_b);
		}
		nav_a = nav_a->next;
		k_ndex_a++;
	}
	return (j_best_b);
}