/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:46:37 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/15 13:33:36 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	char		*s2;

	s2 = NULL;
	if (s && f)
	{
		i = ft_strlen(s);
		if (!(s2 = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		s2[i] = '\0';
		while (i > 0)
		{
			i--;
			s2[i] = f(s[i]);
		}
		i--;
		s2[i] = f(s[i]);
	}
	return (s2);
}
