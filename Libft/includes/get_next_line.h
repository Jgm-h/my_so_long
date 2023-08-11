/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorcom- <jmorcom-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:42:36 by jmorcom-          #+#    #+#             */
/*   Updated: 2023/07/28 16:48:41 by jmorcom-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_line(int fd, char	*remain_str);
char	*clean_str(char	*remain_str);
char	*cut_str(char	*remain_str);
char	*ft_join(char	*buff, char	*remain_str, ssize_t rd_char);

int		ft_strlen_gnl(const char *s);
int		ft_strchr_gnl(const char *s);
int		ft_size(const char	*s);

#endif