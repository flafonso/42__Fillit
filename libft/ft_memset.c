/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:44:42 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/09 18:56:48 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s2;

	s2 = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		s2[i] = (unsigned char)c;
		i++;
	}
	return (s2);
}
