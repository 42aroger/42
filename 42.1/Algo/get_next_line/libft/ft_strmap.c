/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:40:15 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 16:40:17 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	size_t	i;

	dst = NULL;
	if (s && f)
	{
		dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (dst)
		{
			i = 0;
			while (s[i])
			{
				dst[i] = f(s[i]);
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (dst);
}
