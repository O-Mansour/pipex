/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:34:30 by omansour          #+#    #+#             */
/*   Updated: 2023/01/29 11:35:12 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirection1(char *av, int *fd)
{
	int	fff;

	fff = open(av, O_RDONLY);
	if (fff == -1)
		show_error(3);
	dup2(fff, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fff);
	close(fd[0]);
	close(fd[1]);
}

void	redirection2(char *av, int *fd)
{
	int	ff;

	ff = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (ff == -1)
		show_error(3);
	dup2(fd[0], STDIN_FILENO);
	dup2(ff, STDOUT_FILENO);
	close(ff);
	close(fd[0]);
	close(fd[1]);
}

void	exec_cmd(char *av, char *ep[])
{
	char	*cmd;
	char	**cmd_args;

	cmd_args = ft_split(av, ' ');
	cmd = full_path(cmd_args[0], ep);
	execve(cmd, cmd_args, ep);
	exit (1);
}

int	main(int ac, char *av[], char *ep[])
{
	int		fd[2];
	int		pid[2];

	if (ac != 5)
		show_error(0);
	if (pipe(fd) == -1)
		show_error(1);
	pid[0] = fork();
	if (pid[0] == -1)
		show_error(2);
	if (pid[0] == 0)
	{
		redirection1(av[1], fd);
		exec_cmd(av[2], ep);
	}
	pid[1] = fork();
	if (pid[1] < 0)
		show_error(2);
	if (pid[1] == 0)
	{
		redirection2(av[4], fd);
		exec_cmd(av[3], ep);
	}
	close_wait(pid[0], pid[1], fd);
	return (0);
}
