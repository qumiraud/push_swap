/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:45:21 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/07 12:26:23 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nodouble(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (tmp->nbr == stack_a->nbr)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
