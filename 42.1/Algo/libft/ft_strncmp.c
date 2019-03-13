/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:37:38 by aroger            #+#    #+#             */
/*   Updated: 2019/03/13 16:37:41 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2 && n)
	{
		while (n-- > 0)
		{
			if (*s1 != *s2)
			{
				if (*(unsigned char *)s1 > *(unsigned char *)s2)
					return (1);
				else
					return (-1);
			}
			if (*s1 == '\0')
				return (0);
			s1++;
			s2++;
		}
	}
	return (0);
}
