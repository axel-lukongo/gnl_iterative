/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:19:07 by alukongo          #+#    #+#             */
/*   Updated: 2022/01/27 18:05:08 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_the_line(char **line, int size_line)
{
	char	*s;

	if (!*line || !**line)
	{
		if (*line)
		{
			free(*line);
			*line = (NULL);
		}
		return (NULL);
	}
	if (size_line == -1)
		size_line = ft_strlen(*line);
	s = ft_substr(*line, 0, size_line + 1, 0);
	*line = ft_substr(*line, size_line + 1, ft_strlen(*line), 1);
	return (s);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*line[1024];
	int			size_line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	size_line = is_newline(line[fd]);
	if (size_line == -1)
		ret = read(fd, buf, BUFFER_SIZE);
	while (size_line == -1 && ret > 0)
	{
		buf[ret] = '\0';
		line[fd] = ft_strjoin(line[fd], buf);
		size_line = is_newline(line[fd]);
		if (size_line == -1)
			ret = read(fd, buf, BUFFER_SIZE);
	}
	return (get_the_line(&line[fd], size_line));
}
