/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:35:57 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/04 18:36:18 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_fig(t_game *game, t_coord *coord, int x, int y)
{
	int a;
	int b;
	int	i;
	int	sum;

	a = 0;
	i = 0;
	sum = 0;
	while (a < game->figure_height && (b = -1))
	{
		while (++b < game->figure_width)
		{
			if (game->figure[a][b] == '*' &&
			game->map[coord->my_x - x + a][coord->my_y - y + b] == game->player)
				i++;
			if (game->figure[a][b] == '*')
				sum += game->mass[coord->my_x - x + a][coord->my_y - y + b];
			if (game->figure[a][b] == '*' &&
			game->map[coord->my_x - x + a][coord->my_y - y + b] == game->enemy)
				return (-1);
		}
		a++;
	}
	return ((i != 1) ? -1 : sum);
}

int		check_map(t_game *game, t_coord *coord, int x, int y)
{
	if ((coord->my_x - x >= 0 && coord->my_y - y >= 0) &&
		(coord->my_x - x + game->figure_height <= game->map_height
		&& coord->my_y - y + game->figure_width <= game->map_width))
		return (1);
	return (0);
}

void	hrenka(t_coord *coord, int oh, int x, int y)
{
	coord->sum = oh;
	coord->fig_x = x;
	coord->fig_y = y;
}

int		check_figure(t_game *game, t_coord *coord)
{
	int x;
	int	y;
	int	oh;

	x = coord->fig_pos_x;
	coord->sum = -1;
	while (x < game->figure_height)
	{
		y = coord->fig_pos_y;
		while (y < game->figure_width)
		{
			if (check_map(game, coord, x, y))
			{
				oh = check_fig(game, coord, x, y);
				if (oh > 0 && (oh < coord->sum || coord->sum == -1))
					hrenka(coord, oh, x, y);
			}
			y++;
		}
		x++;
	}
	return (0);
}
