/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:00:52 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/17 16:49:17 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*tmp;
	t_list	*tmp2;

	lst2 = NULL;
	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(lst2 = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	tmp2 = lst2;
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (tmp2);
		lst = lst->next;
		tmp = f(lst);
		if (!(lst2->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst2 = lst2->next;
	}
	return (tmp2);
}
