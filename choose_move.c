/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:54:57 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/04 18:56:39 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		map_int_create(t_game *game)
{
	int	x;
	int	y;

	game->mass = (int **)malloc(sizeof(int *) * game->map_height);
	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		game->mass[x] = (int *)malloc(sizeof(int) * game->map_width);
		while (y < game->map_width)
		{
			game->mass[x][y] = -1;
			y++;
		}
		x++;
	}
	return (0);
}

int		map_int_change(t_game *game, t_coord *coord)
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int t;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			x1 = (x - coord->en_x > 0) ? x - coord->en_x : coord->en_x - x;
			y1 = (y - coord->en_y > 0) ? y - coord->en_y : coord->en_y - y;
			t = (x1 > y1) ? x1 : y1;
			if (game->mass[x][y] > t || game->mass[x][y] == -1)
				game->mass[x][y] = t;
			y++;
		}
		x++;
	}
	return (0);
}

void	enemy_coord(t_game *game, t_coord *coord)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == game->enemy && game->mass[x][y] != 0)
			{
				coord->en_x = x;
				coord->en_y = y;
				map_int_change(game, coord);
			}
			y++;
		}
		x++;
	}
}

void	my_coord(t_game *game, t_coord *coord)
{
	int	x;
	int	y;
	int	ph;

	x = 0;
	ph = -1;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == game->player && (check_map_fig(game, x, y) == 1))
			{
				coord->my_x = x;
				coord->my_y = y;
				check_figure(game, coord);
				if (coord->sum > 0 && (coord->sum < ph || ph == -1))
				{
					ph = coord->sum;
					coord->en_x = x - coord->fig_x;
					coord->en_y = y - coord->fig_y;
				}
			}
			y++;
		}
		x++;
	}
	ft_printf("%d %d\n", coord->en_x, coord->en_y);
}
