/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:25:06 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 16:25:08 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	if (!*s2)
		return ((char *)s1);
	len = ft_strlen(s2);
	i = 0;
	while (s1[i] && i <= (n - len))
	{
		if (ft_strncmp(&s1[i], s2, len) == 0 && (i + len <= n))
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
