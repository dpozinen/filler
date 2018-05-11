/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:43:25 by dpozinen          #+#    #+#             */
/*   Updated: 2018/04/23 17:43:26 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		*make_lint(char *line, int f, int size, char c)
{
	int *ret;
	int l;
	int i;

	i = (f == 1) ? 4 : 0;
	l = 0;
	CHECK((ret = (int*)malloc(sizeof(int) * size)));
	while (line[i] && l < size)
	{
		if (f == 0 && line[i] == '*')
			ret[l] = -2;
		else if (line[i] == '.' || line[i] == c)
			ret[l] = 0;
		else
			ret[l] = 1;
		i++;
		l++;
	}
	return (ret);
}

char	**read_strarr(int length)
{
	char	**strarr;
	int		i;

	strarr = (char**)malloc(sizeof(char*) * (length + 1));
	CHECK(strarr);
	i = 0;
	while (i < length)
	{
		get_next_line(0, &strarr[i]);
		strarr[i] = string_to_upper(strarr[i]);
		if (!strarr[i])
		{
			free_char_array(strarr, i);
			return (0);
		}
		i++;
	}
	strarr[length] = 0;
	return (strarr);
}

int		**get_array(t_filler *fil, int f)
{
	int		**ret;
	int		i;
	int		h;
	int		w;
	char	**map;

	h = (f == 1) ? fil->map_h : fil->token_h;
	w = (f == 1) ? fil->map_w : fil->token_w;
	f == 1 ? skip_line(0, 1) : 0;
	CHECK((ret = (int**)malloc(sizeof(int*) * h)));
	i = 0;
	CHECK((map = read_strarr(h)));
	f == 1 ? fil->char_map = map : 0;
	while (i < h)
	{
		CHECK((ret[i] = make_lint(map[i], f, w, fil->c)));
		i++;
	}
	return (ret);
}

int		get_size(t_filler *fil, int f)
{
	int		i;
	char	*line;
	int		*s;

	i = 0;
	CHECK((get_next_line(0, &line)));
	while (!ft_isdigit(line[i]))
		i++;
	s = (f == 1) ? &(fil->map_h) : &(fil->token_h);
	*s = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	s = (f == 1) ? &(fil->map_w) : &(fil->token_w);
	*s = ft_atoi(line + i);
	free(line);
	if (*s != 0)
		return (1);
	return (0);
}

int		execute(t_filler *fil)
{
	if (!get_size(fil, 1))
		return (0);
	fil->map = get_array(fil, 1);
	get_size(fil, 0);
	fil->token = get_array(fil, 0);
	make_points(fil);
	fil->i = -1;
	fil->j = -1;
	place_token(fil);
	return (1);
}
