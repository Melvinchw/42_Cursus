/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:32:32 by mchua             #+#    #+#             */
/*   Updated: 2023/10/19 22:08:55 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*rm_usedline(char *mainbuff)
{
	char			*n_mainbuff;
	char			*newline_add;
	unsigned int	line_len;

	newline_add = ft_strchr(mainbuff, '\n');
	if (!newline_add)
	{
		n_mainbuff = NULL;
		return (ft_free(&mainbuff));
	}
	else
		line_len = (newline_add - mainbuff) + 1;
	if (!mainbuff[line_len])
		return (ft_free(&mainbuff));
	n_mainbuff = ft_substr(mainbuff, line_len, ft_strlen(mainbuff) - line_len);
	ft_free(&mainbuff);
	if (!n_mainbuff)
		return (NULL);
	return (n_mainbuff);
}

static char	*extract_line(char *mainbuff)
{
	char	*ptr;
	char	*line;
	int		len;

	ptr = ft_strchr(mainbuff, '\n');
	len = (ptr - mainbuff) + 1;
	line = ft_substr(mainbuff, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_tempbuff(int fd, char *mainbuff)
{
	char	*tempbuff;
	int		read_count;

	tempbuff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tempbuff)
		return (ft_free(&mainbuff));
	tempbuff[0] = '\0';
	read_count = 1;
	while (read_count > 0 && !ft_strchr(tempbuff, '\n'))
	{
		read_count = read(fd, tempbuff, BUFFER_SIZE);
		if (read_count > 0)
		{
			tempbuff[read_count] = '\0';
			mainbuff = ft_strjoin(mainbuff, tempbuff);
		}
	}
	free(tempbuff);
	if (read_count == -1)
		return (ft_free(&mainbuff));
	return (mainbuff);
}

char	*get_next_line(int fd)
{
	static char	*mainbuff = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((mainbuff && !ft_strchr(mainbuff, '\n')) || !mainbuff)
		mainbuff = read_tempbuff(fd, mainbuff);
	if (!mainbuff)
		return (NULL);
	line = extract_line(mainbuff);
	if (!line)
		return (ft_free(&mainbuff));
	mainbuff = rm_usedline(mainbuff);
	return (line);
}
/*
int main(void){
 int fd; int i;
 fd = open("text.txt", O_RDONLY);
 i = 0;
 while (i < 40) {
  printf("%s", get_next_line(fd));  i++;
 } return (0);
}
*/
