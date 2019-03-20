/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:23:10 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 12:23:12 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = NULL;
	if (s && ft_strlen(s) >= (len + start))
	{
		sub = (char*)malloc(sizeof(char) * (len + 1));
		if (sub)
		{
			i = 0;
			while (len--)
				sub[i++] = s[start++];
			sub[i] = '\0';
		}
	}
	return (sub);
}
