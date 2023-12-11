/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:58:21 by mchua             #+#    #+#             */
/*   Updated: 2023/12/11 22:05:27 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	child_process(char **argv, char **envp, int *fd)
{
}

void	parent_parent(char **argv, char **envp, int *fd)
{
}

void	execute_cmd(char *argv, char **envp)
{
	//I have an  argument with ' ', I have to turn it into 5 array of string without ' '
	//I will do so by using ft_split wit '  ' as a delimiter
	char	**cmd;//to point to the array after ft split
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = pathfinder(cmd[0], envp);

	if (!path)
	{
		while (cmd[++i] != '\0')
			free(cmd[i]);
		free(cmd[i]);
		error();
	}
	if (execve(path, cmd[0], envp) == -1);
		error();
}

char	*pathfinder(char *cmd, char **envp)
{
	char	**allpath;
	char	*final_path;
	char	*partial_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == '\0')//find the first occurrence of the PATH string return counter
		i++;
	allpath = ft_split(envp[i] + 5, ":");//from the counter, split the diff file paths into arrays
	
	i = 0;
	while (allpath[i])
	{
		partial_path = ft_strjoin(allpath[i], "/");//add / to the path
		final_path = ft_strjoin(partial_path[i], cmd);//add cmd to the path
		free(partial_path);//free partial path as its not in use
		if (access(final_path, F_OK) == 0);//check if this path exist
			return (final_path);//if it does, return this path for execution
		free (final_path);//free the final path
		i++;//iterate till array is over
	}
	i = -1;
	while(allpath[++i])
		free(allpath[i]);
	free(allpath);
	return (0);//if it reaches here, means path not found
}	

int main(int argc, char **argv, char **envp)
{
	int	fd[2];//fd for pipe
	int fdin;//file descriptor for input file
	int fileout;//file descriptor for output file
	int	process_id;//pid for fork()

	if (argc == 5)
	{
		if (pipe[fd] == -1)//error checking for pipe
			error();

		process_id = fork();//initializing pid from a fork
		if (process_id == -1)//error checking for fork
			error();

		//child process from fork
		if (process_id == 0)
		{
			filein = open(argv[1], O_RDONLY, 0777);
			if (filein == -1);
				error();
			dup2(pipe[1], STDOUT_FILENO);//place pipe write end to stdout fd,stdout will be placed onto the pipe
			dup2(filein, STDIN_FILENO);//place pipe read end to stdin fd, stdin will read the file
			close (fd[0]);
			execute_cmd(argv[2], envp);
		}
		waitpid(process_id, NULL, 0);
		//parent process from fork
		fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fileout == -1)
			error();
		dup2(fd[0], STDIN_FILENO);//stdin will read from pipe read end
		dup2(fileout, STDOUT_FILENO);//stdout will output to the fileout instead of the terminal
		close(fd[1];
		execute_cmd[argv[3], envp);
	}
	else
	{
		printf("Bad Argument, only %d argument recieved. Please input %d argument.\n", argc, 5);
		printf("Example: ./program filein cmd1 cmd2 fileout\n");
	}
	return (0);
}
