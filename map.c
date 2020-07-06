/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:03:49 by flafonso          #+#    #+#             */
/*   Updated: 2018/12/12 15:40:21 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_affiche_map(char **map, int taille)
{
	int		i;
	int		j;

	i = 0;
	while (i < taille)
	{
		j = 0;
		while (j < taille)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**ft_ref_tab(char **tab, int taille)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < taille)
	{
		c = 0;
		while (c < taille)
		{
			tab[i][c] = '.';
			c++;
		}
		i++;
	}
	return (tab);
}

char	**ft_malloc_map(int taille)
{
	char	**tab;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * taille)))
		return (NULL);
	while (i < taille)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * taille)))
		{
			while (y < i)
			{
				free(tab[y]);
				y++;
			}
			return (NULL);
		}
		i++;
	}
	i = 0;
	return (ft_ref_tab(tab, taille));
}
