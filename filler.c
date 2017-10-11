/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:29:57 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/04 19:03:18 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game	*plateau_create(t_game *game, char *line)
{
	int	size;

	game = parse_data(game, line);
	free(line);
	get_next_line(0, &line);
	free(line);
	game->map = (char**)malloc(sizeof(char *) * game->map_height);
	size = 0;
	while (size < game->map_height && get_next_line(0, &line) > 0)
	{
		game->map[size] = ft_strdup(line + 4);
		size++;
		free(line);
	}
	return (game);
}

t_game	*piece_create(t_game *game, char *line)
{
	int	size;

	size = 0;
	game = parse_data_2(game, line);
	free(line);
	game->figure = (char**)malloc(sizeof(char *) * game->figure_height);
	while (size < game->figure_height && get_next_line(0, &line) > 0)
	{
		game->figure[size] = ft_strdup(line);
		size++;
		free(line);
	}
	return (game);
}

void	mass_create(t_game *game, t_coord *coord)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strncmp("Plateau", line, 7) == 0)
			game = plateau_create(game, line);
		if (ft_strncmp("Piece", line, 5) == 0)
		{
			game = piece_create(game, line);
			break ;
		}
	}
	map_int_create(game);
	enemy_coord(game, coord);
	figure_coord(game, coord);
	my_coord(game, coord);
}

int		main(void)
{
	char	*line;
	t_game	*game;
	t_coord	*coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	game = (t_game *)malloc(sizeof(t_game));
	get_next_line(0, &line);
	player_def(line, game);
	ft_strdel(&line);
	mass_create(game, coord);
	while (get_next_line(0, &line))
	{
		if (ft_strncmp("Plateau", line, 7) == 0)
			game = plateau_renew(game, line);
		if (ft_strncmp("Piece", line, 5) == 0)
		{
			game = piece_create(game, line);
			enemy_coord(game, coord);
			figure_coord(game, coord);
			my_coord(game, coord);
		}
	}
	return (0);
}
