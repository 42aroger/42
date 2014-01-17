/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 14:46:13 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 15:14:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rotone(char *str)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i] + 1;
		if (str[i] == 'Z')
			write(1, "A", 1);
		else if (str[i] == 'z')
			write(1, "a", 1);
		else if (str[i] >= 65 && str[i] <= 90)
			write(1, &tmp, 1);
		else if (str[i] >= 97 && str[i] <= 122)
			write(1, &tmp, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1] != NULL)
		ft_rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
