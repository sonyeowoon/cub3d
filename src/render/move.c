/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:46:50 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/11 19:47:32 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_block(t_data *data, double nx, double ny)
{
	int	x;
	int	y;

	x = (int)nx;
	y = (int)ny;
	if (x < 0 || y < 0 || x >= data->map.width || y >= data->map.height)
		return (1);
	return (data->map.map[y][x] == '1');
}

void	move_player(t_data *d, t_player *pl, int kc)
{
	double		mv_x;
	double		mv_y;
	double		ngtv;
	t_vector	nxny;

	ngtv = 1;
	if (ft_strchr("sa", kc))
		ngtv = -1;
	if (ft_strchr("ws", kc))
	{
		mv_x = pl->dir_x;
		mv_y = pl->dir_y;
	}
	else
	{
		mv_x = pl->plane_x;
		mv_y = pl->plane_y;
	}
	nxny.x = pl->x + mv_x * ngtv * pl->move_spd;
	nxny.y = pl->y + mv_y * ngtv * pl->move_spd;
	if (!is_block(d, nxny.x, pl->y))
		pl->x = nxny.x;
	if (!is_block(d, pl->x, nxny.y))
		pl->y = nxny.y;
}

void	rotate_player(t_player *p, int kc)
{
	double	theta;

	if (kc == 65361)
		theta = -(p->rot_spd);
	else
		theta = p->rot_spd;
	p->dir_x = p->dir_x * cos(theta) - p->dir_y * sin(theta);
	p->dir_y = p->dir_x * sin(theta) + p->dir_y * cos(theta);
	p->plane_x = p->plane_x * cos(theta) - p->plane_y * sin(theta);
	p->plane_y = p->plane_x * sin(theta) + p->plane_y * cos(theta);
}
