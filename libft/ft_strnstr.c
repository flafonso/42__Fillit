/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:47 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/12 17:23:36 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len2;

	i = 0;
	len2 = (size_t)ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (!ft_strncmp(&haystack[i], needle, len2))
		{
			if (len - i < len2)
				return (NULL);
			return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
