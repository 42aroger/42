/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:53:30 by aroger            #+#    #+#             */
/*   Updated: 2019/03/14 18:53:31 by aroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*lstnew;

	lstnew = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!lstnew)
			lstnew = tmp;
		else
		{
			tmp->next = lstnew;
			lstnew = tmp;
		}
		lst = lst->next;
	}
	return (lstnew);
}
