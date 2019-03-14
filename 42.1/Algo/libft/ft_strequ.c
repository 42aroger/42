/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:11:54 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 18:11:55 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (ft_tolower((int)*s1) == ft_tolower((int)*s2))
		{
			if (*s1 == '\0')
				return (1);
			s1++;
			s2++;
		}
	}
	return (0);
}