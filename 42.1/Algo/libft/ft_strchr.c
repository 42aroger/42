/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:52:20 by aroger            #+#    #+#             */
/*   Updated: 2019/03/13 14:52:27 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s != (char)c || *s)
			*s++;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
