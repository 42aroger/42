/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <aroger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:59:39 by aroger            #+#    #+#             */
/*   Updated: 2019/04/01 15:59:54 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int        main(int argc, char **argv)
{
    char    *str;
    int        fd;

    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        while (get_next_line(fd, &str) > 0)
            ft_putendl(str);
        close (fd);
        free(str);
    }
    else
    {
        while (get_next_line(0, &str) > 0)
            ft_putendl(str);
    }
    return (0);
}
