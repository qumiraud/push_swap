/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:05:27 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/30 12:54:10 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bestmove_for_five(t_stack **stack_a, t_stack **stack_b, t_stack *lastnode, int size)
{
		while (size > 3)
	{
		lastnode = ft_stacklast(*stack_a);
		if (ft_find_min(*stack_a) == 0 || ft_find_min(*stack_a) == 1 || ft_find_min(*stack_a) == 2)
		{
			if (ft_find_min(*stack_a) == 2)
				rotate_a(stack_a);
			if (ft_find_min(*stack_a) == 1)
				swap_a(stack_a);
			push_b(stack_a, stack_b);
		}
		else if (ft_find_min(*stack_a) == 4)
		{
			reverse_rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
		else if (ft_find_min(*stack_a) == 3)
		{
			reverse_rotate_a(stack_a);
			size++;
		}
		size--;
	}
}
void	ft_for_five(t_stack	**stack_a, t_stack **stack_b, t_stack *lastnode)
{
	int	size;

	size = ft_stacksize(*stack_a);
	ft_bestmove_for_five(stack_a, stack_b, lastnode, size);
	ft_for_three(stack_a, ft_stacklast(*stack_a));
	size = ft_stacksize(*stack_b);
	while (size-- > 0)
		push_a(stack_a, stack_b);
	if ((*stack_a)->nbr > lastnode->nbr && (*stack_a)->next->nbr < (*stack_a)->nbr)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	while ((*stack_a)->nbr > lastnode->nbr)
		rotate_a(stack_a);

	return ;

}