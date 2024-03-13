/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:58:21 by mchua             #+#    #+#             */
/*   Updated: 2024/03/13 21:47:56 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int process_id;
	int grandchild_id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		process_id = fork();
		if (process_id == -1)
			error();
		if (process_id == 0)
			child_process(argv, envp, fd);
		else
		{
			waitpid(process_id, NULL, 0);
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
	else
	{
		printf("Bad Argument, only %d argument recieved. \
			Please input %d argument.\n", argc, 5);
		printf("Example: ./program filein cmd1 cmd2 fileout\n");
	}
	return (0);
}
