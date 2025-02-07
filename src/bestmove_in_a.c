/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove_in_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:56:11 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/07 11:57:39 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bestmove_i_big_a(int i, int *move, t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = ft_stacksize(*stack_a);
	i = size_a - i;
	while ((*move) > 0 && i > 0)
	{
		reverse_rotate_rotate(stack_a, stack_b);
		(*move)--;
		i--;
	}
	while (i > 0)
	{
		reverse_rotate_a(stack_a);
		i--;
	}
}

void	bestmove_in_top_a_big(t_stack **stack_a, t_stack **stack_b, int *move)
{
	t_stack		*nav;
	static int	i;
	int			size_a;
	int			size_b;

	nav = (*stack_a);
	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	if ((*move) > size_b / 2)
		(*move) = size_b - (*move);
	if (i > size_a / 2)
		bestmove_i_big_a(i, move, stack_a, stack_b);
	else if (i <= size_a / 2)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
}

void	move_a_on_top(int i, t_stack **stack_a)
{
	int	size_a;

	size_a = ft_stacksize(*stack_a);
	while (i > 0)
	{
		if (i < size_a / 2)
			rotate_a(stack_a);
		else
		{
			i = size_a - i;
			while (i > 0)
			{
				reverse_rotate_a(stack_a);
				i--;
			}
		}
		i--;
	}
}

void	bestmove_in_top_a_little(t_stack **stack_a, t_stack **stack_b, int *move)
{
	t_stack	*nav;
	int		i;
	int		size_a;
	int		size_b;

	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	i = 0;
	nav = (*stack_a);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	if ((*move) <= size_b / 2)
	{
		while ((*move) > 0 && i > 0)
		{
			rotate_rotate(stack_a, stack_b);
			(*move)--;
			i--;
		}
	}
	move_a_on_top(i, stack_a);
}