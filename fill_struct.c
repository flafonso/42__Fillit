/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 23:43:50 by flafonso          #+#    #+#             */
/*   Updated: 2019/01/07 14:53:57 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_2(int t_2)
{
	if (t_2 == 0)
		return (0);
	return (1);
}

static void	ft_moins_hein_y(t_struct p_struct[27], int r)
{
	int		i;
	int		c;

	i = 0;
	while (i < 4)
	{
		if (p_struct[r].y[i] < 0)
		{
			c = 0;
			while (c < 4)
			{
				p_struct[r].y[c]++;
				c++;
			}
		}
		i++;
	}
}

static void	ft_moins_hein_x(t_struct p_struct[27], int r)
{
	int		i;
	int		c;

	i = 0;
	while (i < 4)
	{
		if (p_struct[r].x[i] < 0)
		{
			c = 0;
			while (c < 4)
			{
				p_struct[r].x[c]++;
				c++;
			}
		}
		i++;
	}
}

static void	ft_check_neg_coor(t_struct p_struct[27], int r)
{
	ft_moins_hein_x(p_struct, r);
	ft_moins_hein_y(p_struct, r);
	p_struct[r].c = r + 65;
}

void		ft_fill_struct(char *tab, t_struct p_struct[27], int r)
{
	int		i;
	int		l;
	int		y;
	int		c;

	i = 0;
	l = 0;
	y = 0;
	c = -1;
	while (tab[i])
	{
		if (tab[i] == '#' && c == -1)
			c = i;
		if (tab[i] == '#')
		{
			p_struct[r].x[l] = (i % 5) - (c % 5);
			p_struct[r].y[l] = y;
			l++;
		}
		if (tab[i] == '\n' && c != -1)
			y++;
		i++;
	}
	p_struct[r].stop = 1;
	ft_check_neg_coor(p_struct, r);
}
