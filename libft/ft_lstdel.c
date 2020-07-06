/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:35:32 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/19 13:59:40 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !del)
		return ;
	while (*alst != NULL)
	{
		tmp = (*alst);
		del((tmp)->content, (tmp)->content_size);
		(*alst) = (*alst)->next;
		free(tmp);
	}
	tmp = NULL;
}
