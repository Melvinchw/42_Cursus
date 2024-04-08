/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:21:23 by mchua             #+#    #+#             */
/*   Updated: 2024/03/18 16:12:40 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**getpath(char **envp)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

char	*pathfinder(char *cmd, char **envp)
{
	char	**allpath;
	char	*final_path;
	char	*partial_path;
	int		i;

	i = 0;
	allpath = getpath(envp);
	if (!allpath)
		return (NULL);
	while (allpath[i])
	{
		partial_path = ft_strjoin(allpath[i], "/");
		final_path = ft_strjoin(partial_path, cmd);
		free(partial_path);
		if (!final_path)
			free(final_path);
		if (access(final_path, X_OK) == 0)
			return (final_path);
		free (final_path);
		i++;
	}
	free_array(allpath);
	return (NULL);
}

void	execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error();
	path = pathfinder(cmd[0], envp);
	if (!path)
	{
		free_array(cmd);
		error();
		exit(0);
	}
	if (execve(path, cmd, envp) == -1)
		error();
	free_array(cmd);
	exit(1);
}
