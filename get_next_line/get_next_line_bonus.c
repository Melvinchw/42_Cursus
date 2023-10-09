/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:31:00 by mchua             #+#    #+#             */
/*   Updated: 2023/10/09 21:31:03 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*clean_buffer(char *storage)
{
	char			*new_storage;
	char			*ptr;
	unsigned int	len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
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
	static char	*storage[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if ((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd])
		storage[fd] = read_buffer(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = new_line(storage[fd]);
	if (!line)
		return (ft_free(&storage[fd]));
	storage[fd] = clean_buffer(storage[fd]);
	return (line);
}
