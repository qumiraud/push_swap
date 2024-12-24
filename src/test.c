/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:09:54 by qumiraud          #+#    #+#             */
/*   Updated: 2024/12/24 15:29:11 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	char	*strfullargv = NULL;
	char	**tab;
	int		i;
	t_stack	*stack_a;

	i = 0;
	stack_a = NULL;
	strfullargv = ft_strfullargv(argc, argv);
	if (!strfullargv)
		return (1);
	tab = ft_split(strfullargv, ' ');
	if (!tab)
		return (1);
	while (tab[i] != NULL)
	{
		if (i == 0)
			stack_a = ft_newstack(ft_atol(tab[i]));
		else
			ft_stackadd_back(&stack_a, ft_newstack(ft_atol(tab[i])));
		free(tab[i]);
		i++;
	}
	free(tab);
	while (stack_a)
	{
		printf("- %d : %d\n", i, stack_a->nbr);
		stack_a = stack_a->next;
		i++;
	}
	ft_printf("- %s-\n", strfullargv);
	free(strfullargv);
	return (0);
}
