/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:03:49 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/04 19:05:08 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		player_def(char *line, t_game *game)
{
	game->player = ' ';
	game->enemy = ' ';
	if (line[10] == '1')
	{
		game->player = 'O';
		game->enemy = 'X';
	}
	else
	{
		game->player = 'X';
		game->enemy = 'O';
	}
}

t_game		*parse_data(t_game *game, char *line)
{
	char	*str;

	str = ft_strdup(line);
	str = ft_strchr(str, ' ');
	str++;
	game->map_height = ft_atoi(str);
	str = ft_strchr(str, ' ');
	game->map_width = ft_atoi(str);
	return (game);
}

t_game		*parse_data_2(t_game *game, char *line)
{
	char	*str;

	str = ft_strdup(line);
	str = ft_strchr(str, ' ');
	str++;
	game->figure_height = ft_atoi(str);
	str = ft_strchr(str, ' ');
	game->figure_width = ft_atoi(str);
	return (game);
}

t_game		*plateau_renew(t_game *game, char *line)
{
	int		size;

	get_next_line(0, &line);
	free(line);
	size = 0;
	while (size < game->map_height && get_next_line(0, &line) > 0)
	{
		game->map[size] = ft_strcpy(game->map[size], line + 4);
		size++;
		free(line);
	}
	return (game);
}
