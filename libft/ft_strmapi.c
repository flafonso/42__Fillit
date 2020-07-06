/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:05:13 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/18 16:24:35 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	s2 = NULL;
	if (s && f)
	{
		i = ft_strlen(s);
		if (!(s2 = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			s2[i] = f(i, s[i]);
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
