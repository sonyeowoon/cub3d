#include "cub3d.h"

static int is_block(t_data *data, double nx, double ny)
{
	int x=(int)nx;
	int y=(int)ny;
	if (x < 0 || y < 0 || x >= data->map.width || y >= data->map.height)
		return 1;
	return (data->map.map[y][x] == '1');
}


static void move_player(t_data *data)
{
	double ms = data->player.move_spd;
	double rs = data->player.rot_spd;
	// rotate
	if (data->keys[512])
	{
		double c = cos(+rs);
		double s = sin(+rs);
		double x = data->player.dir_x;
		double y = data->player.dir_y;
		data->player.dir_x = x * c - y * s;
		data->player.dir_y = x * s + y * c;
		x = data->player.plane_x;
		y = data->player.plane_y;
		data->player.plane_x = x * c - y * s;
		data->player.plane_y = x * s + y * c;
	}
	if (data->keys[513])
	{
		double c = cos(-rs);
		double s = sin(-rs);
		double x = data->player.dir_x;
		double y = data->player.dir_y;
		data->player.dir_x = x * c - y * s;
		data->player.dir_y = x * s + y * c;
		x = data->player.plane_x;
		y = data->player.plane_y;
		data->player.plane_x = x * c - y * s;
		data->player.plane_y = x * s + y * c;
	}
	// move
	double nx, ny;
	if (data->keys['w'])
	{
		nx = data->player.x + data->player.dir_x * ms;
		ny = data->player.y + data->player.dir_y * ms;
//		if(!is_block(data, nx, data->player.y))
		data->player.x = nx;
//		if(!is_block(data, data->player.x, ny))
		data->player.y = ny;
	}
	if (data->keys['s'])
	{
		nx = data->player.x - data->player.dir_x * ms;
		ny = data->player.y - data->player.dir_y * ms;
		if(!is_block(data, nx, data->player.y))
			data->player.x = nx;
		if(!is_block(data, data->player.x, ny))
			data->player.y = ny;
	}
	if (data->keys['a'])
	{
		nx = data->player.x - data->player.plane_x * ms;
		ny = data->player.y - data->player.plane_y * ms;
		if(!is_block(data, nx, data->player.y))
			data->player.x = nx;
		if(!is_block(data, data->player.x, ny))
			data->player.y = ny;
	}
	if (data->keys['d'])
	{
		nx = data->player.x + data->player.plane_x * ms;
		ny = data->player.y + data->player.plane_y * ms;
		if (!is_block(data, nx, data->player.y))
			data->player.x = nx;
		if (!is_block(data, data->player.x, ny))
			data->player.y = ny;
	}
}

int on_loop(t_data *data)
{
	if (!data->running)
		return 0;
	move_player(data);
	render_frame(data, &data->player);
	return 0;
}

int on_key_press(int kc, t_data *data)
{
	if(kc >= 0 && kc < 512)
		data->keys[kc] = 1;
	if (kc == 65361)
		data->keys[512] = 1;
	if (kc == 65363)
		data->keys[513] = 1;
	if (kc == 65307)
	{
		data->keys[514] = 1;
		on_close(data);
	}
	return 0;
}

int on_key_release(int kc, t_data *data)
{
	if(kc >= 0 && kc < 512)
		data->keys[kc] = 0;
	if (kc == 65361)
		data->keys[512] = 0;
	if (kc == 65363)
		data->keys[513] = 0;
	if (kc == 65307)
		data->keys[514] = 0;
	return 0;
}

int on_close(t_data *data)
{
	data->running=0;
	if(data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win=NULL;
	}
	return 0;
}
