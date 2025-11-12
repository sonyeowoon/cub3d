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
	t_player	*p;

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
	c->tex_pos = (c->draw_start - data->win_height / 2 + c->line_height / 2) * \
				c->step;
	if (c->tex_pos < 0)
		c->tex_pos = 0;
}

static void	draw_col(t_data *data, t_dda *dv, t_col *c, int x)
{
	t_img		*tex;
	t_img		*fb;
	char		*addr;
	char		*color;
	t_player	*p;

	p = &data->player;
	c_var_init(data, c, dv, &tex);
	c_var_init2(data, dv, c, tex);
	fb = &data->fb;
	while (c->draw_start <= c->draw_end)
	{
		addr = (fb->addr + (c->draw_start * fb->line_len + x * (fb->bpp / 8)));
		color = (tex->addr + ((int)c->tex_pos) * tex->line_len + c->tex_x * \
				(tex->bpp / 8));
		*(unsigned int *)addr = *(unsigned int *)color;
		c->tex_pos += c->step;
		c->draw_start++;
	}
}

void	render_frame(t_data *data)
{
	int		x;
	t_dda	dda_vars;
	t_col	draw_vars;

	x = 0;
	while (x < data->win_width)
	{
		dda(data, &dda_vars, x);
		draw_col(data, &dda_vars, &draw_vars, x);
		x++;
	}
}
