/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:46:54 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/13 13:16:14 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_img(t_data *d, t_img *fb, t_assets *as)
{
	if (fb->img)
		mlx_destroy_image(d->mlx, fb->img);
	if (as->north.img.img)
		mlx_destroy_image(d->mlx, as->north.img.img);
	if (as->south.img.img)
		mlx_destroy_image(d->mlx, as->south.img.img);
	if (as->east.img.img)
		mlx_destroy_image(d->mlx, as->east.img.img);
	if (as->west.img.img)
		mlx_destroy_image(d->mlx, as->west.img.img);
}

void	game_exit(t_data *d)
{
	destroy_img(d, &d->fb, &d->asset);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	parse_free_data(d);
}
