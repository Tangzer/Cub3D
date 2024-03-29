/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:16:45 by devoma            #+#    #+#             */
/*   Updated: 2023/05/27 12:00:10 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*gnl_loop(int fd, char *static_line)
{
	char		buf[101];
	int			for_read;
	static char	*temp;

	while (1)
	{
		for_read = read(fd, buf, 100);
		buf[for_read] = '\0';
		if (for_read == -1)
			return (NULL);
		if (!static_line)
			static_line = ft_strdup(buf);
		else
		{
			temp = static_line;
			static_line = ft_strjoin(temp, buf);
			free(temp);
		}
		if (ft_strchr(buf, '\n') || for_read == 0)
			break ;
	}
	return (static_line);
}

char	*get_next_line(int fd)
{
	int			index_n;
	char		*result;
	static char	*static_line;
	char		*temp;
	int			second_part;

	static_line = gnl_loop(fd, static_line);
	second_part = ft_strlen(ft_strchr(static_line, '\n'));
	index_n = ft_strlen(static_line) - second_part + 1;
	result = ft_substr(static_line, 0, index_n);
	temp = static_line;
	static_line = ft_substr(static_line, index_n, ft_strlen(static_line));
	free(temp);
	return (result);
}

char	**reading_file(int fd, int line_count, char **map)
{
	int		i;
	char	*line;

	i = 0;
	map = malloc(sizeof(char *) * line_count);
	protect_malloc(map);
	while (1)
	{
		line = get_next_line(fd);
		if (!ft_strlen(line))
		{
			map[i] = NULL;
			free(line);
			break ;
		}
		map[i] = no_tab(line);
		i++;
		map[i] = NULL;
		free(line);
	}
	return (map);
}

int	reading_lines(int fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!ft_strlen(line))
		{
			free(line);
			break ;
		}
		line_count++;
		free(line);
	}
	return (line_count);
}

int	is_empty_str(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
