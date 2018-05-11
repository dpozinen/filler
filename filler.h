/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:37:54 by dpozinen          #+#    #+#             */
/*   Updated: 2018/04/23 17:37:54 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft_complete/libft.h"
# include <limits.h>

# define CHECK(x) if (x <= 0) return (0);

typedef struct s_filler
{
	char	c;
	int		i;
	int		j;
	int		min;
	int		map_h;
	int		map_w;
	int		token_h;
	int		token_w;
	int		**token;
	int		**map;
	char	**char_map;
}t_filler;

int		execute(t_filler *fil);
int		**make_points(t_filler *fil);
int		*place_token(t_filler *fil);
int		skip_line(int fd, int amount);

#endif