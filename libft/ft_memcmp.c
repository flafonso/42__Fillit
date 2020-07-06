/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:25 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/12 14:02:15 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_2;
	unsigned char	*s2_2;

	s1_2 = (unsigned char*)s1;
	s2_2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1_2[i] != s2_2[i])
			return (s1_2[i] - s2_2[i]);
		i++;
	}
	return (0);
}
