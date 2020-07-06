/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:31 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/18 15:37:27 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_2;
	unsigned char	*dst_2;

	src_2 = (unsigned char*)src;
	dst_2 = (unsigned char*)dst;
	if (dst > src && len != 0)
	{
		len--;
		while (0 != len)
		{
			dst_2[len] = src_2[len];
			len--;
		}
		dst_2[len] = src_2[len];
		return (dst);
	}
	dst = ft_memcpy(dst, src, len);
	return (dst);
}
