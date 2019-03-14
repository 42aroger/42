/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:57:01 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 16:57:03 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != ' ' && s[k] != '\n' && s[k] != '\t')
		{
			k++;
			j = k;
		}
		else
			k++;
	}
	if (j == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, (unsigned int)i, j - i + 1));
}
