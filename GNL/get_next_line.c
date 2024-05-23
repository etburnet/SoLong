/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:14:01 by eburnet           #+#    #+#             */
/*   Updated: 2024/02/16 10:48:36 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *storage, char *buff)
{
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buff[bytes_read] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	return (storage);
}

char	*read_next_line(char *line)
{
	char	*storage;
	int		pos;
	int		line_len;

	line_len = ft_strlen(line);
	pos = 0;
	while (line[pos] != '\n' && line[pos] != '\0')
		pos++;
	if (pos == 0 && line[pos] != '\n')
		return (NULL);
	storage = ft_substr(line, pos + 1, line_len - pos - 1);
	if (line[pos] != '\0')
		line[pos + 1] = '\0';
	if (storage == NULL)
	{
		free(line);
		return (NULL);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = ft_read(fd, storage, buff);
	free(buff);
	if (line == NULL)
	{
		return (NULL);
	}
	storage = read_next_line(line);
	if (storage == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;

	fd = open("42_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
} */
