/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:38:02 by dalexand          #+#    #+#             */
/*   Updated: 2016/05/19 14:32:22 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_block
{
	unsigned char	x;
	unsigned char	y;
}					t_block;

typedef struct		s_tetriminos
{
	t_block			blocks[4];
	unsigned char	width;
	unsigned char	height;
	unsigned char	letter;

}					t_tetriminos;

typedef struct		s_tetriminos_array
{
	t_tetriminos	**array;
	int				size;
}					t_tetriminos_array;

unsigned char		min(unsigned char a, unsigned char b,
				unsigned char c, unsigned char d);
unsigned char		max(unsigned char a, unsigned char b,
				unsigned char c, unsigned char d);
int					touch(t_tetriminos *t, int i, int j);

t_tetriminos		*collect_blocks(char *str, int nbtetri);
void				crop(t_tetriminos *t);
t_tetriminos		*check_touch_blocks(t_tetriminos *t);
t_tetriminos		*parse(char *str, int nbtetri);
void				ft_error(void);
int					ft_read(int fd, t_tetriminos **result, int nbtetri,
		int *nb_read);
t_tetriminos_array	*ft_read_all(int fd);
int					solve(t_tetriminos_array *ta, unsigned char i,
				char **map, int nax_edge);
int					ft_square_root(int number);
char				**ft_map(int max_edge);
void				print_map(char **map, int max_edge);

#endif
