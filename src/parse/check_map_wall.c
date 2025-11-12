/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 07:11:32 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 13:54:29 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_top_or_bottom(char **map, int i, int j, int width)
{
	if (!map || !map[i] || !map[i][j])
		return (1);
	while (map[i][j] == ' ' || map[i][j] == '\t'
	|| map[i][j] == '\r' || map[i][j] == '\v'
	|| map[i][j] == '\f')
		j++;
	while (j < width && map[i][j])
	{
		if (map[i][j] == '\0')
			return (0);
		if (map[i][j] != '1' && !is_space_ex_newline(map[i][j]))
			return (1);
		else
			j++;
	}
	return (0);
}

static int	check_side_wall(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (is_space_ex_newline(line[i]))
		i++;
	if (line[i] != '1')
		return (1);
	j = ft_strlen(line) - 1;
	while (j >= i && is_space_ex_newline(line[j]))
		j--;
	if (line[j] != '1')
		return (1);
	return (0);
}

int	check_map_wall(t_map *map)
{
	int	i;

	if (check_top_or_bottom(map->map, 0, 0, map->width) != 0)
		return (1);
	i = 1;
	while (i < (map->height - 1))
	{
		if (check_side_wall(map->map[i]) != 0)
			return (1);
		i++;
	}
	if (check_top_or_bottom(map->map, i, 0, map->width) != 0)
		return (1);
	return (0);
}
