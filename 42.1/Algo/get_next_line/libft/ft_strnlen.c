/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:02:32 by aroger            #+#    #+#             */
/*   Updated: 2019/03/16 12:03:41 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *str, size_t maxlen)
{
	size_t		i;

	i = 0;
	while (i < maxlen)
	{
		if (!*str)
			return (i);
		i++;
		str++;
	}
	return (i);
}
