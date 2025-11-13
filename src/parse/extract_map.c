/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 04:06:19 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 14:38:01 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			return (treat_err(strerror(errno)), 1);
		while (file->file[rc][j])
		{
			if (file->file[rc][j] == '\t')
				return (treat_err("\\t exists"), 1);
			maps[i][j] = file->file[rc][j];
			j++;
		}
		maps[i][j] = '\0';
		i++;
		rc++;
	}
	maps[i] = NULL;
	return (0);
}

int	extract_map(t_file *file, t_map *map)
{
	map->height = file->height - file->read_count;
	map->width = get_map_width(file->file, file->read_count);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (treat_err(strerror(errno)), 1);
	if (set_map(file, map, map->map, file->read_count) != 0)
		return (1);
	return (0);
}
