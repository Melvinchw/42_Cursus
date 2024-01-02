/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:58:21 by mchua             #+#    #+#             */
/*   Updated: 2024/01/02 19:35:42 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	error()
{
	perror("Error executing,goodbye bitch\n Error: ");
}

char	*pathfinder(char *cmd, char **envp)
{
	char	**allpath;
	char	*final_path;
	char	*partial_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)//find the first occurrence of the PATH string return counter
		i++;
	allpath = ft_split(envp[i] + 5, ':');//from the counter, split the diff file paths into arrays
	
	i = 0;
	while (allpath[i])
	{
		partial_path = ft_strjoin(allpath[i], "/");//add / to the path
		final_path = ft_strjoin(&partial_path[i], cmd);//add cmd to the path
		free(partial_path);//free partial path as its not in use
		if (access(final_path, F_OK) == 0)//check if this path exist
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
		while (cmd[++i] != 0)
			free(cmd[i]);
		free(cmd[i]);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

void	child_process(char **argv, char **envp, int *fd)
{
	int fdin;
	
	fdin = open(argv[1], O_RDONLY, 0777);//open as read only as the point of this file is to take the content and execute a command. Nothing is to be done to this file

	if (fdin == -1)
		error();
	dup2(fdin, STDIN_FILENO);//duplicate this file and replace this with the STDIN, which is the read portion. This way when program rea, it will read from the file
	dup2(fd[1], STDOUT_FILENO);//duplicate this write end of pipe, and replace with STDOUT so that output will be passed to the pipe
	close (fd[0]);//close the end of pipe that is not in use
	execute_cmd(argv[2],envp);//pass the 2nd argument which is the command into this function along with the list of environment variables
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);//read up on the flags. Open as writeoonly to input the output
	if (fdout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);//duplicate the read end of pipe and duplicate with STDIN so program will read value from child process that was output into the write end of pipe.
	dup2(fdout, STDOUT_FILENO);//duplicate the file fd and replace with STDOUT so any output will be written into the fdout file.
	close (fd[1]);//close the write end of pipe that is not in use
	execute_cmd(argv[3], envp);//pass in the 2nd command which is the 3rd argument along with the list of environment variables
}	

int main(int argc, char **argv, char **envp)
{
	int	fd[2];//fd for pipe
	//int fdin;//file descriptor for input file
	//int fileout;//file descriptor for output file
	int	process_id;//pid for fork()

	if (argc == 5)
	{
		if (pipe(fd) == -1)//error checking for pipe
			error();

		process_id = fork();//initializing pid from a fork
		if (process_id == -1)//error checking for fork
			error();

		//child process from fork
		if (process_id == 0)
			child_process(argv, envp, fd);//pass in the arguments, environmental variables and pipe fds)
		waitpid(process_id, NULL, 0);//process id of child, don't need the status of process, 0 means work as normal wait function. Read up on waitpid vs wait
		parent_process(argv, envp, fd);
	}
	else
	{
		printf("Bad Argument, only %d argument recieved. Please input %d argument.\n", argc, 5);
		printf("Example: ./program filein cmd1 cmd2 fileout\n");
	}
	return (0);
}
