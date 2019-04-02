/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:51:28 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 16:51:30 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	dst = NULL;
	if (s && f)
	{
		dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (dst)
		{
			i = 0;
			while (s[i])
			{
				dst[i] = f(i, s[i]);
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (dst);
}
