/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:44:21 by daleksan          #+#    #+#             */
/*   Updated: 2017/02/16 17:16:55 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_line(t_list *str, char *tmp, char **line)
{
	*tmp++ = '\0';
	*line = ft_strdup(str->content);
	tmp = ft_strdup(tmp);
	free(str->content);
	str->content = tmp;
	return (1);
}

static int		last_line(t_list *str, char *tmp, char **line)
{
	tmp = ft_strchr(str->content, '\0');
	if (tmp == str->content)
		return (0);
	else if (tmp != str->content)
	{
		tmp = ft_strnew(0);
		*line = ft_strdup(str->content);
		free(str->content);
		str->content = tmp;
		return (1);
	}
	return (0);
}

static t_list	*searching_lst(t_list **lst, size_t fd)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new->content = ft_strnew(0);
	new->content_size = fd;
	new->next = 0;
	ft_lstadd(lst, new);
	return (*lst);
}

static int		ft_reading(t_list *str)
{
	char	*bf;
	int		read_am;
	char	*tmp;
	char	*clone;

	bf = ft_strnew(BUFF_SIZE);
	read_am = 1;
	if (str->content)
		clone = ft_strdup(str->content);
	while ((read_am = read(str->content_size, bf, BUFF_SIZE)) > 0)
	{
		bf[read_am] = '\0';
		tmp = ft_strjoin(clone, bf);
		ft_strdel(&clone);
		clone = tmp;
		str->content = clone;
		if (ft_strchr(str->content, '\n'))
			break ;
	}
	ft_strdel(&bf);
	return (read_am);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*str;
	char			*tmp;
	int				num;

	if (read(fd, 0, 0) < 0 || fd == 1)
		return (-1);
	str = searching_lst(&lst, fd);
	num = ft_reading(str);
	if (num < 0)
		return (-1);
	else if ((tmp = ft_strchr(str->content, '\n')) != NULL)
		return (get_line(str, tmp, line));
	else if (tmp == NULL && num == 0)
		return (last_line(str, tmp, line));
	return (0);
}
