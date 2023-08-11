/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:32:14 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/07/28 16:48:37 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*remain_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain_str = read_line(fd, remain_str);
	if (!remain_str)
		return (NULL);
	return (remain_str);
}

char	*read_line(int fd, char	*remain_str)
{
	char		*buff;
	ssize_t		rd_char;

	rd_char = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr_gnl(remain_str) && rd_char > 0)
	{
		rd_char = read(fd, buff, BUFFER_SIZE);
		if (rd_char == -1 || !(ft_strlen_gnl(remain_str) + rd_char))
		{
			free(buff);
			free(remain_str);
			return (NULL);
		}
		remain_str = ft_join(buff, remain_str, rd_char);
	}
	free (buff);
	return (remain_str);
}
//
//char	*cut_str(char	*remain_str)
//{
//	int		i;
//	char	*r_str;
//
//	i = 0;
//	r_str = malloc(ft_size(remain_str) + 2);
//	if (!r_str)
//		return (NULL);
//	while (i < ft_size(remain_str))
//	{
//		r_str[i] = remain_str[i];
//		i++;
//	}
//	if (remain_str[i] == '\n')
//		r_str[i++] = '\n';
//	if (i <= ft_strlen_gnl(remain_str))
//		r_str[i] = 0;
//	return (r_str);
//}
//
//char	*clean_str(char	*remain_str)
//{
//	char	*cleaned_str;
//	int		i;
//
//	i = 0;
//	cleaned_str = malloc(ft_strlen_gnl(remain_str) - ft_size(remain_str) + 1);
//	if (!cleaned_str)
//		return (NULL);
//	while (i < ft_strlen_gnl(remain_str) - ft_size(remain_str))
//	{
//		cleaned_str[i] = remain_str[i + ft_strchr_gnl(remain_str) + 1];
//		i++;
//	}
//	free (remain_str);
//	if (cleaned_str[0] == 0)
//	{
//		free(cleaned_str);
//		return (NULL);
//	}
//	cleaned_str[i] = 0;
//	return (cleaned_str);
//}

/*
int	main(void)
{
	char *line;
	int i;
	int fd1;
	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
//	close(fd2);
//	close(fd3);
	return (0);
}
*/