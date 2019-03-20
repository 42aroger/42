/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <aroger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:23:07 by aroger            #+#    #+#             */
/*   Updated: 2019/03/12 16:27:04 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str;
	size_t	size;

	str = s1;
	s1 += ft_strlen(s1);
	size = ft_strnlen(s2, n);
	s1[size] = '\0';
	ft_memcpy(s1, s2, size);
	return (str);
}
