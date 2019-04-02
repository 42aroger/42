/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:02:19 by aroger            #+#    #+#             */
/*   Updated: 2019/03/13 17:05:02 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			i++;
		}
		else if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (i);
}

static char	**ft_fill(char **array, char const *s, char c)
{
	size_t	index;
	size_t	p;
	size_t	start;

	index = 0;
	p = 0;
	while (s[p] != '\0')
	{
		if (s[p] == c)
			p++;
		else if (s[p] != c)
		{
			start = p;
			while (s[p] != c && s[p])
				p++;
			array[index] = ft_strsub(s, start, (p - start));
			index++;
		}
	}
	array[index] = NULL;
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	nbrwords;

	if (s)
	{
		nbrwords = ft_count_words(s, c);
		array = (char**)malloc(sizeof(char *) * (nbrwords + 1));
		if (!array)
			return (NULL);
		array = ft_fill(array, s, c);
		return (array);
	}
	return (NULL);
}
