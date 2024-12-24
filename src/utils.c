/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:59:58 by qumiraud          #+#    #+#             */
/*   Updated: 2024/12/23 16:14:03 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void	ft_puterror_fd(const char *str, const char *color)
{
	write(2, color, ft_strlen(color));
	write(2, str, ft_strlen(str));
	write(2, RESET_COLOR, ft_strlen(RESET_COLOR));
}

// long	ft_atol(char *str)
// {
// 	int		i;
// 	long	nbr;
// 	long	sign;

// 	i = 0;
// 	nbr = 0;
// 	sign = 1;
// 	if ((*str <= '0' && *str >= '9') )
// 	{
// 		ft_puterror_fd("Error\n", YELLOW);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	while (*str)
// 	{
// 		if (*str < '0' || *str > '9')
// 		{
// 			ft_puterror_fd("Error\n: not a digit", YELLOW);
// 			exit(EXIT_FAILURE);
// 		}
// 		nbr = nbr * 10 + (*str - 48);
// 		str++;
// 	}
// 	nbr *= sign;
// 	if (nbr > 2147483647 || nbr < -2147483648)
// 	{
// 		ft_puterror_fd("Error\n: int_overflow", YELLOW);
// 		exit(EXIT_FAILURE);
// 	}
// 	return (nbr);
// }