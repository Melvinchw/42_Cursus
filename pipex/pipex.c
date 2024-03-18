/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:58:21 by mchua             #+#    #+#             */
/*   Updated: 2024/03/18 16:06:03 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	start_pipe(char **argv, char **envp)
{
	int	fd[2];
	int	child_id;
	int	grandchild_id;

	if (pipe(fd) == -1)
		error();
	child_id = fork();
	if (child_id == -1)
		error();
	if (child_id == 0)
		child_process(argv, envp, fd);
	else
	{
		waitpid(child_id, NULL, 0);
		grandchild_id = fork();
		if (grandchild_id == 0)
			parent_process(argv, envp, fd);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		start_pipe(argv, envp);
	else
	{
		printf("Bad Argument, only %d argument recieved.\n \
			Please input %d argument.\n", argc, 5);
		printf("Example: ./program filein cmd1 cmd2 fileout\n");
	}
	return (0);
}
