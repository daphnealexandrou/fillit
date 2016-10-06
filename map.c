/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:33:10 by adenece           #+#    #+#             */
/*   Updated: 2016/04/01 11:10:48 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_square_root(int number)
{
	int		nb;
	int		count;
	int		summ;

	nb = 1;
	count = 0;
	summ = 0;
	while (summ < number)
	{
		if (nb % 2 != 0)
		{
			count = count + 1;
			summ = summ + nb;
		}
		nb++;
	}
	return (count);
}

char	**ft_map(int edge)
{
	char	**map;
	int		i;
	int		j;

	j = 0;
	if (!(map = (char **)malloc(sizeof(char *) * edge)))
		return (NULL);
	while (j != edge)
	{
		if (!(map[j] = (char *)malloc(sizeof(char) * edge)))
			return (NULL);
		i = 0;
		while (i != edge)
		{
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

void	print_map(char **map, int edge)
{
	int		i;
	int		j;

	i = 0;
	while (i != edge)
	{
		j = 0;
		while (j != edge)
		{
			ft_putchar(map[j][i]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
