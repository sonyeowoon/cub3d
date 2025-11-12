/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:34:35 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/12 14:59:26 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static void	get_pwd(t_data *data, t_player *p, t_img *fb, int x)
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	double	delta_dist_x;
	double	delta_dist_y;

	int	step_x;
	int	step_y;
	double	side_dist_x;
	double	side_dist_y;
	int	map_x;
	int	map_y;

	int	hit = 0;
	int	side;

	double	perp_wall_dist;

	int		line_height;
	int		draw_start;
	int		draw_end;

	t_img	*tex;
	double	wall_x;
	int		tex_x;

	double	step;
	double	tex_pos;

	camera_x = 2 * x / (double)data->win_width - 1;
	ray_dir_x = p->dir_x + p->plane_x * camera_x;
	ray_dir_y = p->dir_y + p->plane_y * camera_x;

	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / ray_dir_y);

	map_x = (int)p->x;
	map_y = (int)p->y;
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (p->x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - p->x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (p->y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - p->y) * delta_dist_y;
	}

	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (data->map.map[map_y][map_x] == '1')
			hit = 1;
	}

	if (side == 0)
		perp_wall_dist = (map_x - p->x + (1 - step_x) / 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - p->y + (1 - step_y) / 2) / ray_dir_y;

	line_height = (int)(data->win_height / perp_wall_dist);
	draw_start = -line_height / 2 + data->win_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + data->win_height / 2;
	if (draw_end >= data->win_height)
		draw_end = data->win_height - 1;

	if (side == 0 && ray_dir_x > 0)
		tex = &data->asset.east.img;
	else if (side == 0 && ray_dir_x <= 0)
		tex = &data->asset.west.img;
	else if (side == 1 && ray_dir_y > 0)
		tex = &data->asset.south.img;
	else
		tex = &data->asset.north.img;

	if (side == 0)
		wall_x = p->y + perp_wall_dist * ray_dir_y;
	else
		wall_x = p->x + perp_wall_dist * ray_dir_x;
	wall_x -= floor(wall_x);

	tex_x = (int)(wall_x * (double)tex->w);
	if (side == 0 && ray_dir_x < 0)
		tex_x = tex->w - tex_x - 1;
	if (side == 1 && ray_dir_y > 0)
		tex_x = tex->w - tex_x - 1;
	
	step = (double)tex->h / (double)line_height;
	tex_pos = (draw_start - data->win_height / 2 + line_height / 2) * step;
	if (tex_pos < 0)
		tex_pos = 0;
	while (draw_start <= draw_end)
	{
		*(unsigned int *)(fb->addr + (draw_start * fb->line_len + x * (fb->bpp / 8))) = *(unsigned int *)(tex->addr + ((int)tex_pos) * tex->line_len + tex_x * (tex->bpp / 8));
		tex_pos += step;
		draw_start++;
	}
}
*/

static void	c_var_init(t_data *data, t_col *c, t_dda *dv, t_img **tex)
{
	c->line_height = (int)(data->win_height / dv->perp_wall_dist);
	c->draw_start = -(c->line_height) / 2 + data->win_height / 2;
	if (c->draw_start < 0)
		c->draw_start = 0;
	c->draw_end = c->line_height / 2 + data->win_height / 2;
	if (c->draw_end >= data->win_height)
		c->draw_end = data->win_height - 1;

	if (dv->side == 0 && dv->ray_dir_x > 0)
		*tex = &data->asset.east.img;
	else if (dv->side == 0 && dv->ray_dir_x <= 0)
		*tex = &data->asset.west.img;
	else if (dv->side == 1 && dv->ray_dir_y > 0)
		*tex = &data->asset.south.img;
	else
		*tex = &data->asset.north.img;
}

static void	c_var_init2(t_data *data, t_dda *dv, t_col *c, t_img *tex)
{
	t_player *p;

	p = &data->player;
	if (dv->side == 0)
		c->wall_x = p->y + dv->perp_wall_dist * dv->ray_dir_y;
	else
		c->wall_x = p->x + dv->perp_wall_dist * dv->ray_dir_x;
	c->wall_x -= floor(c->wall_x);

	c->tex_x = (int)(c->wall_x * (double)tex->w);
	if (dv->side == 0 && dv->ray_dir_x < 0)
		c->tex_x = tex->w - c->tex_x - 1;
	if (dv->side == 1 && dv->ray_dir_y > 0)
		c->tex_x = tex->w - c->tex_x - 1;
	
	c->step = (double)tex->h / (double)c->line_height;
	c->tex_pos = (c->draw_start - data->win_height / 2 + c->line_height / 2) * c->step;
	if (c->tex_pos < 0)
		c->tex_pos = 0;
}

static void	draw_col(t_data *data, t_dda *dv, t_col *c, int x)
{
	t_img	*tex;
	t_img	*fb;
	char *addr;
	char *color;
	t_player *p;

	p = &data->player;
	c_var_init(data, c, dv, &tex);
	c_var_init2(data, dv, c, tex);
	fb = &data->fb;
	while (c->draw_start <= c->draw_end)
	{
		addr = (fb->addr + (c->draw_start * fb->line_len + x * (fb->bpp / 8)));
		color = (tex->addr + ((int)c->tex_pos) * tex->line_len + c->tex_x * (tex->bpp / 8));
		/*
		*(unsigned int *)(fb->addr + (draw_start * fb->line_len + x * (fb->bpp / 8))) = *(unsigned int *)(tex->addr + ((int)tex_pos) * tex->line_len + tex_x * (tex->bpp / 8));
		*/
		*(unsigned int *)addr = *(unsigned int *)color;
		c->tex_pos += c->step;
		c->draw_start++;
	}
}

void	render_frame(t_data *data)
{
	int		x;
	//double	perp_wall_dist;
	t_dda	dda_vars;
	t_col	draw_vars;

	x = 0;
	while (x < data->win_width)
	{
		dda(data, &dda_vars, x);
		//get_pwd(data, p, &data->fb, x);
		draw_col(data, &dda_vars, &draw_vars, x);
		x++;
	}
}
