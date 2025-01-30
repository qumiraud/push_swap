/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:21:14 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/30 12:52:50 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_max(t_stack	*stack_a)
{
	t_stack *tmp;
	int	i;
	int j;

	i = 0;
	j = 0;
	tmp = stack_a;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (tmp->nbr < stack_a->nbr)
		{
			tmp = stack_a;
			j = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (tmp->nbr);

}

int	ft_find_min(t_stack	*stack_a)
{
	t_stack *tmp;
	int	i;
	int j;

	i = 0;
	j = 0;
	tmp = stack_a;
	while (stack_a)
	{
		if (tmp->nbr > stack_a->nbr)
		{
			tmp = stack_a;
			j = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (tmp->nbr);

}

int	ft_good_order(t_stack	*stack)
{
	t_stack *tmp;

	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->nbr < stack->nbr)
			{
				return (0);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
void	ft_go_pushswap(t_stack **stack_a)
{
	//t_stack stack_b;
	int	size;

	size = ft_stacksize(*stack_a);
	if (ft_good_order(*stack_a) == 1)
		return ;
	if (size <= 5)
	{
		ft_special_case(stack_a, size);
		return ;
	}
	if (size > 5)
	{
		ft_over_five(stack_a, size);
		return ;
	}
	swap_a(stack_a);
	//free(stack_b);
	return ;
}
