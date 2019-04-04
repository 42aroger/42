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

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char		*fill_rest(char *str);
static void		join_strings(char **line, char *str);
static int		init_gnl(const int fd, char **line, char **rest);


int		get_next_line(const int fd, char **line)
{
	char		*str;
	static char	*rest = NULL;
	size_t		ret;
	int 		check;

	check = init_gnl(fd, line, &rest);
	if (check != 0)
		return (check);
	str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, str, BUFF_SIZE)) > 0 && !ft_strchr(str, '\n'))
	{
		str[ret] = '\0';
		join_strings(line, str);
	}
	if (ret > 0)
	{
		str[ret] = '\0';
		join_strings(line, str);
		rest = fill_rest(str);
	}
	free(str);
	if (ret > 1)
		ret = 1;
	else if (ret < 0)
		ret = -1;
	return (ret);
}

static char		*fill_rest(char *str)
{
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n')
		return (ft_strdup(++str));
	else
		return (NULL);
}

static void		join_strings(char **line, char *str)
{
	size_t		len;
	size_t		p;
	char		*tmp;

	p = 0;
	if (*line)
	{
		tmp = ft_strdup(*line);
		free(*line);
		p = ft_strlen(tmp);
		len = ft_strlen(str) + p;
		*line = (char*)malloc(sizeof(char) * (len + 1));
		ft_strcpy(*line, tmp);
		free(tmp);
	}
	else
	{
		len = ft_strlen(str);
		*line = (char*)malloc(sizeof(char) * (len + 1));
	}
	while (*str != '\0' && *str != '\n')
		(*line)[p++] = *str++;
	(*line)[p] = '\0';
}

static int		init_gnl(const int fd, char **line, char **rest)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (!line || read(fd, buf, 0) < 0 || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (*rest && ft_strchr(*rest, '\n'))
	{
		join_strings(line, *rest);
		tmp = *rest;
		*rest = fill_rest(tmp);
		free(tmp);
		return (1);
	}
	else if (*rest && !ft_strchr(*rest, '\n'))
	{
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (0);
}