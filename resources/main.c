/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student@42 <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 22:10:06 by student@42        #+#    #+#             */
/*   Updated: 2013/12/03 13:35:51 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "get_next_line.h"

int	get_next_line(int fd, char **line);

int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	pid_t	child;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open("me.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		close(fd2);
		return (-1);
	}
	// while (get_next_line(fd, &line) == 1)
	// {
	// 	printf("%d\n", get_next_line(fd, &line));
	// 	printf("%s\n", line);
	// 	//write(fd2, line, strlen(line));
	// 	//write(fd2, &n, 1);					// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
	// 	free(line);							// vous inquietez pas
	// }
	dprintf(2, "%d\n", get_next_line(fd, &line));
	dprintf(2, "%s\n", line);
	dprintf(2, "%d\n", get_next_line(fd, &line));
	dprintf(2, "%s\n", line);
	dprintf(2, "%d\n", get_next_line(fd, &line));
	dprintf(2, "%s\n", line);
	dprintf(2, "%d\n", get_next_line(fd, &line));
	dprintf(2, "%s\n", line);
	// printf("%d\n", get_next_line(fd, &line));
	// printf("%s\n", line);
	// printf("%d\n", get_next_line(fd, &line));
	// printf("%s\n", line);
	// printf("%d\n", get_next_line(fd, &line));
	// printf("%s\n", line);
	close(fd);
	close(fd2);
	printf("%d\n", get_next_line(fd, &line));

	// child = fork();
	// if (child == 0)
	// {
	// 	char	*arg[] = {"/usr/bin/diff", NULL, "me.txt", NULL};

	// 	arg[1] = argv[1];
	// 	execve(arg[0], arg, NULL);
	// 	exit(0);
	// }
	// else
	// 	wait(NULL); // bad code I know ... but it's not the project*/
	// (void)argc;
	// (void)argv;
	return (0);
}
