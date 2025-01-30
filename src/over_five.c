/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:48:04 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/30 14:14:55 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	search_proxi(int ref, t_stack **stack_b)
{
	t_stack		*nav;
	t_stack		*reset;
	int			near;

	reset = NULL;
	near = 2147483647;
	nav = (*stack_b);
	nav->proxi = 0;

	while (nav)
	{
		if (nav->nbr > ref)
		{
			if (nav->nbr < near)
			{
				if (reset)
					reset->proxi = 0;
				near = nav->nbr;
				nav->proxi = 1;
				reset = nav;
			}
		}
		nav = nav->next;
	}
}

int	ft_cheapest_move(t_stack **stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		size_b;
	t_stack	*nav_a;
	t_stack	*nav_b;
	t_stack	*reset;

	nav_a = (*stack_a);
	nav_b = stack_b;
	reset = NULL;
	size_b = ft_stacksize(nav_b);
	i = 0;
	j = size_b + ft_stacksize(nav_a);
	while (nav_a)
	{
		i = 0;
		nav_b = stack_b;
		while (nav_b)
		{
			search_proxi(nav_a->nbr, &stack_b);
			printf("countmove: %d & valeur de nav_a : %ld & valeur de nav_b->proxi: %d\n", i, nav_a->nbr, nav_b->proxi);
			if (nav_a->nbr < nav_b->nbr && nav_b->proxi == 1)
			{
				write (1, "a\n" , 2);
				break;
			}
			else if (nav_a->nbr > ft_find_max(nav_b) && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
			{
				write (1, "b\n" , 2);
				break;
			}
			else if (nav_a->nbr < ft_find_min(nav_b) && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
			{
				// ft_printstack((*stack_a), stack_b);

				write (1, "c\n" , 2);
				break;
			}

				i++;
				nav_b = nav_b->next;
		}
		if ( i < j)
		{
			j = i;
			if (reset)
				reset->bestmove = 0;

			nav_a->bestmove = 1;
			reset = nav_a;
			if (j <= 2)
				return (j);
		}
		nav_a = nav_a->next;
	}
	return (j);
}

void	ft_over_five(t_stack **stack_a, int size_a)
{
	t_stack	*stack_b;
	int		size_b;
	int		move;

	move = 0;
	stack_b = NULL;
	//printf("size : %d\n",size);
	//********************** go_stack_b **************************************//
	push_b(stack_a, &stack_b);
	push_b(stack_a, &stack_b);
	size_a = size_a - 2;
	//printf("size : %d", size);
	while (--size_a >= 3)
	{
		size_b = ft_stacksize(stack_b);
		move =ft_cheapest_move(stack_a, stack_b);
		//printf("move value : %d\n", move);
		// ft_printstack((*stack_a), stack_b);
		while ((*stack_a)->bestmove != 1)
			rotate_a(stack_a);
		if (move < size_b/2)
		{
			while (move > 0 )
			{
					rotate_b(&stack_b);
					move --;
			}
		}
		else
		{
			move = size_b - (move);
			while (move > 0 && move > size_b/2)
			{
				reverse_rotate_b(&stack_b);
				move --;
			}
		}
		push_b(stack_a, &stack_b);
	}

	//********************** go_stack_b **************************************//
	ft_for_three(stack_a, ft_stacklast(*stack_a));

	//?*********************? go_ stack_a ?************************************?//
	// size = ft_stacksize(stack_b);
	// tmp = (*stack_a);
	// while (ft_stacksize(stack_b) > 0)
	// {
	// 	i = 0;
	// 	tmp = (*stack_a);
	// 	//printf("-%ld-\n", (*stack_a)->nbr);
	// 	while (tmp)
	// 	{
	// 		//printf("boucle : %d\n", ft_stacksize(stack_b));

	// 		if (stack_b->nbr > tmp->next->nbr && stack_b->nbr < tmp->nbr) //!probleme stack_last
	// 		{
	// 			i++;
	// 			break;
	// 		}
	// 		else if (stack_b->nbr < ft_find_min(tmp, ft_stacksize(tmp))
	// 			&& (tmp)->nbr == ft_find_min(tmp, ft_stacksize(tmp)))
	// 			break ;
	// 		else if (stack_b->nbr > ft_find_max(tmp, ft_stacksize(tmp))
	// 			&& tmp->nbr == ft_find_min(tmp, ft_stacksize(tmp)))
	// 			break ;
	// 		i++;
	// 		tmp = tmp->next;

	// 	}
	// 	if (i >= ft_stacksize((*stack_a)) / 2)
	// 	{
	// 		while (ft_stacksize((*stack_a)) - (i) > 0)
	// 		{
	// 			reverse_rotate_a(stack_a);
	// 			i++;
	// 		}
	// 	}
	// 	else if (i < ft_stacksize((*stack_a)) / 2)
	// 	{
	// 		while (i > 0)
	// 		{
	// 			rotate_a(stack_a);
	// 			i--;
	// 		}
	// 	}
	// 	// if ((stack_b->nbr < (*stack_a)->nbr && stack_b->nbr > ft_stacklast(*stack_a)->nbr)
	// 	// 	|| (stack_b->nbr < ft_find_min(*stack_a, ft_stacksize((*stack_a))) && (*stack_a)->nbr == ft_find_min(*stack_a, ft_stacksize((*stack_a))))
	// 	// 	|| (stack_b->nbr > ft_find_max(*stack_a, ft_stacksize((*stack_a))) && (*stack_a)->nbr == ft_find_max(*stack_a, ft_stacksize((*stack_a)))))
	// 	// {
	// 		//printf("round : %d\n", ft_stacksize(stack_b));
	// 		push_a(stack_a, &stack_b);
	// 	// 	size--;
	// 	// }
	// 	//ft_printstack(*stack_a, stack_b);

	// }
	while ((*stack_a)->nbr != ft_find_min((*stack_a)))
		rotate_a(stack_a);



	//?*********************? go_stack_a ?************************************?//
	return;
}
