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

	if (init_gnl(fd, line, &rest) != 0)
		return (init_gnl(fd, line, &rest));
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
		len = ft_strlen(str) + ft_strlen(tmp);
		*line = (char*)malloc(sizeof(char) * (len + 1));
		ft_strcpy(*line, tmp);
		p = ft_strlen(tmp);
		free(tmp);
	}
	else
	{
		len = ft_strlen(str);
		*line = (char*)malloc(sizeof(char) * (len + 1));
	}
	ft_putstr(str);
	while (str[p] != '\0' && str[p] != '\n')
	{
		ft_putnbr(p);
		//ft_putchar(*str);
		ft_putchar('a');
		ft_putchar((char)str[p]);
		ft_putchar('b');
		*line[p] = (char)str[p];
		p++;
	}
	*line[p] = '\0';
}

static int		init_gnl(const int fd, char **line, char **rest)
{
	char		*tmp;

	if (!line)
		line = (char**)malloc(sizeof(char *));
	if (*line)
		free(line);
	*line = NULL;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
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