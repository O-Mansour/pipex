/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:46:42 by omansour          #+#    #+#             */
/*   Updated: 2023/01/29 11:52:38 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_path(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg[i] == '/')
			return (1);
	return (0);
}

char	*path_value(char *ep[])
{
	int	i;

	i = -1;
	while (ep[++i])
		if (!ft_strncmp("PATH=", ep[i], 5))
			return (ep[i] + 5);
	return (NULL);
}

void	ft_free(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

char	*full_path(char *arg, char *ep[])
{
	char	*path;
	char	**p;
	int		i;

	i = -1;
	if (!access(arg, X_OK))
		return (arg);
	else if (!is_path(arg))
	{
		path = path_value(ep);
		p = ft_split(path, ':');
		while (p[++i])
		{
			path = ft_sjoin(p[i], arg);
			if (!access(path, X_OK))
			{
				ft_free(p);
				return (path);
			}
			free(path);
		}
		ft_free(p);
	}
	show_error(4);
	return (NULL);
}

void	close_wait(int pid1, int pid2, int *fd)
{
	close (fd[0]);
	close (fd[1]);
	waitpid (pid1, NULL, 0);
	waitpid (pid2, NULL, 0);
}
