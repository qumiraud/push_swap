/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:22:59 by qumiraud          #+#    #+#             */
/*   Updated: 2024/12/24 13:41:01 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_badarg_error(void)
{
	ft_puterror_fd("Error\n: an empty or bad argument has been found", YELLOW);
	exit(EXIT_FAILURE);
}
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat_argv(char *strfullargv, char *tmp, char *argv)
{
		tmp = ft_strdupandfree(strfullargv);
		if (tmp == NULL)
			return (NULL);
		strfullargv = ft_strjoin(tmp, argv);
		if (strfullargv == NULL)
			return (NULL);
		free(tmp);
		tmp = ft_strdupandfree(strfullargv);
		if (tmp == NULL)
		return (NULL);
		strfullargv = ft_strjoin(tmp, " ");
		if (strfullargv == NULL)
			return (NULL);
		free(tmp);
		return (strfullargv);
}

char	*ft_strfullargv(int argc, char **argv)
{
	int		i;
	char	*strfullargv = NULL;
	char	*tmp = NULL;

	i = 1;
	if (argv[i][0] == '\0')
		ft_badarg_error();
	strfullargv = ft_clean_malloc(argv[1], ft_strlen(argv[1]));
	if (!strfullargv)
		return (NULL);
	strfullargv = ft_strcpy(strfullargv, argv[1]);
	tmp = ft_strdupandfree(strfullargv);
	if (tmp == NULL)
		return (NULL);
	strfullargv = ft_strjoin(tmp, " ");
	free(tmp);
	while (++i < argc)
	{
		if (argv[i][0] == '\0')
			ft_badarg_error();
		strfullargv = ft_concat_argv(strfullargv, tmp, argv[i]);
		if (strfullargv == NULL)
			return (NULL);
	}
	return (strfullargv);
}
