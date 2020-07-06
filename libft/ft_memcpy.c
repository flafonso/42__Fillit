/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:28 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/09 18:56:32 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_2;
	unsigned char	*dst_2;

	src_2 = (unsigned char*)src;
	dst_2 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dst_2[i] = src_2[i];
		i++;
	}
	return (dst);
}
