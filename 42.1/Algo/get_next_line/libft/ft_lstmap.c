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
	t_list	*tmpresult;
	t_list	*tmplist;
	t_list	*flist;

	if (!lst || !f)
		return (NULL);
	tmplist = f(lst);
	flist = ft_lstnew(tmplist->content, tmplist->content_size);
	if (flist)
	{
		tmpresult = flist;
		lst = lst->next;
		while (lst != NULL)
		{
			tmplist = (*f)(lst);
			tmpresult->next = ft_lstnew(tmplist->content,\
				tmplist->content_size);
			if (!tmpresult->next)
				return (NULL);
			tmpresult = tmpresult->next;
			lst = lst->next;
		}
	}
	return (flist);
}
