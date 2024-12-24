/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:12:14 by qumiraud          #+#    #+#             */
/*   Updated: 2024/12/24 15:08:14 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack *ft_newstack(int number)
{
	t_stack	*newstack;
	newstack = malloc(sizeof(t_stack));
	if (!newstack)
		return (NULL);
	newstack->nbr = number;
	newstack->next = NULL;
	return (newstack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}