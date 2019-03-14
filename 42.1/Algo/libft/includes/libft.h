/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:07:39 by aroger            #+#    #+#             */
/*   Updated: 2019/03/07 11:08:32 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar(char c);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putstr(char const *s);
char		*ft_strcat(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnew(size_t size);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		**ft_strsplit(char const *s, char c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strstr(const char *haystack, const char *needle);

#endif
