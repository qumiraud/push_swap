/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:54:13 by qumiraud          #+#    #+#             */
/*   Updated: 2024/10/25 09:27:52 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((str[0] != c) && (str[0]))
		i = 1;
	while (str[j])
	{
		if ((str[j] == c && str[j - 1] != c) || str[j] == '\0')
			i++;
		j++;
	}
	return (i);
}

static int	ft_countletters(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static void	ft_freeall(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static char	**ft_strsplit(char **tab, char *str, char c)
{
	int		i;
	int		j;
	char	*kstr;

	i = 0;
	j = 0;
	kstr = str;
	while (str[i])
	{
		if (i == 0 || (str[i] != c && str[i - 1] == c))
		{
			tab[j] = ft_substr(str, i, ft_countletters(kstr, c));
			if (tab[j] == NULL)
				ft_freeall(tab, j);
			j++;
		}
		i++;
		kstr++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *) s;
	str = ft_strtrim(str, &c);
	if (!str)
		return (0);
	tab = ft_calloc(ft_countwords(str, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	ft_strsplit(tab, str, c);
	free(str);
	return (tab);
}
