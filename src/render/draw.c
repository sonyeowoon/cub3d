/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:34:19 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/07 11:34:23 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	background(t_img *fb, int width, int height, t_assets *asset)
{
	int	y;
	int	x;
	int	half;

	half = height / 2;
	y = 0;
	x = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y < half)
				*(unsigned int *)(fb->addr + (y * fb->line_len + x * (fb->bpp / 8))) = asset->ceil_rgb;
			else
				*(unsigned int *)(fb->addr + (y * fb->line_len + x * (fb->bpp / 8))) = asset->floor_rgb;
			x++;
		}
		y++;
	}
}

void	draw(t_data *data)
{
	background(&data->fb, data->win_width, data->win_height, &data->asset);
	render_frame(data, &data->player);
	mlx_put_image_to_window(data->mlx, data->win, data->fb.img, 0, 0);
}
