/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 16:15:36 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 17:53:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_count_words(char *str)
{
	int		i;
	int		nbr;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 && ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 &&\
			str[i] <= 122)))
			nbr = 1; 
		if (str[i] == 32)
		{
			i++;
			nbr++;
			while (str[i] == 32)
				i++;
		}
		else
			i++;
	}
	return (nbr);
}

char	*ft_strcat(char *s1, char *s2, int i, int size)
{
	char	ret[ft_strlen(s1) + ft_strlen(s2) + 2];
	char	*copy;

	ret[ft_strlen(s1) + ft_strlen(s2) + 2] = '\0';
	copy = ret;
	while (s1)
		*ret++ = *s1++;
	*ret++ = 32;
	while (size-- != 0)
		*ret++ = s2[i++];
	return (copy);
}

char	*ft_find_words(char *str, int size, int nbr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == 32)
			i++;
		else
		{
			while (str[i] && str[i++] != 32)
				j++;
			if (j == size)
				tmp = ft_strcat(tmp, str, (i - size), size);
		}
	}
	return (tmp);
}

void	ft_sort_size(int *array, char *str, int size)
{
	int		smaller;
	int		i;

	i = 0;
	while (i != size)
	{
		if (

}

void	ft_count_diff_size(char *str, int size)
{
	int		i;
	int		j;
	int		array[size];
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == 32)
			i++;
		else
		{
			while (str[i] && str[i++] != 32)
				j++;
			array[nbr++] = j;
		}
	}
}

void	ft_strsplit(char *str, int size)
{
	ft_count_diff_size(str, size);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1] != NULL)
	{
		if (ft_count_words(argv[1]) != 0)
			ft_strsplit(argv[1], ft_count_words(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
