/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:34:35 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/07 13:13:18 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_pwd(t_data *data, t_player *p, int x)
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int	map_x = int(p->x);
	int	map_y = int(p->y);

	double	delta_dist_x;
	double	delta_dist_y;

	camera_x = 2 * x / double(w) - 1;
	ray_dir_x = p->dir_x + p->plane_x * camera_x;
	ray_dir_y = p->dir_y + p->plane_y * camera_x;

	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / ray_dir_y);
}

void	render_frame(t_data *data, t_player *p)
{
	int		x;
	double	perp_wall_dist;
	//double	camera_x;
	//double	ray_dir_x;
	//double	ray_dir_y;

	x = 0;
	while (x < data->win_width)
	{
		perp_wall_dist = get_pwd(data, p, x);
		//camera_x = 2 * x / double(data->win_width) - 1;
		ray_dir_x = p->dir_x + p->plane_x * (2 * x / double(data->win_width) - 1);
		ray_dir_y = p->dir_y + p->plane_y * (2 * x / double(data->win_width) - 1);
		x++;
	}
}
