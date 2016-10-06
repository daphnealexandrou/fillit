/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:08:49 by dalexand          #+#    #+#             */
/*   Updated: 2016/05/26 12:43:16 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_char(int i, int block_count, char c)
{
	if (c == '#' && i % 5 != 4 && block_count < 4)
		return (1);
	if (c == '\n' && i % 5 == 4)
		return (1);
	if (c == '.' && i % 5 != 4)
		return (1);
	if (c == '\0' && i == 20)
		return (1);
	return (0);
}

t_tetriminos	*collect_blocks(char *str, int nbtetri)
{
	t_tetriminos	*result;
	int				block_count;
	int				i;

	block_count = 0;
	i = 0;
	if (!(result = (t_tetriminos *)malloc(sizeof(t_tetriminos))))
		return (NULL);
	while (i <= 20 && check_char(i, block_count, str[i]))
	{
		if (str[i] == '#')
		{
			result->blocks[block_count] = (t_block) {.x = i % 5, .y = i / 5};
			block_count = block_count + 1;
		}
		i++;
	}
	result->letter = nbtetri + 'A';
	if (i == 21 && block_count == 4)
		return (result);
	free(result);
	return (NULL);
}

void			crop(t_tetriminos *t)
{
	unsigned char	x_min;
	unsigned char	x_max;
	unsigned char	y_min;
	unsigned char	y_max;

	if (!t)
		return ;
	x_min = min(t->blocks[0].x, t->blocks[1].x, t->blocks[2].x, t->blocks[3].x);
	x_max = max(t->blocks[0].x, t->blocks[1].x, t->blocks[2].x, t->blocks[3].x);
	y_min = min(t->blocks[0].y, t->blocks[1].y, t->blocks[2].y, t->blocks[3].y);
	y_max = max(t->blocks[0].y, t->blocks[1].y, t->blocks[2].y, t->blocks[3].y);
	t->blocks[0].x -= x_min;
	t->blocks[0].y -= y_min;
	t->blocks[1].x -= x_min;
	t->blocks[1].y -= y_min;
	t->blocks[2].x -= x_min;
	t->blocks[2].y -= y_min;
	t->blocks[3].x -= x_min;
	t->blocks[3].y -= y_min;
	t->width = x_max - x_min + 1;
	t->height = y_max - y_min + 1;
}

t_tetriminos	*check_touch_blocks(t_tetriminos *t)
{
	int		touched[4];
	int		i;

	if (!t)
		return (NULL);
	touched[0] = 1;
	touched[1] = 0;
	touched[2] = 0;
	touched[3] = 0;
	i = 0;
	while (i < 48)
	{
		if (touched[(i / 4) % 4] && touch(t, (i / 4) % 4, i % 4))
			touched[i % 4] = 1;
		i++;
	}
	if (touched[1] && touched[2] && touched[3])
		return (t);
	free(t);
	return (NULL);
}

t_tetriminos	*parse(char *str, int nbtetri)
{
	t_tetriminos	*result;

	result = collect_blocks(str, nbtetri);
	crop(result);
	result = check_touch_blocks(result);
	if (result == NULL)
		ft_error();
	return (result);
}
