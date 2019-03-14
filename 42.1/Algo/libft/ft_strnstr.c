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

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;
	size_t	i;

	if (!haystack || !needle || !n)
		return (NULL);
	len = ft_strlen(needle);
	if (n < len)
		return (NULL);
	if (!needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i <= (n - len))
	{
		if (ft_strncmp(&haystack[i], needle, len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
