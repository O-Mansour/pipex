/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:58:50 by omansour          #+#    #+#             */
/*   Updated: 2023/01/29 09:03:02 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_nwords(char *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			n++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (n);
}

static char	**ft_deallocate(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**ft_fill(char *str, char **strs, char c)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	z = 0;
	while (str[x])
	{
		while (str[x] == c && str[x])
			x++;
		if (str[x] && str[x] != c)
		{
			y = x;
			while (str[x] != c && str[x])
				x++;
			strs[z] = ft_substr(str, y, x - y);
			if (!strs[z])
				return (ft_deallocate(strs));
			z++;
		}
	}
	return (strs);
}

char	**ft_split(char *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **) ft_calloc(ft_nwords(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	strs = ft_fill(s, strs, c);
	return (strs);
}
