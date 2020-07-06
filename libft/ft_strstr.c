/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:55 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/12 16:16:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	size_t	len;

	i = 0;
	len = (size_t)ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (!ft_strncmp(&haystack[i], needle, len))
		{
			return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
