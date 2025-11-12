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

static void	get_img_data(t_assets *asset)
{
	t_img	*dir;

	dir = &asset->north.img;
	dir->addr = mlx_get_data_addr(dir->img, &dir->bpp, &dir->line_len, \
			&dir->endian);
	dir = &asset->south.img;
	dir->addr = mlx_get_data_addr(dir->img, &dir->bpp, &dir->line_len, \
			&dir->endian);
	dir = &asset->east.img;
	dir->addr = mlx_get_data_addr(dir->img, &dir->bpp, &dir->line_len, \
			&dir->endian);
	dir = &asset->west.img;
	dir->addr = mlx_get_data_addr(dir->img, &dir->bpp, &dir->line_len, \
			&dir->endian);
}

void	init_tex_img(t_data *data, t_assets *asset)
{
	t_img	*dir;

	dir = &asset->north.img;
	dir->img = mlx_xpm_file_to_image(data->mlx, asset->north.path, \
			&dir->w, &dir->h);
	if (dir->img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
	dir = &asset->south.img;
	dir->img = mlx_xpm_file_to_image(data->mlx, asset->south.path, \
			&dir->w, &dir->h);
	if (dir->img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
	dir = &asset->east.img;
	dir->img = mlx_xpm_file_to_image(data->mlx, asset->east.path, \
			&dir->w, &dir->h);
	if (dir->img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
	dir = &asset->west.img;
	dir->img = mlx_xpm_file_to_image(data->mlx, asset->west.path, \
			&dir->w, &dir->h);
	if (asset->west.img.img == NULL)
		return ;
		//return (free_exit(data), treat_err("mlx img"), 1);
	get_img_data(asset);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
		//return (free_exit(data), treat_err("mlx"), 1);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, \
			"Cub3D");
	if (!data->win)
		return ;
		//return (free_exit(data), treat_err("mlx"), 1);
}
