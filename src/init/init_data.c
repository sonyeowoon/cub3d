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

static void	init_texture(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->east = NULL;
	texture->west = NULL;
	texture->floor.r = 0;
	texture->floor.g = 0;
	texture->floor.b = 0;
	texture->ceiling.r = 0;
	texture->ceiling.g = 0;
	texture->ceiling.b = 0;
	texture->has_floor = 0;
	texture->has_ceiling = 0;
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
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}

static void	init_file(t_file *file)
{
	file->file = NULL;
	file->height = 0;
	file->width = 0;
	file->line_count = 0;
	file->read_count = 0;
}

static void	init_img(t_img *img)
{
	img->south = NULL;
	img->north = NULL;
	img->east = NULL;
	img->west = NULL;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_file(&data->file);
	init_map(&data->map);
	init_texture(&data->texture);
	init_img(&data->img);
	init_player(&data->player);
}
