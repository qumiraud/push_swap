/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:59:09 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/07 12:00:15 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bestmove_i_big_b(int i, int *move, t_stack **stack_a, t_stack **stack_b)
{
	int	size_b;

	size_b = ft_stacksize(*stack_b);
	if (i > size_b / 2)
	{
		i = size_b - i;
		while ((*move) > 0 && i > 0)
		{
			reverse_rotate_rotate(stack_a, stack_b);
			(*move)--;
			i--;
		}
		while (i > 0)
		{
			reverse_rotate_b(stack_b);
			i--;
		}
	}
}

void	bestmove_in_top_b_big(t_stack **stack_b, t_stack **stack_a, int *move)
{
	t_stack		*nav;
	static int	i;
	int			size_a;
	int			size_b;

	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	nav = (*stack_b);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	if ((*move) > size_a / 2)
		(*move) = size_a - (*move);
	if (i > size_b / 2)
		bestmove_i_big_b(i, move, stack_a, stack_b);
	else
	{
		while (i > 0)
		{
			rotate_b(stack_b);
			i--;
		}
	}
}

int	get_bestmove_pos(t_stack **stack_b)
{
	t_stack	*nav;
	int		i;

	i = 0;
	nav = (*stack_b);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	return (i);
}

void	bestmove_in_top_b_little(t_stack **stack_b, t_stack **stack_a, int *move)
{
	int	i;

	i = get_bestmove_pos(stack_b);
	if (i > ft_stacksize(*stack_b) / 2)
	{
		i = ft_stacksize(*stack_b) - i;
		while ((*move) > 0 && i > 0)
		{
			rotate_rotate(stack_b, stack_a);
			(*move)--;
			i--;
		}
		while ((*stack_b)->bestmove != 1)
			rotate_b(stack_b);
	}
	while (i > 0)
	{
		rotate_b(stack_b);
		i--;
	}
}