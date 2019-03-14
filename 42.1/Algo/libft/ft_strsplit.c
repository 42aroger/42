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

static int	ft_string_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		nbrwords;
	int		index;

	if (s)
	{
		index = 0;
		nbrwords = ft_count_words(s, c);
		array = (char**)malloc(sizeof(char *) * (nbrwords + 1));
		if (!array)
			return (NULL);
		while (nbrwords--)
		{
			while (*s != '\0' && *s != c)
				s++;
			array[index] = ft_strsub(s, 0, ft_string_len(s, c));
			if (array[index] == NULL)
				return (NULL);
			s = s + ft_string_len(s, c);
			index++;
		}
		array[index] = NULL;
		return (array);
	}
	return (NULL);
}
