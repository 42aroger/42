/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:15:42 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 15:16:19 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (s)
	{
		str = (unsigned char *)s;
		while (n--)
		{
			if (*str == (unsigned char)c)
				return ((void *)str);
			str++;
		}
	}
	return (NULL);
}
