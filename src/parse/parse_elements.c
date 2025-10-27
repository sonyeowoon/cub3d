/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:54:02 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 12:09:56 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_xpm_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (is_space(line[j]))
		j++;
	len = j;
	while (line[len] && !is_space(line[len]))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (perror("malloc"), NULL);
	i = 0;
	while (line[j] && !is_space(line[len]))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || (line[j] == '\t')))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	set_xpm_texture(t_texture *texture, char *line, int j)
{
	if (line[j + 2] && !is_space_ex_newline(line[j + 2]))
		return (1);
	if (line[j] == 'N' && line[j + 1] == 'O' && !texture->north)
		texture->north = get_xpm_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !texture->south)
		texture->south = get_xpm_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !texture->west)
		texture->west = get_xpm_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !texture->east)
		texture->east = get_xpm_path(line, j + 2);
	else
		return (1);
	return (0);
}

static int	get_texture(t_texture *texture, char **file, int i, int j)
{
	while (is_space(file[i][j]) == 1)
		j++;
	if (ft_isprint(file[i][j]) && !ft_isdigit(file[i][j]))
	{
		if (ft_isprint(file[i][j + 1]) && !ft_isdigit(file[i][j + 1]) && is_space_ex_newline(file[i][j + 2]))
		{
			if (set_xpm_texture(texture, file[i], j) != 0)
				return (treat_err("set xpm"), 1);
			return (-1);
		}
		else
		{
			if (set_color_rgb(texture, file[i], j) != 0)
				return (treat_err("set rgb"), 1);
			return (-1);
		}
	}
	else if (ft_isdigit(file[i][j]))
		return 2;
	return 0;
}

int	parse_header(t_file *file, t_texture *texture)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (file->file[i])
	{
		j = 0;
		while (file->file[i][j])
		{
			tmp = get_texture(texture, file->file, i, j);
			if (tmp == -1 || tmp == 2)
				break ;
			else if (tmp == 0)
				return (0);
			else if (tmp == 1)
				return (1);
			j++;
		}
		if (tmp == 2)
			break ;
		i++;
	}
	file->read_count = i;
	return (0);
}
