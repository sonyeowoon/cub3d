/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:35:09 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/12 16:44:09 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ddavars(t_data *data, t_player *p, t_dda *dv, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)data->win_width - 1;
	dv->ray_dir_x = p->dir_x + p->plane_x * camera_x;
	dv->ray_dir_y = p->dir_y + p->plane_y * camera_x;
	dv->delta_dist_x = fabs(1 / dv->ray_dir_x);
	dv->delta_dist_y = fabs(1 / dv->ray_dir_y);
	dv->map_x = (int)p->x;
	dv->map_y = (int)p->y;
}

static void	get_side_dist(t_dda *dv, t_player *p)
{
	if (dv->ray_dir_x < 0)
	{
		dv->step_x = -1;
		dv->side_dist_x = (p->x - dv->map_x) * dv->delta_dist_x;
	}
	else
	{
		dv->step_x = 1;
		dv->side_dist_x = (dv->map_x + 1.0 - p->x) * dv->delta_dist_x;
	}
	if (dv->ray_dir_y < 0)
	{
		dv->step_y = -1;
		dv->side_dist_y = (p->y - dv->map_y) * dv->delta_dist_y;
	}
	else
	{
		dv->step_y = 1;
		dv->side_dist_y = (dv->map_y + 1.0 - p->y) * dv->delta_dist_y;
	}
}

static double	get_pwd(t_map *map, t_dda *dv, t_player *p)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (dv->side_dist_x < dv->side_dist_y)
		{
			dv->side_dist_x += dv->delta_dist_x;
			dv->map_x += dv->step_x;
			dv->side = 0;
		}
		else
		{
			dv->side_dist_y += dv->delta_dist_y;
			dv->map_y += dv->step_y;
			dv->side = 1;
		}
		if (map->map[dv->map_y][dv->map_x] == '1')
			hit = 1;
	}
	if (dv->side == 0)
		return ((dv->map_x - p->x + (1 - dv->step_x) / 2) / dv->ray_dir_x);
	else
		return ((dv->map_y - p->y + (1 - dv->step_y) / 2) / dv->ray_dir_y);
	return (-1);
}

void	dda(t_data *data, t_dda *dv, int x)
{
	init_ddavars(data, &data->player, dv, x);
	get_side_dist(dv, &data->player);
	dv->perp_wall_dist = get_pwd(&data->map, dv, &data->player);
}
