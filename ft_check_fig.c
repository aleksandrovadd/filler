/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:06:28 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/11 15:07:24 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_map_fig(t_game *game, int x, int y)
{
	int i;

	i = 0;
	if (x < game->map_height - 1 && game->map[x + 1][y] == game->player)
		i++;
	if (x > 0 && game->map[x - 1][y] == game->player)
		i++;
	if (y < game->map_width - 1 && game->map[x][y + 1] == game->player)
		i++;
	if (y > 0 && game->map[x][y - 1] == game->player)
		i++;
	if (x < game->map_height - 1 && y < game->map_width - 1 &&
		game->map[x + 1][y + 1] == game->player)
		i++;
	if (x > 0 && y > 0 && game->map[x - 1][y - 1] == game->player)
		i++;
	if (x < game->map_height - 1 && y > 0 &&
		game->map[x + 1][y - 1] == game->player)
		i++;
	if (y < game->map_width - 1 && x > 0 &&
		game->map[x - 1][y + 1] == game->player)
		i++;
	if (i == 8)
		return (0);
	return (1);
}

void	figure_coord(t_game *game, t_coord *coord)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->figure_height)
	{
		y = 0;
		while (y < game->figure_width)
		{
			if (game->figure[x][y] == '*')
			{
				coord->fig_pos_x = x;
				coord->fig_pos_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
