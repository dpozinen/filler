/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:46:06 by dpozinen          #+#    #+#             */
/*   Updated: 2018/04/23 18:46:07 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_points(t_filler *fil, int i, int j)
{
	int t_j;
	int t_i;
	int m_j;
	int c;

	c = 0;
	t_i = 0;
	while (i < fil->map_h && t_i < fil->token_h)
	{
		m_j = j;
		t_j = 0;
		while (m_j < fil->map_w && t_j < fil->token_w)
		{
			if (fil->token[t_i][t_j] == -2)
				c += fil->map[i][m_j];
			m_j++;
			t_j++;
		}
		i++;
		t_i++;
	}
	if (c >= fil->min)
		return (0);
	fil->min = c;
	return (1);
}

int		check_spot(t_filler *fil, int i, int j)
{
	int t_j;
	int t_i;
	int m_j;
	int c;

	c = 0;
	t_i = 0;
	while (i < fil->map_h && t_i < fil->token_h)
	{
		m_j = j;
		t_j = 0;
		while (m_j < fil->map_w && t_j < fil->token_w)
		{
			if (fil->map[i][m_j] == 1 && fil->token[t_i][t_j] == -2)
				return (0);
			(fil->map[i][m_j] == -2 && fil->token[t_i][t_j] == -2) ? c++ : 0;
			m_j++;
			t_j++;
		}
		i++;
		t_i++;
	}
	return (c == 1 ? 1 : 0);
}

int		*place_token(t_filler *fil)
{
	int i;
	int j;

	i = 0;
	fil->min = INT_MAX;
	while (i <= fil->map_h - fil->token_h)
	{
		j = 0;
		while (j <= fil->map_w - fil->token_w)
		{
			if (check_spot(fil, i, j) && count_points(fil, i, j))
			{
				fil->i = i;
				fil->j = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}
