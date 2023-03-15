/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omansour <omansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:14:15 by omansour          #+#    #+#             */
/*   Updated: 2023/01/29 10:21:15 by omansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	show_error(int n)
{
	if (n == 0)
		write (2, "Syntax : ./pipex file1 cmd1 cmd2 file2\n", 39);
	else if (n == 1)
		write (2, "Error : pipe() error.\n", 22);
	else if (n == 2)
		write (2, "Error : fork() error.\n", 22);
	else if (n == 3)
		write (2, "Error : no such file (open error).\n", 35);
	else if (n == 4)
		write (2, "Error : command not found.\n", 27);
	exit(1);
}
