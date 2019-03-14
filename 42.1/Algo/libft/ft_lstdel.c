/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:52:48 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 18:52:50 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, t_list *new)
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = *alst;
		ft_lstdelone(&tmp, del);
		*alst = (*alst)->next;
	}
}
