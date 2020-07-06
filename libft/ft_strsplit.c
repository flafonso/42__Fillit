/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:22:25 by flafonso          #+#    #+#             */
/*   Updated: 2018/11/18 14:55:24 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_skip_spaces(char const *str, int i, char c)
{
	while (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}

static int		ft_count_char(char const *str, int i, char c)
{
	int		nb_char;

	nb_char = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		nb_char++;
	}
	return (nb_char);
}

static int		ft_count_nb_word(char const *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		i = ft_skip_spaces(str, i, c);
	}
	return (word);
}

static char		**faux_strsplit(char const *s, char c)
{
	char			**dest;
	int				len;
	int				i;
	int				nb_char;
	unsigned int	i_s;

	i = 0;
	i_s = 0;
	nb_char = 0;
	len = ft_count_nb_word(s, c);
	if (!(dest = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (i_s == 0 && s[0] == c)
			i_s = ft_skip_spaces(s, i_s, c);
		nb_char = ft_count_char(s, i_s, c);
		if (!(dest[i] = ft_strsub(s, i_s, nb_char)))
			return (NULL);
		i++;
		i_s = ft_skip_spaces(s, nb_char + i_s, c);
	}
	dest[i] = NULL;
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (faux_strsplit(s, c));
}
