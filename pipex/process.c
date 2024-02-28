/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:21:31 by mchua             #+#    #+#             */
/*   Updated: 2024/02/28 23:21:35 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY, 0777);
	if (fdin == -1)
		error();
	dup2(fdin, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close (fd[0]);
	execute_cmd(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fdout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close (fd[1]);
	execute_cmd(argv[3], envp);
}
