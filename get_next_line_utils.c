/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:50:16 by alukongo          #+#    #+#             */
/*   Updated: 2022/01/18 18:00:09 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strlen_nl(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while ((s[i] && s[i] != '\n'))
			i++;
		if (s[i] == '\n')
			i++;
	}
	return (i);
}

char	*ft_strdup_r(char *s, char *src, char *ptr)
{
	int		i;
	int		size;

	size = 0;
	i = -1;
	if (src && src[0])
	{
		while (src[size])
			size++;
		s = malloc(sizeof(char) * (size + 1));
		if (!(s))
		{
			free(s);
			return (0);
		}
		while (src[++i])
			s[i] = src[i];
		while (i < ft_strlen_nl(src) + 2)
			s[i++] = '\0';
		if (ft_strlen_nl(ptr))
			free(ptr);
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2, int size, int ret)
{
	char	*str;
	int		i;
	int		j;
	int		tes;

	tes = ret;
	j = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen_nl(s1) + size + 1));
	if (!str)
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && j < (ft_strlen_nl(s2) - 1))
	{
		str[i++] = s2[j++];
		while (s2[j] == '\n')
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*free_addrs(char *rest, char *buf)
{
	char	*ptr;

	ptr = rest;
	while (*buf != '\n' && *buf != '\0')
		buf++;
	while (*buf == '\n')
		buf++;
	if (!*buf)
	{
		free(ptr);
		ptr = NULL;
		rest = NULL;
	}
	else
		rest = ft_strdup_r(rest, buf, ptr);
	return (rest);
}
