/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <aroger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:38:17 by aroger            #+#    #+#             */
/*   Updated: 2019/03/12 15:55:59 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (dst && src)
	{
		i = 0;
		if (ft_strlen(src) == 0)
		{
			dst[i] = src[i];
			i++;
			while (dst[i] != '\0')
				dst[i++] = '\0';
			return (dst);
		}
		while (len-- > 0 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		if (len != (size_t)-1)
		{
			while (len-- > 0)
				dst[i++] = '\0';
		}
	}
	return (dst);
}
