/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:18:16 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 14:21:20 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_data *data)
{
	data->img.north = mlx_xpm_file_to_image(data->mlx, data->texture.north, 
		&(data->texture.no_tex_width), &(data->texture.no_tex_height));
	if (data->img.north == NULL)
		return (free_exit(data), treat_err("mlx img"), 1);
	data->img.south = mlx_xpm_file_to_image(data->mlx, data->texture.south, 
		&(data->texture.so_tex_width), &(data->texture.so_tex_height));
	if (data->img.south == NULL)
		return (free_exit(data), treat_err("mlx img"), 1);
	data->img.east = mlx_xpm_file_to_image(data->mlx, data->texture.east, 
		&(data->texture.ea_tex_width), &(data->texture.ea_tex_height));
	if (data->img.east == NULL)
		return (free_exit(data), treat_err("mlx img"), 1);
	data->img.west = mlx_xpm_file_to_image(data->mlx, data->texture.west, 
		&(data->texture.we_tex_width), &(data->texture.we_tex_height));
	if (data->img.west == NULL)
		return (free_exit(data), treat_err("mlx img"), 1);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_exit(data), treat_err("mlx"), 1);
	data->win = mlx_new_window(data->mlx, 480, 640, "Cub3D");
	if (!data->win)
		return (free_exit(data), treat_err("mlx"), 1);
}
