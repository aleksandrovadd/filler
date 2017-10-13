#include <unistd.h>
#include "filler.h"

int	define_player(char *pl)
{
	char	*str;
	int		i;

	i = 0;
	while (i++ <= 10)
	{
		get_next_line(0, &str);
		ft_printf("%s\n", str);
		if (ft_strstr(str, "p1 : [./filler]"))
			*pl = 'O';
		free(str);
	}
	if (*pl == 'O')
		return (1);
	else
		return (2);
}

void	colorize(char *line, int player)
{
	if (*line > 47 && *line < 57)
	{
		while (*line != '\0')
		{
			if (*line == 'X' || *line == 'x')
				if (player == 1)
					ft_printf("\033[1;33mX\033[0m");
				else
					ft_printf("\033[1;34mX\033[0m");
			else if (*line == 'O' || *line == 'o')
				if (player == 1)
					ft_printf("\033[1;34mO\033[0m");
				else
					ft_printf("\033[1;33mO\033[0m");
			else
				ft_printf("\033[1;36m%c\033[0m", *line);
			line++;
		}
		ft_printf("\n");
	}
	else
		ft_printf("\033[1;36m%s\033[0m\n", line);
}

int	main(void)
{
	char	*line;
	char	pl;
	int		player;

	player = define_player(&pl);
	while (get_next_line(0, &line))
	{
		colorize(line, player);
		free(line);
	}
	return (0);
}