/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:53:32 by dalexand          #+#    #+#             */
/*   Updated: 2016/03/24 16:44:21 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	min(unsigned char a, unsigned char b, unsigned char c,
			unsigned char d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	if (b <= c && b <= d)
		return (b);
	if (c <= d)
		return (c);
	return (d);
}

unsigned char	max(unsigned char a, unsigned char b, unsigned char c,
		unsigned char d)
{
	if (a >= b && a >= c && a >= d)
		return (a);
	if (b >= c && b >= d)
		return (b);
	if (c >= d)
		return (c);
	return (d);
}

int				touch(t_tetriminos *t, int i, int j)
{
	return ((t->blocks[i].x - t->blocks[j].x == 1
					&& t->blocks[i].y == t->blocks[j].y) ||
					(t->blocks[i].x - t->blocks[j].x == -1
					&& t->blocks[i].y == t->blocks[j].y) ||
					(t->blocks[i].y - t->blocks[j].y == 1
					&& t->blocks[i].x == t->blocks[j].x) ||
					(t->blocks[i].y - t->blocks[j].y == -1
					&& t->blocks[i].x == t->blocks[j].x));
}
