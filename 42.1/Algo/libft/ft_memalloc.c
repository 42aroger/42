/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:07:03 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 16:07:04 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*new;
	size_t			i;

	new = NULL;
	new = (unsigned char *)malloc(size);
	if (new)
	{
		i = 0;
		while (size--)
			new[i++] = 0;
	}
	return ((void *)new);
}
