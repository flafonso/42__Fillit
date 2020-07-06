/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:57:58 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/23 15:30:10 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;

	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = ft_strnew(len)))
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
