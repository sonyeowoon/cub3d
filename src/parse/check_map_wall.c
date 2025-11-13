/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:15:03 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 14:40:57 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 공백이 맵 경계로 이어지는지 확인 (공백 flood fill)
static int	check_space_leak(t_map *map, char **visited, int y, int x)
{
	if (y < 0 || y >= map->height)
		return (1);
	if (x < 0 || !map->map[y])
		return (1);
	if (x >= (int)ft_strlen(map->map[y]))
		return (1);
	if (visited[y][x] == 'V' || map->map[y][x] == '1')
		return (0);
	if (!is_space_ex_newline(map->map[y][x]))
		return (0);
	visited[y][x] = 'V';
	if (check_space_leak(map, visited, y - 1, x))
		return (1);
	if (check_space_leak(map, visited, y + 1, x))
		return (1);
	if (check_space_leak(map, visited, y, x - 1))
		return (1);
	if (check_space_leak(map, visited, y, x + 1))
		return (1);
	return (0);
}

// 이동 가능한 공간 flood fill
static int	flood_fill_walkable(t_map *map, char **visited, int y, int x)
{
	char	c;

	if (y < 0 || y >= map->height || x < 0)
		return (1);
	if (!map->map[y] || x >= (int)ft_strlen(map->map[y]))
		return (1);
	c = map->map[y][x];
	if (visited[y][x] == 'V' || c == '1')
		return (0);
	if (is_space_ex_newline(c))
		return (check_space_leak(map, visited, y, x));
	visited[y][x] = 'V';
	if (flood_fill_walkable(map, visited, y - 1, x))
		return (1);
	if (flood_fill_walkable(map, visited, y + 1, x))
		return (1);
	if (flood_fill_walkable(map, visited, y, x - 1))
		return (1);
	if (flood_fill_walkable(map, visited, y, x + 1))
		return (1);
	return (0);
}

static char	**create_visited_map(t_map *map)
{
	char	**visited;
	int		i;
	int		j;

	visited = malloc(sizeof(char *) * map->height);
	if (!visited)
		return (treat_err(strerror(errno)), NULL);
	i = -1;
	while (++i < map->height)
	{
		visited[i] = malloc(sizeof(char) * (ft_strlen(map->map[i]) + 1));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (treat_err(strerror(errno)), NULL);
		}
		j = -1;
		while (map->map[i][++j])
			visited[i][j] = '0';
		visited[i][j] = '\0';
	}
	return (visited);
}

static void	free_visited_map(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	check_map_wall(t_map *map)
{
	char	**visited;
	int		i;
	int		j;
	int		result;

	visited = create_visited_map(map);
	if (!visited)
		return (1);
	result = 0;
	i = -1;
	while (++i < map->height && result == 0)
	{
		j = -1;
		while (map->map[i][++j] && result == 0)
		{
			if (visited[i][j] != 'V' &&
				(map->map[i][j] == '0' || map->map[i][j] == 'N'
				|| map->map[i][j] == 'S' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'W'))
				result = flood_fill_walkable(map, visited, i, j);
		}
	}
	free_visited_map(visited, map->height);
	return (result);
}
