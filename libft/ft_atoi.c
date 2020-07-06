/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:48:42 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/09 17:40:58 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		s;
	int		nb;

	i = 0;
	s = 1;
	nb = 0;
	while (ft_isspace((int)str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit((int)str[i]) == 1)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * s);
}
