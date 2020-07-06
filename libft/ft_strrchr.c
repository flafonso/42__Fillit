/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:51 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/12 15:15:50 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == (char)c)
			return ((void*)&s[i]);
		i--;
	}
	if (s[i] == (char)c)
		return ((void*)&s[i]);
	return (NULL);
}
