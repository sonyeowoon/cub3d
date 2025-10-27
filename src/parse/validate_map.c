/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 05:15:46 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 13:55:53 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_pos_valid(t_data *data, char **map)
{
	int	y;
	int	x;

	y = (int)data->player.pos_y;
	x = (int)data->player.pos_x;
	if (ft_strlen(map[y - 1]) < (size_t)x
		|| ft_strlen(map[y + 1]) < (size_t)x
		|| is_space2(map[y][x - 1]) != 0
		|| is_space2(map[y][x + 1]) != 0
		|| is_space2(map[y - 1][x]) != 0
		|| is_space2(map[y + 1][x]) != 0)
		return (1);
	return (0);
}

static int	check_player(t_data *data, char **map)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				data->player.pos_x = (double)j + 0.3;
				data->player.pos_y = (double)i + 0.3;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_pos_valid(data, map) != 0)
		return (1);
	return (0);
}

static int	check_map_elements(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			while ((map[i][j] >= 9 && map[i][j] <= 13) || map[i][j] == 32)
				j++;
			if (map[i][j] == '\0')
				break ;
			if (!(ft_strchr("NSEW10", map[i][j])) && !is_space_ex_newline(map[i][j]))
				return (1);
			if (ft_strchr("NSEW", map[i][j]) && data->player.dir != '0')
				return (1);
			if (ft_strchr("NSEW", map[i][j]) && data->player.dir == '0')
				data->player.dir = map[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_file_not_end(t_file *file, t_map *map)
{
	int	len;

	len = file->read_count + map->height;
	if (!file->file[len])
		return (0);
	return (1);
}

int	validate_map(t_data *data, t_map *map)
{
	if (!map)
		return (treat_err("map parsing err"), 1);
	if (check_map_elements(data, map->map) != 0)
		return (treat_err("map elements err"), 1);
	if (check_map_wall(map) != 0)
		return (treat_err("no wall"), 1);
	if (map->height < 3)
		return (treat_err("small map"), 1);
	if (check_player(data, map->map) != 0)
		return (treat_err("player err"), 1);
	if (check_file_not_end(&data->file, map) != 0)
		return (treat_err("file err"), 1);
	return (0);
}

