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
	int	img_x;
	int	img_y;
	
	data->asset.north.img.img = mlx_xpm_file_to_image(data->mlx, data->asset.north.path, &img_x, &img_y);
	if (data->asset.north.img.img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
	data->asset.south.img.img = mlx_xpm_file_to_image(data->mlx, data->asset.south.path, &img_x, &img_y);
	if (data->asset.south.img.img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
	data->asset.east.img.img = mlx_xpm_file_to_image(data->mlx, data->asset.east.path, &img_x, &img_y);
	if (data->asset.east.img.img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
	data->asset.west.img.img = mlx_xpm_file_to_image(data->mlx, data->asset.west.path, &img_x, &img_y);
	if (data->asset.west.img.img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
		//return (free_exit(data), treat_err("mlx"), 1);
	data->win = mlx_new_window(data->mlx, 480, 640, "Cub3D");
	if (!data->win)
		return ;
		//return (free_exit(data), treat_err("mlx"), 1);
}
