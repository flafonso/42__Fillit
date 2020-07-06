/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:35 by flafonso          #+#    #+#             */
/*   Updated: 2019/01/07 16:57:06 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
}

static int	ft_contact(t_struct p_struct, int w, int v)
{
	int		check;

	check = 0;
	if ((p_struct.x[w] == p_struct.x[v] - 1 &&
		p_struct.y[w] == p_struct.y[v])
		|| (p_struct.x[w] == p_struct.x[v] &&
		p_struct.y[w] == p_struct.y[v] - 1))
		check++;
	if ((p_struct.x[w] - 1 == p_struct.x[v] &&
		p_struct.y[w] == p_struct.y[v])
		|| (p_struct.x[w] == p_struct.x[v] &&
		p_struct.y[w] - 1 == p_struct.y[v]))
		check++;
	return (check);
}

static int	ft_counts(t_struct p_struct[27], int i)
{
	int		v;
	int		w;
	int		check;

	w = 0;
	check = 0;
	while (w < 4)
	{
		v = 0;
		while (v < 4)
		{
			if (v == 3 && v == w)
				break ;
			if (v == w)
				v++;
			check = check + ft_contact(p_struct[i], w, v);
			v++;
		}
		w++;
	}
	return (check);
}

static int	ft_touch(t_struct p_struct[27])
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (p_struct[i].stop != 10)
	{
		if (ft_counts(p_struct, i) != 6 && ft_counts(p_struct, i) != 8)
			return (0);
		i++;
	}
	return (1);
}

int			main(int ac, char **av)
{
	static t_struct	p_struct[27];
	int				fd;
	int				r;
	char			*tab;

	tab = NULL;
	r = 0;
	if (ac != 2)
	{
		ft_usage();
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (ft_malloc_struct(tab, fd, p_struct) == 1 && ft_touch(p_struct) == 1)
	{
		while (p_struct[r].stop != 10)
			r++;
		ft_mini_morback(
			ft_malloc_map(ft_sqrt_supp(r * 4)), p_struct, ft_sqrt_supp(r * 4));
	}
	else
		ft_putstr("error\n");
	close(fd);
	return (0);
}
