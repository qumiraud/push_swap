/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:32:25 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/07 13:34:46 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_badarg_error(char *str)
{
	free(str);
	ft_puterror_fd("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_atol_not_digit_error(void)
{
	ft_puterror_fd("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_atol_overflow_error(void)
{
	ft_puterror_fd("Error\n");
	exit(EXIT_FAILURE);
}
