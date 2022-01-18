/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:54:03 by alukongo          #+#    #+#             */
/*   Updated: 2022/01/18 17:58:37 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
			{
				return (i);
			}
			i++;
		}
	}
	return (NO_NEW_LINE);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;
	int			ret;
	char		buf[BUFFER_SIZE];

	str = NULL;
	ret = 1;
	if (BUFFER_SIZE > 0)
	{
		if (rest && *rest)
		{
			str = ft_strjoin(rest, 0, 0, ft_strlen_nl(rest));
			rest = free_addrs(rest, rest);
		}
		while (is_newline(str) == NO_NEW_LINE && ret > 0)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret <= 0)
				return (str);
			buf[ret] = '\0';
			str = ft_strjoin(str, buf, ft_strlen_nl(buf), ret);
		}
		buf[ret] = '\0';
		rest = free_addrs(rest, buf);
	}
	return (str);
}
