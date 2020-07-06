/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:19 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/09 18:56:07 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_2;

	i = 0;
	s_2 = (unsigned char*)s;
	while (i < n)
	{
		if (s_2[i] == (unsigned char)c)
			return ((void *)&s_2[i]);
		i++;
	}
	return (NULL);
}
