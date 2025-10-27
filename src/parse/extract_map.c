/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 04:06:19 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 13:51:57 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_height(char **file, int read_count)
{
	int	i;
	int	j;
	int	height;

	i = read_count;
	height = 0;
	while (file[i])
	{
		j = 0;
		while ((file[i][j] >= 9 && file[i][j] <= 13) || file[i][j] == ' ')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
		height++;
	}
	return (height);
}

static int	get_map_width(char **file, int read_count)
{
	int	width;
	int	len;
	
	width = ft_strlen(file[read_count]);
	while (file[read_count])
	{
		len = ft_strlen(file[read_count]);
		if (len > width)
			width = len;
		read_count++;
	}
	return (width);
}

static int	set_map(t_file *file, t_map *map, char **maps, int rc)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		maps[i] = malloc(sizeof(char) * (file->width + 1));
		if (!maps[i])
			return (perror("malloc"), 1);
		while (file->file[rc][j] && file->file[rc][j] != '\n')
		{
			maps[i][j] = file->file[rc][j];
			j++;
		}
		while (j < file->width)
			maps[i][j++] = ' ';
		maps[i][j] = '\0';
		i++;
		rc++;
	}
	maps[i] = NULL;
	return (0);
}

int	extract_map(t_file *file, t_map *map)
{
	map->height = get_map_height(file->file, file->read_count);
	map->width = get_map_width(file->file, file->read_count);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (perror("malloc"), 1);
	if (set_map(file, map, map->map, file->read_count) != 0)
		return (1);
	return (0);	
}
