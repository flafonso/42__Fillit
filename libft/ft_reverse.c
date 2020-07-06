/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:02:46 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/09 18:37:17 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str)
{
	char	c;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (str[l])
		l++;
	l--;
	while (i < l)
	{
		c = str[i];
		str[i] = str[l];
		str[l] = c;
		i++;
		l--;
	}
	return (str);
}
