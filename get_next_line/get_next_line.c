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

static char	*remove_buffer(char *storage)
{
	char			*new_buffer;
	char			*newline_add;
	unsigned int	line_len;

	newline_add = ft_strchr(storage, '\n');
	if (!newline_add)
	{
		new_buffer = NULL;
		return (ft_free(&storage));
	}
	else
		line_len = (newline_add - storage) + 1;
	if (!storage[line_len])
		return (ft_free(&storage));
	new_buffer = ft_substr(storage, line_len, ft_strlen(storage) - line_len);
	ft_free(&storage);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

static char	*new_line(char *storage)
{
	char	*ptr;
	char	*line;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_buffer(int fd, char *storage)
{
	char	*buffer;
	int		index_readed;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	index_readed = 1;
	while (index_readed > 0 && !ft_strchr(buffer, '\n'))
	{
		index_readed = read(fd, buffer, BUFFER_SIZE);
		if (index_readed > 0)
		{
			buffer[index_readed] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (index_readed == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = read_buffer(fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = remove_buffer(storage);
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
