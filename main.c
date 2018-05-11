/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:36:20 by dpozinen          #+#    #+#             */
/*   Updated: 2018/04/23 17:36:21 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		skip_line(int fd, int amount)
{
	char	*line;
	int		i;

	i = 0;
	while (i < amount)
	{
		get_next_line(fd, &line);
		free(line);
		i++;
	}
	return (1);
}

int		get_player(void)
{
	char *line;
	char c;

	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
		c = 'O';
	else
		c = 'X';
	free(line);
	return (c);
}

int		main(void)
{
	t_filler	*fil;

	CHECK((fil = (t_filler*)malloc(sizeof(t_filler))));
	CHECK((fil->c = get_player()));
	while (execute(fil))
		ft_printf("%d %d\n", fil->i, fil->j);
	if (fil->c == 'O')
		write(2, "PLAYER ONE WON THE GAME\n", 24);
	else if (fil->c == 'X')
		write(2, "PLAYER TWO WON THE GAME\n", 24);
	free(fil);
	return (0);
}
