/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:16 by qumiraud          #+#    #+#             */
/*   Updated: 2024/12/24 13:45:33 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	ft_atol_not_digit_error(void)
{
	ft_puterror_fd("Error\n: not digit detected", YELLOW);
		exit(EXIT_FAILURE);
}

void	ft_atol_overflow_error(void)
{
	ft_puterror_fd("Error\n: int_overflow", YELLOW);
		exit(EXIT_FAILURE);
}

int	ft_create_number(char *str, long nbr, int sign)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			ft_puterror_fd("Error\n: not a digit", YELLOW);
			exit(EXIT_FAILURE);
		}
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	nbr *= sign;
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		ft_puterror_fd("Error\n: int_overflow", YELLOW);
		exit(EXIT_FAILURE);
	}
	return (nbr);
}

int	ft_atol(char *str)
{
	int		i;
	long	nbr;
	long	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if ((*str <= '0' && *str >= '9') )
		ft_atol_not_digit_error();
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (str[i])
	{
		if (i > 12)
			ft_atol_overflow_error();
		i++;
	}
	nbr = ft_create_number(str, nbr, sign);
	return ((int) nbr);
}