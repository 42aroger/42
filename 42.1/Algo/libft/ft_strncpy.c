/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <aroger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:38:17 by aroger            #+#    #+#             */
/*   Updated: 2019/03/23 15:28:26 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (len-- > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (len != (size_t)-1)
	{
		while (len-- != (size_t)-1)
			dst[i++] = '\0';
	}
	return (dst);
}
