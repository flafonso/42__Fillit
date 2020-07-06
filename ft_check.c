/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:34:05 by flafonso          #+#    #+#             */
/*   Updated: 2019/01/07 18:21:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_tab_last_2(int c2, int c, int n, int p)
{
	if (c2 == 1)
		if (c != 4 || n != 4 || p != 12)
			return (0);
	if (c2 == 0)
		if (c != 4 || n != 5 || p != 12)
			return (0);
	return (1);
}

static int	ft_check_tab_last(char *tab, int c2)
{
	if (c2 == 1)
		if (tab[4] != '\n' || tab[9] != '\n' ||
			tab[14] != '\n' || tab[19] != '\n' || tab[20] != '\0')
			return (0);
	if (c2 == 0)
		if (tab[4] != '\n' || tab[9] != '\n' ||
			tab[14] != '\n' || tab[19] != '\n' || tab[20] != '\n')
			return (0);
	return (1);
}

static int	ft_check_tab(char *tab, int c2)
{
	int		i;
	int		c;
	int		n;
	int		p;

	i = 0;
	c = 0;
	n = 0;
	p = 0;
	while (tab[i])
	{
		if (tab[i] != '.' && tab[i] != '#' && tab[i] != '\n')
			return (0);
		if (tab[i] == '#')
			c++;
		if (tab[i] == '.')
			p++;
		if (tab[i] == '\n')
			n++;
		if (ft_check_tab_last(tab, c2) == 0)
			return (0);
		i++;
	}
	return (ft_check_tab_last_2(c2, c, n, p));
	return (1);
}

static int	ft_check(char *tab, int fd, t_struct p_struct[27])
{
	static int		t[3] = {1, 0, 0};

	while (t[0] != 0)
	{
		if ((tab = ft_strnew(22)) == NULL)
			return (0);
		t[0] = read(fd, tab, 21);
		tab[21] = '\0';
		if (t[0] == 0)
			break ;
		if (tab[20] == '\0')
			t[2]++;
		if (ft_check_tab(tab, t[2]) == 0)
		{
			free(tab);
			return (0);
		}
		ft_fill_struct(tab, p_struct, t[1]);
		t[1]++;
		free(tab);
	}
	free(tab);
	return (t[2] == 0) ? 0 : 1;
}

int			ft_malloc_struct(char *tab, int fd, t_struct p_struct[27])
{
	int		i;
	int		r;

	i = 0;
	while (i < 27)
	{
		r = 0;
		while (r < 4)
		{
			p_struct[i].x[r] = 0;
			p_struct[i].y[r] = 0;
			p_struct[i].taille = 0;
			r++;
		}
		p_struct[i].stop = 10;
		i++;
	}
	if (ft_check(tab, fd, p_struct) == 0)
		return (0);
	return (1);
}
