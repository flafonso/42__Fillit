/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:38:37 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/12 18:14:44 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if (!(tab = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
