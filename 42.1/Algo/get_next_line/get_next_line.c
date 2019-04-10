/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <aroger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:38:04 by aroger            #+#    #+#             */
/*   Updated: 2019/04/01 12:38:09 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int		ft_new_line(char **gnl, char **line, int fd, int ret)
{
	char		*tmp;
	int			len;

	len = 0;
	while (gnl[fd][len] != '\n' && gnl[fd][len] != '\0')
		len++;
	if (gnl[fd][len] == '\n')
	{
		*line = ft_strsub(gnl[fd], 0, len);
		tmp = ft_strdup(gnl[fd] + len + 1);
		free(gnl[fd]);
		gnl[fd] = tmp;
		if (gnl[fd][0] == '\0')
			ft_strdel(&gnl[fd]);
	}
	else if (gnl[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(gnl[fd]);
		ft_strdel(&gnl[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*gnl[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!gnl[fd])
			gnl[fd] = ft_strnew(1);
		tmp = ft_strjoin(gnl[fd], buff);
		free(gnl[fd]);
		gnl[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!gnl[fd] || gnl[fd][0] == '\0'))
		return (0);
	return (ft_new_line(gnl, line, fd, ret));
}
