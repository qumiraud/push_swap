/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_proxi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:53:29 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/07 11:54:24 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	search_proxi_for_return(int ref, t_stack *stack)
{
	t_stack		*nav;
	t_stack		*reset;
	int			near;

	reset = NULL;
	near = 2147483647;
	nav = stack;
	nav->proxi = 0;
	while (nav)
	{
		if (nav->nbr > ref && nav->nbr < near)
		{
			if (reset)
				reset->proxi = 0;
			near = nav->nbr;
			nav->proxi = 1;
			reset = nav;
		}
		nav = nav->next;
	}
}

void	search_proxi(int ref, t_stack *stack)
{
	t_stack		*nav;
	t_stack		*reset;
	int			near;

	reset = NULL;
	near = -2147483648;
	nav = stack;
	nav->proxi = 0;
	while (nav)
	{
		if (nav->nbr < ref && nav->nbr > near)
		{
			if (reset)
				reset->proxi = 0;
			near = nav->nbr;
			nav->proxi = 1;
			reset = nav;
		}
		nav = nav->next;
	}
}
