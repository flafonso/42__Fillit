/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:44:32 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/08 11:06:10 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		i2;

	i = ft_strlen(s1);
	i2 = 0;
	while (i2 < n && s2[i2])
	{
		s1[i] = s2[i2];
		i++;
		i2++;
	}
	s1[i] = '\0';
	return (s1);
}
