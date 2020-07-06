/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:01:23 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/19 13:32:47 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_trimspace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	else
		return (0);
}

static int		ft_lentrim(const char *s)
{
	size_t	i;
	size_t	max;
	size_t	len;

	i = 0;
	max = ft_strlen(s) - 1;
	while (ft_is_trimspace(s[max]) == 1 && max != 0)
		max--;
	while (ft_is_trimspace(s[i]) == 1 && s[i] != '\0')
		i++;
	len = max - i + 1;
	if (max == 0 || s[i] == '\0')
		return (1);
	return ((int)len);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = (size_t)ft_lentrim(s);
	if (!(trim = ft_strnew(len)))
		return (NULL);
	while (ft_is_trimspace(s[i]) == 1)
		i++;
	trim = ft_strncpy(trim, &s[i], len);
	return (trim);
}
