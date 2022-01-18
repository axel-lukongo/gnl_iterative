/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:06:09 by alukongo          #+#    #+#             */
/*   Updated: 2022/01/18 18:06:12 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 10000000
# define NO_NEW_LINE -1
# define NEW_LINE 1
# include<unistd.h>
# include<stdlib.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<stdio.h>

char	*get_next_line(int fd);
int		ft_strlen_nl(char *s);
int		is_newline(char *str);
char	*ft_strjoin(char *s1, char *s2, int size, int ret);
char	*ft_strdup_r(char *s, char *src, char *ptr);
char	*free_addrs(char *rest, char *buf);
#endif // !GET_NEXT_LINE_H