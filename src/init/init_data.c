/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:11:04 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 14:21:37 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_assets(t_assets *asset)
{
	init_texture(&asset->north);
	init_texture(&asset->south);
	init_texture(&asset->east);
	init_texture(&asset->west);
	asset->ceil_rgb = 0;
	asset->floor_rgb = 0;
	asset->has_ceiling = 0;
	asset->has_floor = 0;
}

static void	init_map(t_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->player_count = 0;
	map->map_start = 0;
}

static void	init_player(t_player *player)
{
	player->plane = PLANE;
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->move_spd = 0.05;
	player->rot_spd = 0.05;
}

static void	init_file(t_file *file)
{
	file->file = NULL;
	file->height = 0;
	file->width = 0;
	file->line_count = 0;
	file->read_count = 0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_file(&data->file);
	init_map(&data->map);
	init_img(&data->fb);
	init_player(&data->player);
	init_assets(&data->asset);
}
