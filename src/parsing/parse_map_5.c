/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Verdoodt <Verdoodt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:18:03 by devoma            #+#    #+#             */
/*   Updated: 2023/05/19 13:16:40 by Verdoodt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_line_f_c_2(char *line)
{
	char	*temp;
	char	**matrix;

	temp = ft_substr(line, 1, ft_strlen(line));
	free(line);
	matrix = ft_split(temp, ',');
	if (check_line_f_c_3(temp, matrix) == 0)
		return (0);
	free(temp);
	free_map(matrix);
	return (1);
}

int	check_line_f_c_3(char *temp, char **matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != '\n' && (matrix[i][j] < 48 || matrix[i][j] > 57
				|| ft_atoi(matrix[i]) < 0 || ft_atoi(matrix[i]) > 255))
			{
				free(temp);
				free_map(matrix);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_id_3(char *map_line, int j)
{
	char	*new_line;

	new_line = create_line(map_line, j);
	if (!new_line || check_line_f_c(new_line) == 0)
	{
		free(new_line);
		return (0);
	}
	if (check_line_f_c(new_line) == 1 && map_line[j] == 'F')
	{
		free(new_line);
		return (1);
	}
	if (check_line_f_c(new_line) == 1 && map_line[j] == 'C')
	{
		free(new_line);
		return (2);
	}
	free(new_line);
	return (0);
}

int	skip_empty_lines(char **map, int n)
{
	int	i;

	n++;
	i = n;
	while (map[i])
	{
		if (map[i][0] == '\n')
			i++;
		else
			break ;
	}
	return (i);
}
