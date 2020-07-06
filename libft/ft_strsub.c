/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:43:26 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/13 08:57:22 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = len + 1;
	if (!(str = ft_memalloc(i)) || !(s))
		return (NULL);
	str = ft_strncpy(str, &s[start], len);
	return (str);
}
