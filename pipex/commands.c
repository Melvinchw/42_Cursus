/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:21:23 by mchua             #+#    #+#             */
/*   Updated: 2024/03/13 21:47:24 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*pathfinder(char *cmd, char **envp)
{
	char	**allpath;
	char	*final_path;
	char	*partial_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	allpath = ft_split(envp[i] + 5, ':');
	if (!allpath)
		return (NULL);
	i = 0;
	while (allpath[i])
	{
		partial_path = ft_strjoin(allpath[i], "/");
		final_path = ft_strjoin(partial_path, cmd);
		free(partial_path);
		if (!final_path)
			free(final_path);
		if (access(final_path, F_OK) == 0)
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
