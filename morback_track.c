/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morback_track.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:58:06 by flafonso          #+#    #+#             */
/*   Updated: 2019/01/07 17:45:49 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_remove_piesse(char **map, int taille, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < taille)
	{
		y = 0;
		while (y < taille)
		{
			if (map[x][y] == i + 65)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}

static char	**pose_piesse(char **map, t_struct p_struct, int taille, int pos)
{
	int		x;
	int		y;
	int		w;

	w = 0;
	while (w < 4)
	{
		x = (pos % taille) + p_struct.x[w];
		y = (pos / taille) + p_struct.y[w];
		map[y][x] = p_struct.c;
		w++;
	}
	return (map);
}

static int	verif_piesse(char **map, t_struct p_struct, int taille, int pos)
{
	int		x;
	int		y;
	int		w;

	w = 0;
	if (pos >= taille * taille)
		return (0);
	while (w < 4)
	{
		x = (pos % taille) + p_struct.x[w];
		y = (pos / taille) + p_struct.y[w];
		if (x >= taille || y >= taille)
			return (0);
		if (map[y][x] != '.')
			return (0);
		w++;
	}
	return (1);
}

static int	ft_morback_track(char **map, t_struct p_struct[27], int pos, int i)
{
	if (map == NULL)
		return (110);
	if (p_struct[i].stop == 10)
		return (1);
	while (pos < p_struct[0].taille * p_struct[0].taille)
	{
		if (verif_piesse(map, p_struct[i], p_struct[0].taille, pos) == 1)
		{
			map = pose_piesse(map, p_struct[i], p_struct[0].taille, pos);
			if (ft_morback_track(map, p_struct, 0, i + 1) == 1)
				return (1);
			map = ft_remove_piesse(map, p_struct[0].taille, i);
		}
		pos++;
	}
	return (0);
}

int			ft_mini_morback(char **map, t_struct p_struct[27], int taille)
{
	int		i;

	if (map == NULL)
		return (0);
	p_struct[0].taille = taille;
	while (ft_morback_track(map, p_struct, 0, 0) != 1)
	{
		i = -1;
		while (++i < p_struct[0].taille)
			free(map[i]);
		free(map);
		if (ft_morback_track(map, p_struct, 0, 0) == 110)
		{
			ft_putstr("error\n");
			return (0);
		}
		p_struct[0].taille++;
		map = ft_malloc_map(p_struct[0].taille);
	}
	ft_affiche_map(map, p_struct[0].taille);
	i = -1;
	while (++i < p_struct[0].taille)
		free(map[i]);
	free(map);
	return (0);
}
