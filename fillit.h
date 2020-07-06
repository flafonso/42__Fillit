/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:12:27 by flafonso          #+#    #+#             */
/*   Updated: 2019/01/07 15:23:59 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_struct
{
	int		x[4];
	int		y[4];
	int		taille;
	int		stop;
	char	c;
}				t_struct;

int				ft_mini_morback(char **map, t_struct p_struct[27], int taille);
int				ft_malloc_struct(char *tab, int fd, t_struct p_struct[27]);
void			ft_fill_struct(char *tab, t_struct p_struct[27], int r);
char			**ft_malloc_map(int taille);
char			**ft_ref_tab(char **tab, int taille);
void			ft_affiche_map(char **map, int taille);
void			ft_free_map(int taille, char ***map);
int				ft_check_2(int t_2);

#endif
