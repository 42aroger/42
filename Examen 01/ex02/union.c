/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 15:38:58 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 16:10:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_find(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2, int size)
{
	char	tmp[size];
	int		i;
	int		j;

	tmp[size] = '\0';
	j = 0;
	i = 0;
	while (s1[j])
	{
		if (!(ft_find(tmp, s1[j])))
			tmp[i++] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j])
	{
		if (!(ft_find(tmp, s2[j])))
			tmp[i++] = s2[j];
		j++; 
	}
	tmp[i] = '\0';
	write(1, &tmp, ft_strlen(tmp));
}

int		main(int argc, char **argv)
{
	int		size;

	size = 0;
	if (argc == 3 && argv[1] != NULL && argv[2] != NULL)
	{
		if (ft_strlen(argv[1]) > ft_strlen(argv[2]))
			size = ft_strlen(argv[1]);
		else
			size = ft_strlen(argv[2]);
		ft_union(argv[1], argv[2], size);
	}
	write(1, "\n", 1);
	return (0);
}
