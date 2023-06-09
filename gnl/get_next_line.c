/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:55:14 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 19:28:32 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_hasendl(int *index, char *staticbuff)
{
	int	i;

	i = 0;
	while (staticbuff[i])
	{
		if (staticbuff[i] == '\n')
		{
			*index = i;
			return (1);
		}
		i++;
	}
	*index = -42;
	return (0);
}

int	ft_checkstaticbuff(char **line, char **staticbuff)
{
	int		idx;
	char	*bufaux;

	if (!*staticbuff)
	{
		*line = 0;
		return (0);
	}
	else if (ft_hasendl(&idx, *staticbuff))
	{
		*line = ft_gnlsubstr(*staticbuff, 0, idx + 1);
		bufaux = ft_gnlsubstr(*staticbuff, idx + 1, ft_gnlstrlen(*staticbuff));
		free (*staticbuff);
		*staticbuff = ft_gnlstrdup(bufaux);
		free(bufaux);
		return (1);
	}
	*line = ft_gnlstrdup(*staticbuff);
	free(*staticbuff);
	*staticbuff = 0;
	return (0);
}

int	ft_readline(int fd, char *buffer, char **line, int *eol_idx)
{
	int		b_read;
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = 0;
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read == -1)
		return (-1);
	if (ft_hasendl(eol_idx, buffer))
		ft_gnlstrjoin(line, buffer, ((size_t)(*eol_idx)) + 1);
	else
	{
		ft_gnlstrjoin(line, buffer, ft_gnlstrlen(buffer));
		*eol_idx = -1;
	}
	return (b_read);
}

char	*ft_maneyador(int fd, char *buff, char **staticbuff)
{
	char	*line;
	int		bytesreaded;
	int		indexeol;

	if (ft_checkstaticbuff(&line, staticbuff))
		return (line);
	bytesreaded = 1;
	indexeol = -1;
	while (bytesreaded && indexeol == -1)
	{
		bytesreaded = ft_readline(fd, buff, &line, &indexeol);
		if (bytesreaded == -1 || !line)
		{
			free(line);
			return (0);
		}
	}
	free(*staticbuff);
	*staticbuff = 0;
	if (indexeol == -1)
		ft_gnlstrjoin(&line, buff, ft_gnlstrlen(buff));
	else
		*staticbuff = ft_gnlsubstr(buff,
				(size_t) indexeol + 1, ft_gnlstrlen(buff));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*staticbuffer[1024];
	char		*line;
	char		*buffer;

	line = 0;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_gnlcalloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_maneyador(fd, buffer, &staticbuffer[fd]);
	free(buffer);
	return (line);
}
