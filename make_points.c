/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:21:48 by dpozinen          #+#    #+#             */
/*   Updated: 2018/04/23 18:21:48 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**place(t_filler *fil, int i, int j, int c)
{
	int **map;
	int map_h;
	int map_w;

	map_h = fil->map_h;
	map_w = fil->map_w;
	map = fil->map;
	if (i - 1 >= 0)
	{
		(j - 1 >= 0 && map[i - 1][j - 1] == 0) ? map[i - 1][j - 1] = c : 0;
		map[i - 1][j] == 0 ? map[i - 1][j] = c : 0;
		j + 1 < map_w && map[i - 1][j + 1] == 0 ? map[i - 1][j + 1] = c : 0;
	}
	if (i + 1 < map_h)
	{
		(j - 1 >= 0 && map[i + 1][j - 1] == 0) ? map[i + 1][j - 1] = c : 0;
		map[i + 1][j] == 0 ? map[i + 1][j] = c : 0;
		j + 1 < map_w && map[i + 1][j + 1] == 0 ? map[i + 1][j + 1] = c : 0;
	}
	(j + 1 < map_w && map[i][j + 1] == 0) ? map[i][j + 1] = c : 0;
	(j - 1 >= 0 && map[i][j - 1] == 0) ? map[i][j - 1] = c : 0;
	return (map);
}

int		**place_me(t_filler *fil)
{
	int i;
	int j;

	i = 0;
	while (i < fil->map_h)
	{
		j = 0;
		while (j < fil->map_w && fil->char_map[i][j + 4])
		{
			if (fil->char_map[i][j + 4] == fil->c)
				fil->map[i][j] = -2;
			j++;
		}
		i++;
	}
	return (fil->map);
}

int		**make_points(t_filler *fil)
{
	int i;
	int j;
	int c;
	int f;

	c = 1;
	f = 1;
	while (f == 1)
	{
		f = 0;
		i = 0;
		while (i < fil->map_h)
		{
			j = 0;
			while (j < fil->map_w)
			{
				fil->map[i][j] == c ? fil->map = place(fil, i, j, c + 1) : 0;
				fil->map[i][j] == 0 ? f = 1 : 0;
				j++;
			}
			i++;
		}
		c++;
	}
	return (fil->map = place_me(fil));
}
