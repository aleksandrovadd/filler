/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:05:54 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/04 19:08:54 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include "ft_printf/src/ft_printf.h"

typedef struct	s_coord
{
	int			my_x;	// текущая позиция на карте
	int			my_y;

	int			en_x; 	// позиция врага на крте (для int массива)
	int			en_y;

	int			fig_x;  // ответ
	int			fig_y;

	int 		fig_pos_x;	//	найденная n-звездочка на фигуре
	int 		fig_pos_y;
	int 		i;			//	 количество звезд
	int 		fig_x_0;
	int 		fig_y_0;

	int			sum;
}				t_coord;

typedef struct	s_game
{
	char		player;
	char		enemy;

	char		**map;
	int			map_height;
	int			map_width;

	char		**figure;
	int			figure_height;
	int			figure_width;

	int			**mass;
	int 		ph;
}				t_game;

int				main(void);
t_game			*piece_create(t_game *game, char *line);
t_game			*plateau_create(t_game *game, char *line);
t_game			*parse_data(t_game *game, char *line);
t_game			*parse_data_2(t_game *game, char *line);
t_game			*plateau_renew(t_game *game, char *line);
void			player_def(char *line, t_game *game);
void			my_coord(t_game *game, t_coord *coord);
void			enemy_coord(t_game *game, t_coord *coord);
void			figure_coord(t_game *game, t_coord *coord);
void			mass_create(t_game *game, t_coord *coord);
int				check_figure(t_game *game, t_coord *coord);
int				check_map(t_game *game, t_coord *coord, int x, int y);
int				check_map_fig(t_game *game, int x, int y);
int				check_fig(t_game *game, t_coord *coord, int x, int y);
int				map_int_create(t_game *game);
int				map_int_change(t_game *game, t_coord *coord);

#endif
