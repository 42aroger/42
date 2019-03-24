#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 15:19:18 by aroger            #+#    #+#              #
#    Updated: 2019/03/14 15:19:32 by aroger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SOURCES = ft_abs.c ft_itoa.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c\
			ft_striteri.c ft_strncpy.c ft_strtrim.c ft_atoi.c ft_lstadd.c\
			ft_memchr.c	ft_putendl.c ft_strclr.c ft_strjoin.c ft_strnequ.c\
			ft_tolower.c ft_bzero.c	ft_lstdel.c	ft_memcmp.c	ft_putendl_fd.c\
			ft_strcmp.c ft_strlcat.c ft_strnew.c ft_toupper.c ft_isalnum.c\
			ft_lstdelone.c ft_memcpy.c ft_putnbr.c ft_strcpy.c ft_strlen.c\
			ft_strnstr.c ft_isalpha.c ft_lstiter.c ft_memdel.c ft_putnbr_fd.c\
			ft_strdel.c ft_strmap.c	ft_strrchr.c ft_isascii.c ft_lstmap.c\
			ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c ft_strsplit.c\
			ft_isdigit.c ft_lstnew.c ft_memset.c ft_putstr_fd.c	ft_strequ.c\
			ft_strncat.c ft_strstr.c ft_isprint.c ft_memalloc.c	ft_putchar.c\
			ft_strcat.c	ft_striter.c ft_strncmp.c ft_strsub.c ft_strnlen.c

HEADERS = includes/libft.h

OBJECTS = $(subst .c,.o,$(SOURCES))

WFLAGS = -Wall -Werror -Wextra -I includes

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Make Libft :\033[1;32m DONE !\033[m"

$(OBJECTS): $(SOURCES) $(HEADERS)
	@gcc $(WFLAGS) -c $(SOURCES)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
